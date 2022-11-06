//
// Created by pxlhack on 06.11.22.
//

#ifndef MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H
#define MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>

using namespace std;

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

    void set(K key, V newValue);

    V get(K key);

    bool remove(K k);

    void showKeyList();

    void showTree();

    int getTreeNodesCountViewedByPreviousOperation;

private:
    class Node {
    public:
        Node() {
            this->right = nullptr;
            this->left = nullptr;
        }

        Node(K key, V value) {
            this->key = key;
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
        }

        K getKey() const {
            return key;
        }

        void setKey(K key) {
            Node::key = key;
        }

        V getValue() const {
            return value;
        }

        void setValue(V value) {
            Node::value = value;
        }

        Node *getRight() const {
            return right;
        }

        void setRight(Node *right) {
            Node::right = right;
        }

        Node *getLeft() const {
            return left;
        }

        void setLeft(Node *left) {
            Node::left = left;
        }

    private:
        K key;
        V value;
        Node *right, *left;
    };

    Node *root = nullptr;
    int treeNodesCountViewedByPreviousOperation;
};


#endif //MY_BINARY_SEARCH_TREE_MY_BINARY_SEARCH_TREE_H
