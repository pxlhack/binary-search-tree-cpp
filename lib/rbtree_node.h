#ifndef MY_BINARY_SEARCH_TREE_RBTREE_NODE_H
#define MY_BINARY_SEARCH_TREE_RBTREE_NODE_H

#include <iostream>
#include "tree_node.h"

using namespace std;

template<typename K, typename V>
class RBTreeNode : public TreeNode<K, V> {
public:
    RBTreeNode() {
        TreeNode<K, V>();
        this->parent = nullptr;
        color = 'r';
    }


    char getColor() {
        return color;
    }

    void setColor(char c) {
        color = c;
    }

    RBTreeNode *getParent() const {
        return parent;
    }

    void setParent(RBTreeNode *parent) {
        RBTreeNode::parent = parent;
    }


private:
    char color;
    RBTreeNode *parent;
};


#endif //MY_BINARY_SEARCH_TREE_RBTREE_NODE_H
