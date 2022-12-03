#include "../lib/rb_tree.h"


template<typename K, typename V>
RBTree<K, V>::RBTree() {

}

template<typename K, typename V>
bool RBTree<K, V>::put(K key, V value) {
    /*this->nodes_counter = 0;
    auto *newNode = new Node<K, V>(key, value);
    if (this->root == nullptr) {
        this->root = newNode;
        this->size = 1;
        this->nodes_counter++;
        return true;
    } else {
        hidden_put();
    }*/
    bool *ins;

    this->root = hidden_put(this->root, key, value, 0, ins);
    this->root->setColor('b');
    return *ins;
}

template<typename K, typename V>
bool RBTree<K, V>::removeNodeByKey(K key) {

}

template<typename K, typename V>
V RBTree<K, V>::getValueByKey(K key) {

}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::hidden_put(Node<K, V> *t, K k, V data, int s, bool *ins) {
    /*
       t – корень дерева/поддерева
2.  k – ключ нового элемента
3.  data – данные нового элемента
4.  s – тип родителя(левый – 0/правый – 1)
5.  iserted – возвращаемый признак вставки
6.  tnil – фиктивный узел RB-дерева
     */

    if (t == nullptr) {
        t = new Node<K, V>(k, data);
        t->setColor('r');
        return t;
    }
    if (k == t->getKey()) {
        *ins = false;
        return t;
    }
//    if (t->getLeft()->getColor() == 'r' && t->getRight()->getColor() == 'r') {
//        t->setColor('r');
//        t->getLeft()->setColor('b');
//        t->getRight()->setColor('r');
//    }

    bool *ins2;
    if (k < t->getKey()) {
        t->setLeft(hidden_put(t->getLeft(), k, data, 0, ins2));
        if (t->getColor() == 'r' && t->getLeft()->getColor() == 'r' && s == 1) {
            t = R(t);
        }
        if (t->getLeft()->getColor() == 'r' && t->getLeft()->getLeft()->getColor() == 'r') {
            t = R(t);
            t->setColor('b');
            t->getRight()->setColor('r');
        }
    } else {
        t->setRight(hidden_put(t->getRight(), k, data, 1, ins2));

        if (t->getColor() == 'r' && t->getRight()->getColor() == 'r' && s == 0) {
            t = L(t);
        }

        if (t->getRight()->getColor() == 'r' && t->getRight()->getRight()->getColor() == 'r') {
            t = L(t);
            t->setColor('b');
            t->getLeft()->setColor('r');
        }
    }
    *ins = *ins2;
    return t;
}


template<typename K, typename V>
Node<K, V> *RBTree<K, V>::R(Node<K, V> *t) {
    if (t == nullptr) {
        return nullptr;
    } else {
        auto x = t->getLeft();
        t->setLeft(x->getRight());
        x->setRight(t);
        return x;
    }
}


template<typename K, typename V>
Node<K, V> *RBTree<K, V>::L(Node<K, V> *t) {
    if (t == nullptr) {
        return nullptr;
    } else {
        auto x = t->getRight();
        t->setRight(x->getLeft());
        x->setLeft(t);
        return x;
    }

}


template
class RBTree<int, int>;

template
class RBTree<unsigned long long, int>;