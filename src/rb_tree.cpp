#include "../lib/rb_tree.h"

#define RED 'r'
#define BLACK 'b'

template<typename K, typename V>
RBTree<K, V>::RBTree() {

}

template<typename K, typename V>
bool RBTree<K, V>::put(K key, V value) {
    auto *node = new Node<K, V>(key, value);
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
    if (n->parent == nullptr) {
        n->color = 'b';
    }
}


template<typename K, typename V>
void RBTree<K, V>::insert_case2(Node<K, V> *n) {
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
    Node<K, V> *p = n->parent;

    Node<K, V> *nnew = n->right;
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;

  /*  //fixme
    // assert(nnew != NULL); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;*/

    // handle other child/parent pointers
    if (n->right != nullptr) {
        n->right->parent = n;
    }

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
    if (root != nullptr && n->getKey() < root->getKey()) {
        if (!(root->getLeft()->isLeaf())) {
            insert_recurse(root->getLeft(), n);
            return;
        } else {

            root->left = n;
        }
    } else if (root != nullptr) {
        if (!(root->getRight()->isLeaf())) {
            insert_recurse(root->right, n);
            return;
        } else {
            root->right = n;
        }
    }

    // insert new n n
    n->parent = root;
    n->left = new Node<K, V>();
    n->left->leaf();
    n->right = new Node<K, V>();
    n->right->leaf();
    n->color = 'r';
}

template<typename K, typename V>
Node<K, V>* successor(Node<K, V>* x) {
    Node<K, V>* temp = x;

    while (temp->getLeft() != nullptr)
        temp = temp->getLeft();

    return temp;
}

// find node that replaces a deleted node in BST
template<typename K, typename V>
Node<K, V>* BSTreplace(Node<K, V>* x) {
    // when node have 2 children
    if (x->getLeft() != nullptr && x->getRight() != nullptr)
        return successor(x->getRight());

    // when leaf
    if (x->getLeft() == nullptr && x->getRight() == nullptr)
        return nullptr;

    // when single child
    if (x->getLeft() != nullptr)
        return x->getLeft();
    else
        return x->getRight();
}

template<typename K, typename V>
Node<K, V>* RBTree<K, V>::parentf(Node<K, V>* u)
{
    if (u->getKey() == this->root->getKey())
        return nullptr;
    else
    {
        auto t = this->root;

        while (true)
        {
            if (t->getRight() != nullptr && t->getRight()->getKey() == u->getKey())
                break;

            if (t->getLeft() != nullptr && t->getLeft()->getKey() == u->getKey())
                break;

            if (t->getKey() > u->getKey())
                t = t->getLeft();
            else
                t = t->getRight();
        }
    }
}

template<typename K, typename V>
bool isOnLeft(Node<K, V>* t)
{
    return (t == t->parent->getLeft());
}

template<typename K, typename V>
bool hasRedChild(Node<K, V>* n) {
    return (n->getLeft() != NULL && n->getLeft()->getColor() == RED) ||
        (n->getRight() != NULL && n->getRight()->getColor() == RED);
}

template<typename K, typename V>
void RBTree<K, V>::fixDoubleBlack(Node<K, V>* x) {
    if (x == root)
        // Reached root
        return;

    Node<K, V>* sibling = x->sibling(), * parent = parentf(x);
    if (sibling == NULL) {
        // No sibiling, double black pushed up
        fixDoubleBlack(parent);
    }
    else {
        if (sibling->getColor() == RED) {
            // Sibling red
            parent->setColor(RED);
            sibling->setColor(BLACK);
            if (isOnLeft(sibling)) {
                // left case
                rotate_right(parent);
            }
            else {
                // right case
                rotate_left(parent);
            }
            fixDoubleBlack(x);
        }
        else {
            // Sibling black
            if (hasRedChild(sibling)) {
                // at least 1 red children
                if (sibling->getLeft() != NULL && sibling->getLeft()->getColor() == RED) {
                    if (isOnLeft(sibling)) {
                        // left left
                        sibling->getLeft()->setColor(sibling->getColor());
                        sibling->setColor(parent->getColor());
                        rotate_right(parent);
                    }
                    else {
                        // right left
                        sibling->getLeft()->setColor(parent->getColor());
                        rotate_right(sibling);
                        rotate_left(parent);
                    }
                }
                else {
                    if (isOnLeft(sibling)) {
                        // left right
                        sibling->getRight()->setColor(parent->color);
                        rotate_left(sibling);
                        rotate_right(parent);
                    }
                    else {
                        // right right
                        sibling->getRight()->setColor(sibling->color);
                        sibling->setColor(parent->color);
                        rotate_left(parent);
                    }
                }
                parent->setColor(BLACK);
            }
            else {
                // 2 black children
                sibling->setColor(RED);
                if (parent->getColor() == BLACK)
                    fixDoubleBlack(parent);
                else
                    parent->setColor(BLACK);
            }
        }
    }
}

