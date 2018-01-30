#include <iostream>
#include <cmath>
#include <NTL/ZZ.h>


//#include "tests_zp.h"
//#include "tests_gf2n.h"

#include "zp.h"

#define MERSENNE_13 (8191)  //2^13-1
#define MERSENNE_31 (2147483647)
#define MERSENNE_61 (2305843009213693951)

using namespace std;
using namespace NTL;

#define LOGN (20)

void recursive()
{
//    long degree = pow(2,20)-1;
//    ZZ prime;
//    GenPrime(prime, 400);
//    cout << "prime: " << prime << endl;
//    test_multipoint_eval_zp(prime,degree);
//    GenPrime(prime, 256);
//    cout << "prime: " << prime << endl;
//    test_multipoint_eval_zp(prime,degree);
//    for (int i=10; i<=LOGN; i++) {
//        long degree = pow(2,i)-1;
//        cout << "*** n=2^" << i << endl;
//        test_multipoint_eval_zp(ZZ(MERSENNE_61),degree);
//    }

//    long n = 64;
//    for (int i=10; i<=LOGN; i++) {
//        long degree = pow(2,i)-1;
//        cout << "*** n=2^" << i << endl;
//        test_multipoint_eval_gf2n(n,degree);
//    }


//    for (int i=10; i<=LOGN; i++) {
//        long degree = pow(2,i)-1;
//        cout << "*** n=2^" << i << endl;
//        ZZ prime;
//        GenPrime(prime, 400);
//        cout << "prime: " << prime << endl;
//
//        test_interpolate_zp(prime, degree);
//    }
}

int main() {
    ZZ prime;
    GenPrime(prime, 100);
    cout << "prime: " << prime << endl;

//    for (int i=10; i<=LOGN; i++) {
//        long degree = pow(2,i)-1;
//        cout << "*** n=2^" << i << endl;
//        test_multipoint_eval_zp(ZZ(MERSENNE_61),degree);
//    }

    for (int i=10; i<=LOGN; i++) {
        long degree = pow(2,i)-1;
        cout << "*** n=2^" << i << endl;
        test_interpolate_zp(ZZ(MERSENNE_61),degree);
    }
}