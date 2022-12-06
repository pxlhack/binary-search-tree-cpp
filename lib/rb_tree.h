#ifndef MY_BINARY_SEARCH_TREE_RB_TREE_H
#define MY_BINARY_SEARCH_TREE_RB_TREE_H

#include "bst.h"
#include "rb_node.h"
#include "rb_tree_iterator.h"
#include "reverse_rb_tree_iterator.h"

#define RED 'r'
#define BLACK 'b'

template<typename K, typename V>
class RBTree : public BST<K, V> {
public:
    RBTree();

    bool put(K key, V value) override;

    bool removeNodeByKey(K key) override;

    V getValueByKey(K key) override;

    void print();

    RBTreeIterator<K, V> itbegin();

    RBTreeIterator<K, V> itend();

    ReverseRBTreeIterator<K, V> itrbegin();

    ReverseRBTreeIterator<K, V> itrend();

private:

    RBTreeNode<K, V> *root = nullptr;

    RBTreeNode<K, V> *insert(RBTreeNode<K, V> *root, RBTreeNode<K, V> *n);

    void insert_recurse(RBTreeNode<K, V> *pNode, RBTreeNode<K, V> *n);

    void insert_repair_tree(RBTreeNode<K, V> *n);

    void insert_case1(RBTreeNode<K, V> *n);

    void insert_case2(RBTreeNode<K, V> *n);

    void insert_case3(RBTreeNode<K, V> *n);

    void insert_case4(RBTreeNode<K, V> *n);

    void rotate_left(RBTreeNode<K, V> *n);

    void rotate_right(RBTreeNode<K, V> *n);

    void insert_case4step2(RBTreeNode<K, V> *n);

    void delete_case1(RBTreeNode<K, V> *n);

    void delete_case2(RBTreeNode<K, V> *n);

    void delete_case3(RBTreeNode<K, V> *n);

    void delete_case4(RBTreeNode<K, V> *n);

    void delete_case5(RBTreeNode<K, V> *n);

    void delete_case6(RBTreeNode<K, V> *n);

    RBTreeNode<K, V> *sibling(RBTreeNode<K, V> *t);

    RBTreeNode<K, V> *uncle(RBTreeNode<K, V> *t);

    RBTreeNode<K, V> *grandparent(RBTreeNode<K, V> *t);

    bool isLeaf(RBTreeNode<K, V> *t);

    RBTreeNode<K, V> *search(RBTreeNode<K, V> *temp, K key);

    void replaceNode(RBTreeNode<K, V> *n, RBTreeNode<K, V> *child);

    void nodePrint(RBTreeNode<K, V> *tmp, int n = 0);

    void leaf(RBTreeNode<K, V> *t);
};

template<typename K, typename V>
ReverseRBTreeIterator<K, V> RBTree<K, V>::itrbegin() {
    return ReverseRBTreeIterator<K, V>(root, this->size - 1);
}

template<typename K, typename V>
ReverseRBTreeIterator<K, V> RBTree<K, V>::itrend() {
    return ReverseRBTreeIterator<K, V>(root, -1);
}


template<typename K, typename V>
RBTreeIterator<K, V> RBTree<K, V>::itbegin() {
    return RBTreeIterator<K, V>(root, 0);
}

template<typename K, typename V>
RBTreeIterator<K, V> RBTree<K, V>::itend() {
    return RBTreeIterator<K, V>(root, -1);
}

#endif //MY_BINARY_SEARCH_TREE_RB_TREE_H
