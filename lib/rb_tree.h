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
};


#endif //MY_BINARY_SEARCH_TREE_RB_TREE_H
