//
// Created by bush on 13/01/18.
//

#include "tests_gf2n.h"


void test_multipoint_eval_gf2n(long n, long degree) {
    GF2X irreducible;
    init_gf2x(irreducible,n);
//    print_poly(irreducible);
//    cout << endl;

    // the given polynomial
    GF2EX P;
    random(P, degree+1);
    SetCoeff(P,degree,random_GF2E());
//    cout << "The polynomial P:" << endl << P << endl;

    // evaluation points:
    GF2E* x = new GF2E[degree+1];
    GF2E* y = new GF2E[degree+1];

    for(unsigned int i=0;i<=degree; i++) {
        random(x[i]);
//        cout << x[i] << endl;
    }

    // we want to evaluate P on 'degree+1' values.
    GF2EX* p_tree = new GF2EX[degree*2+1];
    steady_clock::time_point begin1 = steady_clock::now();
    build_tree (p_tree, x, 0, degree*2+1);
    steady_clock::time_point end1 = steady_clock::now();
//    test_tree(p_tree[0], x, degree+1);

    steady_clock::time_point begin2 = steady_clock::now();
    evaluate(P, p_tree, 0, degree*2+1, y);
    chrono::steady_clock::time_point end2 = steady_clock::now();
//    test_evaluate(P,x,y,degree+1);

    cout << "Building tree: " << duration_cast<milliseconds>(end1 - begin1).count() << " ms" << endl;
    cout << "Evaluating points: " << duration_cast<milliseconds>(end2 - begin2).count() << " ms" << endl;
    cout << "Total: " << duration_cast<milliseconds>(end1 - begin1).count()+ duration_cast<milliseconds>(end2 - begin2).count() << " ms" << endl;
}