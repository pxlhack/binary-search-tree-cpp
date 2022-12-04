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
    /*bool *ins;

    this->root = hidden_put(this->root, key, value, 0, ins);
    this->root->setColor('b');
    return *ins;*/

    Node<K, V> *node = new Node<K, V>(key, value);
    this->root = insert(this->root, node);

    return true;
}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::insert(Node<K, V> *root, Node<K, V> *n) {
    insert_recurse(root, n);

    // repair the tree in case any of the red-black properties have been violated
    insert_repair_tree(n);

    // find the new root to return
    root = n;
    while (root->parent != nullptr)
        root = root->parent;
    return root;
}

template<typename K, typename V>
void RBTree<K, V>::insert_repair_tree(Node<K, V> *n) {
    if (n->parent == nullptr) {
        insert_case1(n);
    } else if (n->parent->color == 'b') {
        insert_case2(n);
    } else if (n->uncle()->color == 'r') {
        insert_case3(n);
    } else {
        insert_case4(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::insert_case1(Node<K, V> *n) {
    if (n->parent == nullptr)
        n->color = 'b';
}


template<typename K, typename V>
void RBTree<K, V>::insert_case2(Node<K, V> *n) {
    return;
}

template<typename K, typename V>
void RBTree<K, V>::insert_case3(Node<K, V> *n) {
    n->parent->color = 'b';
    n->uncle()->color = 'b';
    n->grandparent()->color = 'r';
    insert_repair_tree(n->grandparent());
}

template<typename K, typename V>
void RBTree<K, V>::insert_case4(Node<K, V> *n) {
    Node<K, V> *p = n->parent;
    Node<K, V> *g = n->grandparent();

    if (n == g->left->right) {
        rotate_left(p);
        n = n->left;
    } else if (n == g->right->left) {
        rotate_right(p);
        n = n->right;
    }

    insert_case4step2(n);
}

template<typename K, typename V>
void RBTree<K, V>::insert_case4step2(Node<K, V> *n) {
    Node<K, V> *p = n->parent;
    Node<K, V> *g = n->grandparent();

    if (n == p->left)
        rotate_right(g);
    else
        rotate_left(g);
    p->color = 'b';
    g->color = 'r';
}

template<typename K, typename V>
void RBTree<K, V>::rotate_left(Node<K, V> *n) {
    Node<K, V> *nnew = n->right;
    Node<K, V> *p = n->parent;
    //fixme
    // assert(nnew != NULL); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;
    // handle other child/parent pointers
    if (n->right != nullptr)
        n->right->parent = n;
    if (p != nullptr) // initially n could be the root
    {
        if (n == p->left)
            p->left = nnew;
        else if (n == p->right) // if (...) is excessive
            p->right = nnew;
    }
    nnew->parent = p;
}

template<typename K, typename V>
void RBTree<K, V>::rotate_right(Node<K, V> *n) {
    Node<K, V> *nnew = n->left;
    Node<K, V> *p = n->parent;

    //fixme
    // assert(nnew != NULL); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->left = nnew->right;
    nnew->right = n;
    n->parent = nnew;
    // handle other child/parent pointers
    if (n->left != nullptr)
        n->left->parent = n;
    if (p != nullptr) // initially n could be the root
    {
        if (n == p->left)
            p->left = nnew;
        else if (n == p->right) // if (...) is excessive
            p->right = nnew;
    }
    nnew->parent = p;
}

template<typename K, typename V>
void RBTree<K, V>::insert_recurse(Node<K, V> *root, Node<K, V> *n) {
    auto *LEAF = new Node<K, V>();
    if (root != NULL && n->getKey() < root->getKey()) {
        if (root->getLeft() != LEAF) {
            insert_recurse(root->getLeft(), n);
            return;
        } else
            root->left = n;
    } else if (root != NULL) {
        if (root->right != LEAF) {
            insert_recurse(root->right, n);
            return;
        } else
            root->right = n;
    }

    // insert new n n
    n->parent = root;
    n->left = LEAF;
    n->right = LEAF;
    n->color = 'r';
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