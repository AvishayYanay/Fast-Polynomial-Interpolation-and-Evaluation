//
// Created by bush on 13/01/18.
//

#ifndef MPEVAL_TESTS_GF2N_H
#define MPEVAL_TESTS_GF2N_H

#include <chrono>
#include <sys/resource.h>

#include <NTL/GF2EXFactoring.h>
#include "utils_gf2n.h"

using namespace std;
using namespace chrono;
using namespace NTL;

//n is the extension of GF2 and degree is the degree of the polynomial we want ot evaluate.
//This polynomial is over GF2^n
void test_multipoint_eval_gf2n(long n, long degree);

#endif //MPEVAL_TESTS_GF2N_H
