//
// Created by bush on 13/01/18.
//

#ifndef MPEVAL_UTILS_GF2N_H
#define MPEVAL_UTILS_GF2N_H

#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>
#include <NTL/GF2XFactoring.h>

using namespace std;
using namespace NTL;

void init_gf2x(GF2X& irred, long deg);
void print_poly (GF2X& P);

void build_tree (GF2EX* tree, GF2E* points, unsigned int root, unsigned int tree_size);
void test_tree (GF2EX& final_polynomial, GF2E* points, unsigned int npoints);
//
void evaluate (GF2EX& P, GF2EX* tree, unsigned int root, unsigned int tree_size, GF2E* results);
void test_evaluate(GF2EX& P, GF2E* points, GF2E* results, unsigned int npoints);


#endif //MPEVAL_UTILS_GF2N_H
