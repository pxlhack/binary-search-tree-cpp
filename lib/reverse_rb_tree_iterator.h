#ifndef MY_BINARY_SEARCH_TREE_REVERSE_RB_TREE_ITERATOR_H
#define MY_BINARY_SEARCH_TREE_REVERSE_RB_TREE_ITERATOR_H

#include "rb_node.h"
#include "rb_tree.h"
#include <stack>
#include <vector>

template<typename K, typename V>
class ReverseRBTreeIterator {
public:
    ReverseRBTreeIterator() {
        index = -1;
        root = nullptr;
    }

    ReverseRBTreeIterator(RBTreeNode<K, V> *root, int index) {
        this->root = root;
        this->index = index;
        if (root) {
            fill();
        }

    }

    ReverseRBTreeIterator &operator++() {
        index--;
        if (index == -1) { index = -1; }

        return *this;
    }

    ReverseRBTreeIterator &operator--() {
        index++;
        if (index == nodeVector.size()) { index = -1; }
        return *this;
    }

    bool operator==(const ReverseRBTreeIterator &iterator) {
        return this->index == iterator.index;
    }

    bool operator!=(const ReverseRBTreeIterator &iterator) {
        return this->index != iterator.index;
    }

    std::string getValue() {
        std::ostringstream strs;
        strs << nodeVector[index]->getValue();
        return strs.str();
    }

    RBTreeNode<K, V> &operator*() {
        return *nodeVector[index];
    }

private:


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
                if (node->getLeft() && node->getRight() || node->getColor() != 'b')
                    nodeVector.push_back(node);

                node = node->getRight();
            }
        }
    }

    int index;
    std::vector<RBTreeNode<K, V> *> nodeVector;
    RBTreeNode<K, V> *root;
};


#endif //MY_BINARY_SEARCH_TREE_REVERSE_RB_TREE_ITERATOR_H
