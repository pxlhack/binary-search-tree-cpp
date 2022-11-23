//
// Created by noneme on 23.11.2022.
//

#ifndef MY_BINARY_SEARCH_TREE_COMPLEXITY_TEST_H
#define MY_BINARY_SEARCH_TREE_COMPLEXITY_TEST_H
using namespace std;
typedef unsigned long long INT_64;

static INT_64 RRand = 15750;
const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;


int complexityTest();

void test_rand(int n);

void test_ord(int n);

INT_64 LineRand();

void sRand();

#endif //MY_BINARY_SEARCH_TREE_COMPLEXITY_TEST_H
