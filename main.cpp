#include <iostream>
#include <cmath>
#include <NTL/ZZ.h>


#include "tests_zp.h"
#include "tests_gf2n.h"

#define MERSENNE_13 (8191)  //2^13-1
#define MERSENNE_31 (2147483647)
#define MERSENNE_61 (2305843009213693951)

using namespace std;
using namespace NTL;

int main()
{
    for (int i=10; i<=20; i++) {
        long degree = pow(2,i)-1;
        cout << "*** n=2^" << i << endl;
        test_multipoint_eval_zp(ZZ(MERSENNE_61),degree);
    }

    long n = 64;
    for (int i=10; i<=20; i++) {
        long degree = pow(2,i)-1;
        cout << "*** n=2^" << i << endl;
        test_multipoint_eval_gf2n(n,degree);
    }

}