#ifndef MY_BINARY_SEARCH_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_NODE_H

#include <iostream>

using namespace std;

template<typename K, typename V>
class Node {
public:
    Node() {
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
        color = 'r';
    }

    Node(K key, V value) {
        this->key = key;
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
        color = 'r';
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
        this->left = left;
    }

    char getColor() {
        return color;
    }

    void setColor(char c) {
        color = c;
    }

    Node *getParent() const {
        return parent;
    }

    void setParent(Node *parent) {
        Node::parent = parent;
    }


private:
    V value;
    K key;
    char color;
    Node *left;
    Node *parent;
    Node *right;
};


#endif //MY_BINARY_SEARCH_TREE_NODE_H
