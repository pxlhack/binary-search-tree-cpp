#ifndef MY_BINARY_SEARCH_TREE_RB_TREE_H
#define MY_BINARY_SEARCH_TREE_RB_TREE_H

#include "bst.h"


template<typename K, typename V>
class RBTree : public BST<K, V> {
public:
    RBTree();

    bool put(K key, V value) override;

    bool removeNodeByKey(K key) override;

    V getValueByKey(K key) override;

private:

    Node<K, V> *hidden_put(Node<K, V> *t, K k, V data, int s, bool *ins);

    Node<K, V> *L(Node<K, V> *t);

    Node<K, V> *R(Node<K, V> *t);

    Node<K, V> *insert(Node<K, V> *root, Node<K, V> *n);

    void insert_recurse(Node<K, V> *pNode, Node<K, V> *n);

    void insert_repair_tree(Node<K, V> *n);

    void insert_case1(Node<K, V> *n);

    void insert_case2(Node<K, V> *n);

    void insert_case3(Node<K, V> *n);

    void insert_case4(Node<K, V> *n);

    void rotate_left(Node<K,V> *n) ;

    void rotate_right(Node<K,V> *n);

    void insert_case4step2(Node<K,V> *n);
};




#endif //MY_BINARY_SEARCH_TREE_RB_TREE_H
