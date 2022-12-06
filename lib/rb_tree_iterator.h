#ifndef MY_BINARY_SEARCH_TREE_RB_TREE_ITERATOR_H
#define MY_BINARY_SEARCH_TREE_RB_TREE_ITERATOR_H

#include "tree_iterator.h"
#include "rb_tree.h"

template<typename K, typename V>
class RBTreeIterator {
public:
    RBTreeIterator(RBTreeNode<K, V> *root, int index) {
        this->root = root;
        this->index = index;
        if (root) {
            fill();
        }
    }

    RBTreeNode<K, V> &operator*() {
        return *nodeVector[this->index];
    }


private:
    std::vector<RBTreeNode<K, V> *> nodeVector;
    RBTreeNode<K, V> *root;
    int index;

    void fill() {
        RBTreeNode<K, V> *node = root;
        std::stack<RBTreeNode<K, V> *> st;
        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node->getLeft();
            } else {
                node = st.top();
                st.pop();
                nodeVector.push_back(node);
                node = node->getRight();
            }
        }
    }
};


#endif //MY_BINARY_SEARCH_TREE_RB_TREE_ITERATOR_H
