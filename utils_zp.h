//
// Created by bush on 12/01/18.
//

#ifndef MPEVAL_UTILS_H
#define MPEVAL_UTILS_H


#include <NTL/ZZ_p.h>
#include <NTL/vec_ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

void print_poly (ZZ_pX& P);//, int degree);

void build_tree (ZZ_pX* tree, ZZ_p* points, unsigned int root, unsigned int tree_size);
void test_tree (ZZ_pX& final_polynomial, ZZ_p* points, unsigned int npoints);

void evaluate (ZZ_pX& P, ZZ_pX* tree, unsigned int root, unsigned int tree_size, ZZ_p* results);
void test_evaluate(ZZ_pX& P, ZZ_p* points, ZZ_p* results, unsigned int npoints);

#endif //MPEVAL_UTILS_H