template<typename K, typename V>
Node<K, V>* sibling(Node<K, V>* t) {
    // sibling null if no parent
    if (t->parent == NULL)
        return NULL;

    if (isOnLeft(t))
        return t->parent->getRight();

    return t->parent->getLeft();
}

template<typename K, typename V>
void swapValues(Node<K, V>* u, Node<K, V>* v) {
    int temp;
    temp = u->getValue();
    u->setValue(v->getValue());
    v->setValue(temp);
}

template<typename K, typename V>
void RBTree<K, V>::deleteNode(Node<K, V>* v) {
    auto u = BSTreplace(v);

    // True when u and v are both black
    bool uvBlack = ((u == NULL || u->getColor() == BLACK) && (v->getColor() == BLACK));
    auto parent = parentf(v);

    if (u == NULL) {
        // u is NULL therefore v is leaf
        if (v == root) {
            // v is root, making root null
            root = NULL;
        }
        else {
            if (uvBlack) {
                // u and v both black
                // v is leaf, fix double black at v
                fixDoubleBlack(v);
            }
            else {
                // u or v is red
                if (sibling(v) != NULL)
                    // sibling is not null, make it red"
                    sibling(v)->setColor(RED);
            }

            // delete v from the tree
            if (isOnLeft(v)) {
                parent->setLeft(NULL);
            }
            else {
                parent->setRight(NULL);
            }
        }
        delete v;
        return;
    }

    if (v->getLeft() == NULL || v->getRight() == NULL) {
        // v has 1 child
        if (v == root) {
            // v is root, assign the value of u to v, and delete u
            v->setValue(u->getValue());
            v->setLeft(NULL);
            v->setRight(NULL);
            delete u;
        }
        else {
            // Detach v from tree and move u up
            if (isOnLeft(v)) {
                parent->setLeft(u);
            }
            else {
                parent->setRight(u);
            }
            delete v;
            u->parent = parent;
            if (uvBlack) {
                // u and v both black, fix double black at u
                fixDoubleBlack(u);
            }
            else {
                // u or v red, color u black
                u->setColor(BLACK);
            }
        }
        return;
    }

    // v has 2 children, swap values with successor and recurse
    swapValues(u, v);
    deleteNode(u);
}

template<typename K, typename V>
bool RBTree<K, V>::removeNodeByKey(K key) {
    
    auto v = this->root;

    while (v->getKey() != key)
        if (v->getKey() > key)
            v = v->getLeft();
        else
            v = v->getRight();

    deleteNode(v);
   
    return true;
    
}

template<typename K, typename V>
void RBTree<K, V>::delete_case1(Node<K, V> *n) {
    if (n->parent != nullptr) {
        delete_case2(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::delete_case2(Node<K, V> *n) {
    Node<K, V> *s = n->sibling();

    if (s->color == 'r') {
        n->parent->color = 'r';
        s->color = 'b';
        if (n == n->parent->left)
            rotate_left(n->parent);
        else
            rotate_right(n->parent);
    }
    delete_case3(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case3(Node<K, V> *n) {
    Node<K, V> *s = n->sibling();

    if ((n->parent->color == 'b') &&
        (s->color == 'b') &&
        (s->left->color == 'b') &&
        (s->right->color == 'b')) {
        s->color = 'r';
        delete_case1(n->parent);
    } else
        delete_case4(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case4(Node<K, V> *n) {
    Node<K, V> *s = n->sibling();

    if ((n->parent->color == 'r') &&
        (s->color == 'b') &&
        (s->left->color == 'b') &&
        (s->right->color == 'b')) {
        s->color = 'r';
        n->parent->color = 'b';
    } else
        delete_case5(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case5(Node<K, V> *n) {
    Node<K, V> *s = n->sibling();


    if (s->color == 'b') { /* this if statement is trivial,
due to case 2 (even though case 2 changed the sibling to a sibling's child,
the sibling's child can't be red, since no red parent can have a red child). */
/* the following statements just force the red to be on the left of the left of the parent,
   or right of the right, so case six will rotate correctly. */
        if ((n == n->parent->left) &&
            (s->right->color == 'b') &&
            (s->left->color == 'r')) { /* this last test is trivial too due to cases 2-4. */
            s->color = 'r';
            s->left->color = 'b';
            rotate_right(s);
        } else if ((n == n->parent->right) &&
                   (s->left->color == 'b') &&
                   (s->right->color == 'r')) {/* this last test is trivial too due to cases 2-4. */
            s->color = 'r';
            s->right->color = 'b';
            rotate_left(s);
        }
    }
    delete_case6(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case6(Node<K, V> *n) {
    Node<K, V> *s = n->sibling();
    s->color = n->parent->color;
    n->parent->color = 'b';

    if (n == n->parent->left) {
        s->right->color = 'b';
        rotate_left(n->parent);
    } else {
        s->left->color = 'b';
        rotate_right(n->parent);
    }
}

template
class RBTree<int, int>;

template
class RBTree<unsigned long long, int>;