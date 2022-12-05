#ifndef MY_BINARY_SEARCH_TREE_RB_TREE_H
#define MY_BINARY_SEARCH_TREE_RB_TREE_H

#include "bst.h"


template<typename K, typename V>
class RBTree : public BST<K, V> {
public:
    RBTree();

    bool put(K key, V value) override;

    bool removeNodeByKey(K key) override;



    void print() {
        pr(this->root);
    }

private:

    Node<K, V> *insert(Node<K, V> *root, Node<K, V> *n);

    void insert_recurse(Node<K, V> *pNode, Node<K, V> *n);

    void insert_repair_tree(Node<K, V> *n);

    void insert_case1(Node<K, V> *n);

    void insert_case2(Node<K, V> *n);

    void insert_case3(Node<K, V> *n);

    void insert_case4(Node<K, V> *n);

    void rotate_left(Node<K, V> *n);

    void rotate_right(Node<K, V> *n);

    void insert_case4step2(Node<K, V> *n);

    void delete_case1(Node<K, V> *n);

    void delete_case2(Node<K, V> *n);

    void delete_case3(Node<K, V> *n);

    void delete_case4(Node<K, V> *n);

    void delete_case5(Node<K, V> *n);

    void delete_case6(Node<K, V> *n);
};




#endif //MY_BINARY_SEARCH_TREE_RB_TREE_H
