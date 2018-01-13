//
// Created by bush on 12/01/18.
//

#include "utils_zp.h"


void print_poly (ZZ_pX& P){//}, int degree) {
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

/* A recursive function to build the tree of polynomials
 * (assumming a complete binary tree => size = 2*#leafs-1
 'tree_size' is the number of nodes (including leaves) in the tree
 'root' is the index of the subtree in the array 'tree'
 */
#define LEFT(X) (2*X+1)
#define RIGHT(X) (2*X+2)

void build_tree (ZZ_pX* tree, ZZ_p* points, unsigned int root, unsigned int tree_size) {
    // halting condition
    if(LEFT(root)>=tree_size) {
        unsigned int point_index = root-(tree_size-1)/2;
        //setting the polynomial to be x-m where m is points[point_index]
        ZZ_p negated;
        NTL::negate(negated, points[point_index]);
        SetCoeff(tree[root], 0, negated);
        SetCoeff(tree[root], 1, 1);
//        cout << endl << "polynomial at index " << root << ":" << endl;
//        print_poly(tree[root]);
//        cout << endl;
        return;
    }

    build_tree(tree, points, LEFT(root), tree_size);
    build_tree(tree, points, RIGHT(root), tree_size);
    tree[root] = tree[LEFT(root)]*tree[RIGHT(root)];
//    cout << endl << "polynomial at index " << root << ":" << endl;
//    print_poly(tree[root]);
//    cout << endl;
}

void test_tree (ZZ_pX& final_polynomial, ZZ_p* points, unsigned int npoints) {
//    cout << "final polynomial: " << endl;
//    print_poly(final_polynomial);
//    cout << endl;
    ZZ_p result;
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


void evaluate (ZZ_pX& P, ZZ_pX* tree, unsigned int root, unsigned int tree_size, ZZ_p* results) {
    // halting condition
    if(LEFT(root)>=tree_size) {
        ZZ_pX R = P%tree[root];
//        cout << "leaf: " << root << endl; print_poly(R); cout << endl;
        if(deg(R)>0)
            cout << "ERROR: R should be constant...";
        unsigned int result_index = root-(tree_size-1)/2;
        results[result_index] = coeff(R, 0);
        return;
    }

    ZZ_pX R = P%tree[root];
    evaluate(R, tree, LEFT(root), tree_size, results);
    evaluate(R, tree, RIGHT(root), tree_size, results);
}

void test_evaluate(ZZ_pX& P, ZZ_p* points, ZZ_p* results, unsigned int npoints) {
    bool error = false;
    for (unsigned int i = 0; i < npoints; i++) {
        ZZ_p y = eval(P, points[i]);
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