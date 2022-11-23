
#ifndef MY_BINARY_SEARCH_TREE_USER_FUNCTIONS_H
#define MY_BINARY_SEARCH_TREE_USER_FUNCTIONS_H

#include "bst.h"
#include "regex"
#include <exception>
#include <ctime>


#define HELP "Menu:\n\
1) Create new empty tree\n\
2) Create new tree and random fill\n\
3) Insert new node to tree\n\
4) Remove node with key\n\
5) Change the value with key\n\
6) Show list of keys\n\
7) Show list of values\n\
8) Show size\n\
9) Check the tree for emptiness\n\
10) Get value with key\n\
11) Get count of nodes with keys more than \n\
12) Count of values in previous operation\n\
13) Clear tree\n\
14) Iterators\n\
0) Exit\n"


void testMenu();

bool isValidCommand(const string &command);

bool isPositiveValue(std::string_view s);

bool createBST(BST<int, int> **pBst);

int getRandom(int begin, int end);

void randomFill(BST<int, int> **tree, int size);

string getIntegerValueAsString(const string &desiredValue);

bool isNegativeValue(std::string_view s);

string getPositiveValueAsString(const string &desiredValue);

bool setValueFromString(int *value);

bool setKeyFromString(int *key);

#endif //MY_BINARY_SEARCH_TREE_USER_FUNCTIONS_H
