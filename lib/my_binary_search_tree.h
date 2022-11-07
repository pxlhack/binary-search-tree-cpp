//
// Created by pxlhack on 06.11.22.
//

#ifndef MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H
#define MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>
#include "node.h"

using namespace std;

template<typename K, typename V>
void inorderTraversal(Node<K, V> *x) {
    if (x != nullptr) {
        inorderTraversal(x->getLeft());
        cout << x->getKey() << "~" << x->getValue() << " ";
        inorderTraversal(x->getRight());
    }
}

template<typename K, typename V>
class MyBinarySearchTree {
public:
    MyBinarySearchTree();

    MyBinarySearchTree(MyBinarySearchTree &myBinarySearchTree);

    ~MyBinarySearchTree();

    int getSize();

    void clear();

    bool isEmpty();

    bool put(K key, V value);

    bool set(K key, V newValue);

    V get(K key);

    bool remove(K k);

//    void showKeyList();

    void showKeyList();

    int getTreeNodesCountViewedByPreviousOperation;

    void showInorderTraversal() {
        inorderTraversal(root);
        cout << "\n";
    }

private:
    Node<K, V> *root = nullptr;
    int treeNodesCountViewedByPreviousOperation;
    int size;
};


#endif //MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H
