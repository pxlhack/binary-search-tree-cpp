//
// Created by pxlhack on 07.11.22.
//

#ifndef MY_BINARY_SEARCH_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_NODE_H

template<typename K, typename V>
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

#endif //MY_BINARY_SEARCH_TREE_NODE_H
