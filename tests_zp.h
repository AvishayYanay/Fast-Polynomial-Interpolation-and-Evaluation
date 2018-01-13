//
// Created by bush on 13/01/18.
//

#ifndef MPEVAL_TESTS_ZP_H
#define MPEVAL_TESTS_ZP_H

#include <chrono>
#include <sys/resource.h>
#include "utils_zp.h"

using namespace std;
using namespace chrono;
using namespace NTL;


void test_multipoint_eval_zp(ZZ prime, long degree);

#endif //MPEVAL_TESTS_ZP_H
