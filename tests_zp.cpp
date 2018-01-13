//
// Created by bush on 13/01/18.
//

#include "tests_zp.h"

void test_multipoint_eval_zp(ZZ prime, long degree)
{
    // init underlying prime field
    ZZ_p::init(ZZ(prime));

    // the given polynomial
    ZZ_pX P;
    random(P, degree+1);
    SetCoeff(P,degree,random_ZZ_p());

    // evaluation points:
    ZZ_p* x = new ZZ_p[degree+1];
    ZZ_p* y = new ZZ_p[degree+1];

    for(unsigned int i=0;i<=degree; i++) {
        random(x[i]);
    }

    // we want to evaluate P on 'degree+1' values.
    ZZ_pX* p_tree = new ZZ_pX[degree*2+1];
    steady_clock::time_point begin1 = steady_clock::now();
    build_tree (p_tree, x, 0, degree*2+1);
    steady_clock::time_point end1 = steady_clock::now();
//    test_tree(p_tree[0], x, DEGREE+1);

    steady_clock::time_point begin2 = steady_clock::now();
    evaluate(P, p_tree, 0, degree*2+1, y);
    chrono::steady_clock::time_point end2 = steady_clock::now();
//    test_evaluate(P,x,y,DEGREE+1);

    cout << "Building tree: " << duration_cast<milliseconds>(end1 - begin1).count() << " ms" << endl;
    cout << "Evaluating points: " << duration_cast<milliseconds>(end2 - begin2).count() << " ms" << endl;
    cout << "Total: " << duration_cast<milliseconds>(end1 - begin1).count()+ duration_cast<milliseconds>(end2 - begin2).count() << " ms" << endl;
}