#ifndef MY_BINARY_SEARCH_TREE_RBTREE_NODE_H
#define MY_BINARY_SEARCH_TREE_RBTREE_NODE_H

#include <iostream>
#include "node.h"

using namespace std;

template<typename K, typename V>
class RBTreeNode : public Node<K, V> {
public:
    RBTreeNode() {
        Node<K, V>();
        this->parent = nullptr;
        this->color = 'r';
    }

    RBTreeNode(K key, V value) {
        RBTreeNode<K, V>();
        this->key = key;
        this->value = value;
    }

    char getColor() {
        return color;
    }

    void setColor(char c) {
        color = c;
    }

    RBTreeNode* getParent() const {
        return parent;
    }

    void setParent(RBTreeNode* parent) {
        RBTreeNode::parent = parent;
    }

    RBTreeNode* getRight() const {
        return right;
    }

    void setRight(RBTreeNode* right) {
        this->right = right;
    }

    RBTreeNode* getLeft() const {
        return left;
    }

    void setLeft(RBTreeNode* left) {
        this->left = left;
    }


private:
    char color;
    RBTreeNode* parent;
    RBTreeNode<K, V>* left;
    RBTreeNode<K, V>* right;
};


#endif //MY_BINARY_SEARCH_TREE_RBTREE_NODE_H
