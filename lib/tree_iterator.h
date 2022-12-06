

#ifndef MY_BINARY_SEARCH_TREE_TREE_ITERATOR_H
#define MY_BINARY_SEARCH_TREE_TREE_ITERATOR_H

#include "node.h"
#include "bst.h"
#include <stack>
#include <vector>

template<typename K, typename V>
class TreeIterator {
public:
    TreeIterator() {
        index = -1;
        root = nullptr;
    }

    TreeIterator(Node<K, V> *root, int index) {
        this->root = root;
        this->index = index;
        if (root)
            fill();
    }

    TreeIterator &operator++() {
        index++;
        if (index == nodeVector.size()) { index = -1; }
        return *this;
    }

    TreeIterator &operator--() {
        index--;
        if (index == -1) { index = -1; }
        return *this;
    }

    bool operator==(const TreeIterator &iterator) {
        return this->index == iterator.index;
    }

    bool operator!=(const TreeIterator &iterator) {
        return this->index != iterator.index;
    }

    std::string getValue() {
        std::ostringstream strs;
        strs << nodeVector[index]->getValue();
        return strs.str();
    }

    virtual Node<K, V> &operator*() {
        return *nodeVector[index];
    }

protected:
    virtual void fill() {
        Node<K, V> *node = root;
        std::stack<Node<K, V> *> st;
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

    int index;
private:

    std::vector<Node<K, V> *> nodeVector;
    Node<K, V> *root;
};

template<typename K, typename V>
class RTreeIterator {
public:
    RTreeIterator() {
        index = -1;
        root = nullptr;
    }

    RTreeIterator(Node<K, V> *root, int index) {
        this->root = root;
        this->index = index;
        if (root) {
            fill();
        }
    }

    RTreeIterator &operator++() {
        index++;
        if (index == -1) {
            index = -1;
        }

        return *this;
    }

    RTreeIterator &operator--() {
        index--;
        if (index == nodeVector.size()) { index = -1; }
        return *this;
    }

    bool operator==(const RTreeIterator &iterator) {
        return this->index == iterator.index;
    }

    bool operator!=(const RTreeIterator &iterator) {
        return this->index != iterator.index;
    }

    std::string getValue() {
        std::ostringstream strs;
        strs << nodeVector[index]->getValue();
        return strs.str();
    }

    Node<K, V> &operator*() {
        return *nodeVector[index];
    }


protected:
    int index;

    virtual void fill() {
        Node<K, V> *node = root;
        std::stack<Node<K, V> *> st;
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

private:
    std::vector<Node<K, V> *> nodeVector;
    Node<K, V> *root;
};


#endif //MY_BINARY_SEARCH_TREE_TREE_ITERATOR_H
