#include "../lib/rb_tree.h"

template<typename K, typename V>
RBTree<K, V>::RBTree() {

}

template<typename K, typename V>
bool RBTree<K, V>::put(K key, V value) {
    this->nodes_counter = 0;
    auto *node = new RBTreeNode<K, V>(key, value);
    this->root = insert(this->root, node);
    this->nodes_counter++;
    this->size++;
    return true;
}

template<typename K, typename V>
RBTreeNode<K, V> *RBTree<K, V>::insert(RBTreeNode<K, V> *root, RBTreeNode<K, V> *n) {
    insert_recurse(root, n);

    insert_repair_tree(n);

    root = n;
    while (root->getParent() != nullptr) {
        root = root->getParent();
        this->nodes_counter++;
    }
    return root;
}

template<typename K, typename V>
void RBTree<K, V>::insert_repair_tree(RBTreeNode<K, V> *n) {
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
void RBTree<K, V>::insert_case1(RBTreeNode<K, V> *n) {
    if (n->getParent() == nullptr) {
        n->setColor(BLACK);
        this->nodes_counter++;
    }
}

template<typename K, typename V>
void RBTree<K, V>::insert_case2(RBTreeNode<K, V> *n) {
}

template<typename K, typename V>
void RBTree<K, V>::insert_case3(RBTreeNode<K, V> *n) {
    n->getParent()->setColor(BLACK);
    uncle(n)->setColor(BLACK);
    grandparent(n)->setColor(RED);
    this->nodes_counter += 2;
    insert_repair_tree(grandparent(n));
}

template<typename K, typename V>
void RBTree<K, V>::insert_case4(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *parent = n->getParent();
    RBTreeNode<K, V> *g = grandparent(n);

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
void RBTree<K, V>::insert_case4step2(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *parent = n->getParent();
    RBTreeNode<K, V> *g = grandparent(n);

    if (n == parent->getLeft()) {
        rotate_right(g);
    } else {
        rotate_left(g);
    }
    parent->setColor(BLACK);
    g->setColor(RED);
    this->nodes_counter += 2;
}

template<typename K, typename V>
void RBTree<K, V>::rotate_left(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *p = n->getParent();

    RBTreeNode<K, V> *nnew = n->getRight();
    n->setRight(nnew->getLeft());
    nnew->setLeft(n);
    n->setParent(nnew);
    this->nodes_counter += 4;

    if (n->getRight() != nullptr) {
        n->getRight()->setParent(n);
        this->nodes_counter += 2;
    }

    if (p != nullptr)
    {
        if (n == p->getLeft()) {
            p->setLeft(nnew);
            this->nodes_counter++;
        } else if (n == p->getRight()) {
            p->setRight(nnew);
            this->nodes_counter++;
        }
    }
    nnew->setParent(p);
    this->nodes_counter++;
}

template<typename K, typename V>
void RBTree<K, V>::rotate_right(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *nnew = n->getLeft();
    RBTreeNode<K, V> *p = n->getParent();

    n->setLeft(nnew->getRight());
    nnew->setRight(n);
    n->setParent(nnew);
    this->nodes_counter += 4;
    if (n->getLeft() != nullptr) {
        n->getLeft()->setParent(n);
        this->nodes_counter += 2;

    }
    if (p != nullptr)
    {
        if (n == p->getLeft()) {
            p->setLeft(nnew);
            this->nodes_counter++;
        }
        else if (n == p->getRight()) {
            p->setRight(nnew);
            this->nodes_counter++;
        }

    }
    nnew->setParent(p);
    this->nodes_counter++;
}

template<typename K, typename V>
void RBTree<K, V>::insert_recurse(RBTreeNode<K, V> *root, RBTreeNode<K, V> *n) {
    if (root != nullptr && n->getKey() < root->getKey()) {
        if (!(isLeaf(root->getLeft()))) {
            insert_recurse(root->getLeft(), n);
            return;
        } else {
            root->setLeft(n);
            this->nodes_counter++;
        }
    } else if (root != nullptr) {
        if (!(isLeaf(root->getRight()))) {
            insert_recurse(root->getRight(), n);
            return;
        } else {
            root->setRight(n);
            this->nodes_counter++;
        }
    }

    // insert new n n
    this->nodes_counter++;
    n->setParent(root);
    n->setLeft(new RBTreeNode<K, V>());
    leaf(n->getLeft());
    n->setRight(new RBTreeNode<K, V>());
    leaf(n->getRight());
    n->setColor(RED);
}

template<typename K, typename V>
bool isOnLeft(RBTreeNode<K, V> *t) {
    return (t == t->getParent()->getLeft());
}

template<typename K, typename V>
RBTreeNode<K, V> *RBTree<K, V>::sibling(RBTreeNode<K, V> *t) {
    if (t->getParent() == nullptr)
        return nullptr;

    if (isOnLeft(t))
        return t->getParent()->getRight();

    return t->getParent()->getLeft();
}

template<typename K, typename V>
RBTreeNode<K, V> *RBTree<K, V>::grandparent(RBTreeNode<K, V> *t) {
    RBTreeNode<K, V> *p = t->getParent();
    if (p == nullptr) {
        return nullptr;
    }
    return p->getParent();
}

template<typename K, typename V>
RBTreeNode<K, V> *RBTree<K, V>::uncle(RBTreeNode<K, V> *t) {

    RBTreeNode<K, V> *p = t->getParent();
    RBTreeNode<K, V> *g = grandparent(t);
    if (g == nullptr) {
        return nullptr;
    }
    return sibling(p);

}

template<typename K, typename V>
bool RBTree<K, V>::removeNodeByKey(K key) {
    try {
        RBTreeNode<K, V> *n = search(this->root, key);
        RBTreeNode<K, V> *child = isLeaf(n->getRight()) ? n->getLeft() : n->getRight();

        replaceNode(n, child);
        if (n->getColor() == BLACK) {
            if (child->getColor() == RED) {
                this->nodes_counter++;
                child->setColor(BLACK);
            } else {
                delete_case1(child);
            }
        }
        delete n;
        this->size--;
        return true;
    }
    catch (const char *c) {
        cout << c << endl;
    }
    return false;
}

template<typename K, typename V>
void RBTree<K, V>::delete_case1(RBTreeNode<K, V> *n) {
    if (n->getParent() != nullptr) {
        delete_case2(n);
    }
}

template<typename K, typename V>
void RBTree<K, V>::delete_case2(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *s = sibling(n);

    if (s->getColor() == RED) {
        this->nodes_counter++;
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
void RBTree<K, V>::delete_case3(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *s = sibling(n);

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
void RBTree<K, V>::delete_case4(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *s = sibling(n);

    if ((n->getParent()->getColor() == RED) &&
        (s->getColor() == BLACK) &&
        (s->getLeft()->getColor() == BLACK) &&
        (s->getRight()->getColor() == BLACK)) {
        this->nodes_counter += 2;
        s->setColor(RED);
        n->getParent()->setColor(BLACK);
    } else
        delete_case5(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case5(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *s = sibling(n);

    if (s->getColor() == 'b') {
        if ((n == n->getParent()->getLeft()) &&
            (s->getRight()->getColor() == 'b') &&
            (s->getLeft()->getColor() == 'r')) {
            this->nodes_counter += 2;
            s->setColor(RED);
            s->getLeft()->setColor(BLACK);
            rotate_right(s);
        } else if ((n == n->getParent()->getRight()) &&
                   (s->getLeft()->getColor() == BLACK) &&
                   (s->getRight()->getColor() == RED)) {
            this->nodes_counter += 2;
            s->setColor(RED);
            s->getRight()->setColor(BLACK);
            rotate_left(s);
        }
    }
    delete_case6(n);
}

template<typename K, typename V>
void RBTree<K, V>::delete_case6(RBTreeNode<K, V> *n) {
    RBTreeNode<K, V> *s = sibling(n);
    s->setColor(n->getParent()->getColor());
    n->getParent()->setColor(BLACK);

    if (n == n->getParent()->getLeft()) {
        s->getRight()->setColor(BLACK);
        rotate_left(n->getParent());
    } else {
        s->getLeft()->setColor(BLACK);
        rotate_right(n->getParent());
    }

    this->nodes_counter += 4;
}

template<typename K, typename V>
bool RBTree<K, V>::isLeaf(RBTreeNode<K, V> *t) {
    this->nodes_counter += 2;
    return (t->getLeft() == nullptr && t->getRight() == nullptr && t->getColor() == BLACK);
}

template<typename K, typename V>
RBTreeNode<K, V> *RBTree<K, V>::search(RBTreeNode<K, V> *temp, K key) {
    int diff;
    RBTreeNode<K, V> *tmp = temp;
    while (!isLeaf(tmp)) {
        diff = key - tmp->getKey();
        if (diff > 0) {
            tmp = tmp->getRight();
        } else if (diff < 0) {
            tmp = tmp->getLeft();
        } else {
            return tmp;
        }
        this->nodes_counter++;
    }
    throw "not found!";
}

template<typename K, typename V>
void RBTree<K, V>::replaceNode(RBTreeNode<K, V> *n, RBTreeNode<K, V> *child) {
    child->setParent(n->getParent());
    this->nodes_counter++;
    if (n == n->getParent()->getLeft()) {
        n->getParent()->setLeft(child);
    } else {
        n->getParent()->setRight(child);
    }

    this->nodes_counter += 2;
}

template<typename K, typename V>
void RBTree<K, V>::nodePrint(RBTreeNode<K, V> *tmp, int n) {
    if (tmp != nullptr) {
        nodePrint(tmp->getRight(), n + 5);

        for (int i = 0; i < n; i++)
            cout << " ";
        cout << "[" << tmp->getKey() << "-" << tmp->getColor() << "]" << endl;
        this->nodes_counter++;
        nodePrint(tmp->getLeft(), n + 5);
    }
}

template<typename K, typename V>
void RBTree<K, V>::print() {
    this->nodes_counter = 0;
    nodePrint(this->root, 0);
}

template<typename K, typename V>
void RBTree<K, V>::leaf(RBTreeNode<K, V> *t) {
    t->setRight(nullptr);
    t->setLeft(nullptr);
    t->setParent(nullptr);
    t->setColor(BLACK);
    this->nodes_counter++;
}

template<typename K, typename V>
V RBTree<K, V>::getValueByKey(K key) {
    this->nodes_counter = 0;
    if (key == this->root->getKey()) {
        this->nodes_counter++;
        return this->root->getValue();
    }
    RBTreeNode<K, V> *curNode = this->root;
    this->nodes_counter++;
    while (curNode != nullptr && key != curNode->getKey()) {
        if (key == curNode->getKey()) {
            return curNode->getValue();
        }

        if (key < curNode->getKey()) {
            curNode = curNode->getLeft();
        } else {
            curNode = curNode->getRight();
        }
        this->nodes_counter++;
    }
    if (curNode != nullptr) {
        this->nodes_counter++;
        return curNode->getValue();
    } else {
        throw "not found!";
    }
}

template
class RBTree<int, int>;

template
class RBTree<unsigned long long, int>;