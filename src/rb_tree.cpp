#include "../lib/rb_tree.h"

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

    insert_repair_tree(n);

    root = n;
    while (root->getParent() != nullptr) {
        root = root->getParent();
    }
    return root;
}

template<typename K, typename V>
void RBTree<K, V>::insert_repair_tree(Node<K, V> *n) {
    if (n->getParent() == nullptr) {
        insert_case1(n);
    } else if (n->getParent()->getColor() == BLACK) {
        insert_case2(n);
    } else if (uncle(n)->getColor() == RED) {
        insert_case3(n);
    } else {
        insert_case4(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::insert_case1(Node<K, V> *n) {
    if (n->getParent() == nullptr) {
        n->setColor(BLACK);
    }
}

template<typename K, typename V>
void RBTree<K, V>::insert_case2(Node<K, V> *n) {
}

template<typename K, typename V>
void RBTree<K, V>::insert_case3(Node<K, V> *n) {
    n->getParent()->setColor(BLACK);
    uncle(n)->setColor(BLACK);
    grandparent(n)->setColor(RED);
    insert_repair_tree(grandparent(n));
}

template<typename K, typename V>
void RBTree<K, V>::insert_case4(Node<K, V> *n) {
    Node<K, V> *parent = n->getParent();
    Node<K, V> *g = grandparent(n);

    if (n == g->getLeft()->getRight()) {
        rotate_left(parent);
        n = n->getLeft();
    } else if (n == g->getRight()->getLeft()) {
        rotate_right(parent);
        n = n->getRight();
    }

    insert_case4step2(n);
}

template<typename K, typename V>
void RBTree<K, V>::insert_case4step2(Node<K, V> *n) {
    Node<K, V> *parent = n->getParent();
    Node<K, V> *g = grandparent(n);

    if (n == parent->getLeft()) {
        rotate_right(g);
    } else {
        rotate_left(g);
    }
    parent->setColor(BLACK);
    g->setColor(RED);
}

template<typename K, typename V>
void RBTree<K, V>::rotate_left(Node<K, V> *n) {
    Node<K, V> *p = n->getParent();

    Node<K, V> *nnew = n->getRight();
    n->setRight(nnew->getLeft());
    nnew->setLeft(n);
    n->setParent(nnew);

    // handle other child/parent pointers
    if (n->getRight() != nullptr) {
        n->getRight()->setParent(n);
    }

    if (p != nullptr) // initially n could be the root
    {
        if (n == p->getLeft()) {
            p->setLeft(nnew);
        } else if (n == p->getRight()) {
            p->setRight(nnew);
        }
    }
    nnew->setParent(p);
}

template<typename K, typename V>
void RBTree<K, V>::rotate_right(Node<K, V> *n) {
    Node<K, V> *nnew = n->getLeft();
    Node<K, V> *p = n->getParent();

    //fixme
    // assert(nnew != NULL); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->setLeft(nnew->getRight());
    nnew->setRight(n);
    n->setParent(nnew);
    // handle other child/parent pointers
    if (n->getLeft() != nullptr) {
        n->getLeft()->setParent(n);

    }
    if (p != nullptr) // initially n could be the root
    {
        if (n == p->getLeft())
            p->setLeft(nnew);
        else if (n == p->getRight()) {
            p->setRight(nnew);
        }

    }
    nnew->setParent(p);
}

template<typename K, typename V>
void RBTree<K, V>::insert_recurse(Node<K, V> *root, Node<K, V> *n) {
    if (root != nullptr && n->getKey() < root->getKey()) {
        if (!(isLeaf(root->getLeft()))) {
            insert_recurse(root->getLeft(), n);
            return;
        } else {
            root->setLeft(n);
        }
    } else if (root != nullptr) {
        if (!(isLeaf(root->getRight()))) {
            insert_recurse(root->getRight(), n);
            return;
        } else {
            root->setRight(n);
        }
    }

    // insert new n n
    n->setParent(root);
    n->setLeft(new Node<K, V>());
    leaf(n->getLeft());
    n->setRight(new Node<K, V>());
    leaf(n->getRight());
    n->setColor(RED);
}

template<typename K, typename V>
bool isOnLeft(Node<K, V> *t) {
    return (t == t->getParent()->getLeft());
}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::sibling(Node<K, V> *t) {
    if (t->getParent() == nullptr)
        return nullptr;

    if (isOnLeft(t))
        return t->getParent()->getRight();

    return t->getParent()->getLeft();
}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::grandparent(Node<K, V> *t) {
    Node<K, V> *p = t->getParent();
    if (p == nullptr) {
        return nullptr;
    }
    return p->getParent();
}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::uncle(Node<K, V> *t) {

    Node<K, V> *p = t->getParent();
    Node<K, V> *g = grandparent(t);
    if (g == nullptr) {
        return nullptr;
    }
    return sibling(p);

}

template<typename K, typename V>
bool RBTree<K, V>::removeNodeByKey(K key) {
    try {
        Node<K, V> *n = search(this->root, key);
        Node<K, V> *child = isLeaf(n->getRight()) ? n->getLeft() : n->getRight();

        replaceNode(n, child);
        if (n->getColor() == BLACK) {
            if (child->getColor() == RED) {
                child->setColor(BLACK);
            } else {
                delete_case1(child);
            }
        }
        delete n;
        return true;
    }
    catch (const char *c) {
        cout << c << endl;
    }
    return false;
}

template<typename K, typename V>
void RBTree<K, V>::delete_case1(Node<K, V> *n) {
    if (n->getParent() != nullptr) {
        delete_case2(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::delete_case2(Node<K, V> *n) {
    Node<K, V> *s = sibling(n);

    if (s->getColor() == RED) {
        n->getParent()->setColor(RED);
        s->setColor(BLACK);
        if (n == n->getParent()->getLeft())
            rotate_left(n->getParent());
        else
            rotate_right(n->getParent());
    }
    delete_case3(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case3(Node<K, V> *n) {
    Node<K, V> *s = sibling(n);

    if ((n->getParent()->getColor() == BLACK) &&
        (s->getColor() == BLACK) &&
        (s->getLeft()->getColor() == BLACK) &&
        (s->getRight()->getColor() == BLACK)) {
        s->setColor(RED);
        delete_case1(n->getParent());
    } else {
        delete_case4(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::delete_case4(Node<K, V> *n) {
    Node<K, V> *s = sibling(n);

    if ((n->getParent()->getColor() == RED) &&
        (s->getColor() == BLACK) &&
        (s->getLeft()->getColor() == BLACK) &&
        (s->getRight()->getColor() == BLACK)) {
        s->setColor(RED);
        n->getParent()->setColor(BLACK);
    } else
        delete_case5(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case5(Node<K, V> *n) {
    Node<K, V> *s = sibling(n);

    if (s->getColor() == 'b') {
        /*this
        if statement
            is trivial,
                    due
            to
            case 2(even though
            case 2 changed
                        the
                sibling
                        to
                a
                        sibling
                's child,
        the
                sibling
        's child can't
        be
                red, since
        no
                red
        parent
                can
        have
                a
        red
        child).
        the
        following
                statements
        just
                force
        the
                red
        to
                be
        on
                the
        left
                of
        the
                left
        of
                the
        parent,
        or right
                of
        the
                right, so
        case six will
                    rotate
            correctly.*/
        if ((n == n->getParent()->getLeft()) &&
            (s->getRight()->getColor() == 'b') &&
            (s->getLeft()->getColor() == 'r')) {
            /*this
            last
                    test
            is
                    trivial
            too
                    due
            to
                    cases
            2 - 4.*/
            s->setColor(RED);
            s->getLeft()->setColor(BLACK);
            rotate_right(s);
        } else if ((n == n->getParent()->getRight()) &&
                   (s->getLeft()->getColor() == BLACK) &&
                   (s->getRight()->getColor() == RED)) {
            /*this
            last
                    test
            is
                    trivial
            too
                    due
            to
                    cases
            2 - 4.*/
            s->setColor(RED);
            s->getRight()->setColor(BLACK);
            rotate_left(s);
        }
    }
    delete_case6(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case6(Node<K, V> *n) {
    Node<K, V> *s = sibling(n);
    s->setColor(n->getParent()->getColor());
    n->getParent()->setColor(BLACK);

    if (n == n->getParent()->getLeft()) {
        s->getRight()->setColor(BLACK);
        rotate_left(n->getParent());
    } else {
        s->getLeft()->setColor(BLACK);
        rotate_right(n->getParent());
    }
}

template<typename K, typename V>
bool RBTree<K, V>::isLeaf(Node<K, V> *t) {
    return (t->getLeft() == nullptr && t->getRight() == nullptr && t->getColor() == BLACK);
}

template<typename K, typename V>
Node<K, V> *RBTree<K, V>::search(Node<K, V> *temp, K key) {
    int diff;
    Node<K, V> *tmp = temp;
    while (!isLeaf(tmp)) {
        diff = key - tmp->getKey();
        if (diff > 0) {
            tmp = tmp->getRight();
        } else if (diff < 0) {
            tmp = tmp->getLeft();
        } else {
            return tmp;
        }
    }
    throw "not found!";
}

template<typename K, typename V>
void RBTree<K, V>::replaceNode(Node<K, V> *n, Node<K, V> *child) {
    child->setParent(n->getParent());
    if (n == n->getParent()->getLeft()) {
        n->getParent()->setLeft(child);
    } else {
        n->getParent()->setRight(child);
    }
}

template<typename K, typename V>
void RBTree<K, V>::nodePrint(Node<K, V> *tmp, int n) {
    if (tmp != nullptr) {
        nodePrint(tmp->getRight(), n + 5);

        for (int i = 0; i < n; i++)
            cout << " ";
        cout << "[" << tmp->getKey() << "-" << tmp->getColor() << "]" << endl;
        nodePrint(tmp->getLeft(), n + 5);
    }
}

template<typename K, typename V>
void RBTree<K, V>::print() {
    nodePrint(this->root, 0);
}

template<typename K, typename V>
void RBTree<K, V>::leaf(Node<K, V> *t) {
    t->setRight(nullptr);
    t->setLeft(nullptr);
    t->setParent(nullptr);
    t->setColor(BLACK);
}

template
class RBTree<int, int>;

template
class RBTree<unsigned long long, int>;