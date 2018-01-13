//
// Created by bush on 13/01/18.
//

#include "utils_gf2n.h"

void init_gf2x(GF2X& irred, long deg) {
    BuildIrred(irred, deg);
    GF2E::init(irred);
}


void print_poly (GF2X& P) {
    long degree = deg(P);
    if (-1 == degree) {
        cout << "0";
        return;
    }
    for(long i=0; i<=degree; i++) {
        cout << coeff(P, i);
        if (i==1)
            cout << "X";
        else if(i>1)
            cout << "X^" << i;
        if (i<degree) {
            cout << " + ";
        }
    }
//    cout << endl << "random poly:" << endl << P << endl;
}

#define LEFT(X) (2*X+1)
#define RIGHT(X) (2*X+2)

void build_tree (GF2EX* tree, GF2E* points, unsigned int root, unsigned int tree_size) {
    // halting condition
    if(LEFT(root)>=tree_size) {
        unsigned int point_index = root-(tree_size-1)/2;
        //setting the polynomial to be x-m where m is points[point_index]
        GF2E negated;
        NTL::negate(negated, points[point_index]);
        SetCoeff(tree[root], 0, negated);
        SetCoeff(tree[root], 1, 1);
//        cout << endl << "polynomial at index " << root << ":" << endl;
//        cout << tree[root] << endl;
        return;
    }

    build_tree(tree, points, LEFT(root), tree_size);
    build_tree(tree, points, RIGHT(root), tree_size);
    tree[root] = tree[LEFT(root)]*tree[RIGHT(root)];
//    cout << endl << "polynomial at index " << root << ":" << endl;
//    cout << tree[root] << endl;
}




void test_tree (GF2EX& final_polynomial, GF2E* points, unsigned int npoints){
//    cout << "final polynomial: " << endl << final_polynomial << endl;
    GF2E result;
    bool error = false;
    for (unsigned int i=0; i<npoints; i++) {
        result = eval(final_polynomial, points[i]);
//        cout << "evaluating on " << points[i] << ": " << result << endl;
        if (0!=result) {
            cout << "FATAL ERROR: polynomials tree is incorrect!" << endl;
            error = true;
            break;
        }
    }
    if (!error)
        cout << "polynomials tree is correct." << endl;
}


void evaluate (GF2EX& P, GF2EX* tree, unsigned int root, unsigned int tree_size, GF2E* results) {
    // halting condition
    if(LEFT(root)>=tree_size) {
        GF2EX R = P%tree[root];
//        cout << "leaf: " << root << endl << R << endl;
        if(deg(R)>0)
            cout << "ERROR: R should be constant...";
        unsigned int result_index = root-(tree_size-1)/2;
        results[result_index] = coeff(R, 0);
        return;
    }

    GF2EX R = P%tree[root];
    evaluate(R, tree, LEFT(root), tree_size, results);
    evaluate(R, tree, RIGHT(root), tree_size, results);
}


void test_evaluate(GF2EX& P, GF2E* points, GF2E* results, unsigned int npoints) {
    bool error = false;
    for (unsigned int i = 0; i < npoints; i++) {
        GF2E y = eval(P, points[i]);
        if (y != results[i]) {
            cout << "y=" << y << " and results[i]=" << results[i] << endl;
            error = true;
        }
    }
    if (error)
        cout << "ERROR: evaluation results do not match real evaluation!" << endl;
    else
        cout << "All evaluation results computed correctly!" << endl;
}