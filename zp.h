//
// Created by bush on 29/01/18.
//

#ifndef MPEVAL_ZP_H
#define MPEVAL_ZP_H

#include <chrono>
#include <sys/resource.h>
#include <iostream>

#include <NTL/ZZ_p.h>
#include <NTL/vec_ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;
using namespace chrono;



void test_multipoint_eval_zp(ZZ prime, long degree);
void test_interpolate_zp(ZZ prime, long degree);

#endif //MPEVAL_ZP_H
