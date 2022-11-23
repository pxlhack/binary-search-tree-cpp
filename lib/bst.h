//
// Created by pxlhack on 06.11.22.
//

#ifndef MY_BINARY_SEARCH_TREE_BST_H
#define MY_BINARY_SEARCH_TREE_BST_H

#include <iostream>
#include <sstream>
#include <stack>
#include "node.h"
#include "tree_iterator.h"


using namespace std;


template<typename K, typename V>
class BST {
public:
    BST();

    BST(BST &bst);

    ~BST();

    int getSize();

    void clear();

    bool isEmpty();

    V getValueByKey(K key);

    bool put(K key, V value);

    bool removeNodeByKey(K key);

    bool setValueForKey(V value, K key);

    void showKeysList();

    void showValuesList();

    int getTreeNodesCountViewedByPreviousOperation();

    int nodesCountWithKeysMoreThan(K key);


    TreeIterator<K, V> begin();

    TreeIterator<K, V> end();

    RTreeIterator<K, V> rbegin();

    RTreeIterator<K, V> rend();

private:
    Node<K, V> *root;
    int nodes_counter;
    int size;

    Node<K, V> *getNodeByKey(K key);

    string getStringOfKeys();

    string getStringOfValues();

};


#endif //MY_BINARY_SEARCH_TREE_BST_H
