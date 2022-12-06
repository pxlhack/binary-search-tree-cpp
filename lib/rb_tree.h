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


    bool remove(K key);

    K getRootKey() {
        return this->root->getKey();
    }

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

    void rb_transplant(RBTreeNode<K, V> *u, RBTreeNode<K, V> *v) {
        if (u->getParent() == nullptr)
            this->root = v;
        else if (u == u->getParent()->getLeft())
            u->getParent()->setLeft(v);
        else
            u->getParent()->setRight(v);
        if (u == root) {
            v->setParent(nullptr);
        }
        v->setParent(u->getParent());
    }

    void rb_delete(RBTreeNode<K, V> *z) {
        RBTreeNode<K, V> *y = z;
        RBTreeNode<K, V> *x;
        char orig_color = y->getColor();

//        if (z->getLeft() == nullptr) {
        if (isLeaf(z->getLeft())) {
            x = z->getRight();
            rb_transplant(z, z->getRight());
//        } else if (z->getRight() == nullptr) {
        } else if (isLeaf(z->getRight())) {

            x = z->getLeft();
            rb_transplant(z, z->getLeft());
        } else {

            y = rb_tree_minimum(z->getRight());
            orig_color = y->getColor();
            x = y->getRight();
            if (y->getParent() == z)
                x->setParent(y);
            else {
                rb_transplant(y, y->getRight());
                y->setRight(z->getRight());
                y->getRight()->setParent(y);
            }
            rb_transplant(z, y);
            y->setLeft(z->getLeft());
            y->getLeft()->setParent(y);
            y->setColor(z->getColor());
        }
        if (orig_color == BLACK)
            rb_delete_fixup(x);
    }

    RBTreeNode<K, V> *rb_tree_minimum(RBTreeNode<K, V> *x) {

        while (!isLeaf(x->getLeft())) {
            x = x->getLeft();

        }

        return x;
    }

    void left_rotate(RBTreeNode<K, V> *x) {

        /*assert(x->getRight() != nullptr);
        assert(this->root->getParent() == nullptr);*/

        RBTreeNode<K, V> *y = x->getRight();
        x->setRight(y->getLeft());

        if (y->getLeft() != nullptr)
            y->getLeft()->setParent(x);
        y->setParent(x->getParent());
        if (x->getParent() == nullptr)
            this->root = y;
        else if (x == x->getParent()->getLeft())
            x->getParent()->setLeft(y);
        else
            x->getParent()->setRight(y);
        y->setLeft(x);
        x->setParent(y);
    }

    void right_rotate(RBTreeNode<K, V> *y) {

        /* assert(y->getLeft() != nullptr);
         assert(this->root->getParent() == nullptr);*/

        RBTreeNode<K, V> *x = y->getLeft();
        y->setLeft(x->getRight());

        if (x->getRight() != nullptr)
            x->getRight()->setParent(y);
        x->setParent(y->getParent());
        if (y->getParent() == nullptr)
            this->root = x;
        else if (y == y->getParent()->getLeft())
            y->getParent()->setLeft(x);
        else
            y->getParent()->setRight(x);
        x->setRight(y);
        y->setParent(x);
    }

    void rb_delete_fixup(RBTreeNode<K, V> *x) {
        while ((x != this->root) && (x->getColor() == BLACK)) {
            if (x == x->getParent()->getLeft()) {
                RBTreeNode<K, V> *w = x->getParent()->getRight();
                if (w->getColor() == RED) {
                    w->setColor(BLACK);
                    x->getParent()->setColor(RED);
                    left_rotate(x->getParent());
                    w = x->getParent()->getRight();
                }
                if ((w->getLeft()->getColor() == BLACK) && (w->getRight()->getColor() == BLACK)) {
                    w->setColor(RED);
                    x = x->getParent();
                } else {
                    if (w->getRight()->getColor() == BLACK) {
                        w->getLeft()->setColor(BLACK);
                        w->setColor(RED);
                        right_rotate(w);
                        w = x->getParent()->getRight();
                    }
                    w->setColor(x->getParent()->getColor());
                    x->getParent()->setColor(BLACK);
                    w->getRight()->setColor(BLACK);
                    left_rotate(x->getParent());
                    x = this->root;
                }
            } else {
                RBTreeNode<K, V> *w = x->getParent()->getLeft();
                if (w->getColor() == RED) {
                    w->setColor(BLACK);
                    x->getParent()->setColor(RED);
                    right_rotate(x->getParent());
                    w = x->getParent()->getLeft();
                }
                if ((w->getRight()->getColor() == BLACK) && (w->getLeft()->getColor() == BLACK)) {
                    w->setColor(RED);
                    x = x->getParent();
                } else {
                    if (w->getLeft()->getColor() == BLACK) {
                        w->getRight()->setColor(BLACK);
                        w->setColor(RED);
                        left_rotate(w);
                        w = x->getParent()->getLeft();
                    }
                    w->setColor(x->getParent()->getColor());
                    x->getParent()->setColor(BLACK);
                    w->getLeft()->setColor(BLACK);
                    right_rotate(x->getParent());
                    x = this->root;
                }
            }
        }
        x->setColor(BLACK);
    }



};

template<typename K, typename V>
bool RBTree<K, V>::remove(K key) {
    try {
        RBTreeNode<K, V> *n = search(this->root, key);
        rb_delete(n);
        delete n;
        this->size--;
        return true;
    }
    catch (const char *c) {
        //fixme
//        cout << c << endl;
    }
    return false;
}


#endif //MY_BINARY_SEARCH_TREE_RB_TREE_H
