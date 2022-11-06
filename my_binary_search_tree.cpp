//
// Created by pxlhack on 06.11.22.
//

#include "my_binary_search_tree.h"
#include <iostream>

template<typename K, typename V>
MyBinarySearchTree<K, V>::MyBinarySearchTree() {
    root = nullptr;
}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::put(K key, V value) {
    Node *newNode = new Node();
    newNode->setKey(key);
    newNode->setValue(value);

    if (root == nullptr) {
        root = new Node(key, value);
        return true;
    } else {
        Node *t = root;
        Node *pred;
        while (t != nullptr) {
            pred = t;
            if (key == t->getKey()) {
                return false;
            }

            if (key < t->getKey()) {
                t = t->getLeft();
            } else {
                t = t->getRight();
            }

        }
        if (key < pred->getKey()) {
            pred->setLeft(new Node(key, value));
        } else {
            pred->setRight(new Node(key, value));
        }
        return true;
    }

}

template<typename K, typename V>
MyBinarySearchTree<K, V>::~MyBinarySearchTree() {
}

template<typename K, typename V>
void MyBinarySearchTree<K, V>::showTree() {
    std::stack<Node> stack;
    stack.push(*root);
    while (!stack.empty()) {
        Node curNode = stack.top();
        stack.pop();
        cout << curNode.getKey() << " ";

        if (curNode.getRight() != nullptr) {
            stack.push(*curNode.getRight());
        }
        if (curNode.getLeft() != nullptr) {
            stack.push(*curNode.getLeft());
        }
    }
    cout << endl;

}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::remove(K k) {

    Node *t = root;
    Node *pred;
    while (t != nullptr && t->getKey() != k) {
        pred = t;
        if (k < t->getKey()) {
            t = t->getLeft();
        } else {
            t = t->getRight();
        }
    }
    if (t == nullptr) {
        return false;
    }


    Node *x;

    if (t->getLeft() == nullptr && t->getRight() == nullptr) {
        x = nullptr;

    } else {
        bool flag = true;
        if (t->getLeft() == nullptr) {
            x = t->getRight();
            flag = false;
        } else {
            if (t->getRight() == nullptr) {
                x = t->getLeft();
                flag = false;
            }
        }
        if (flag) {
            pred = t;
            Node *y = t->getRight();
            while (y->getLeft() != nullptr) {
                pred = y;
                y = y->getLeft();
            }
            t->setKey(y->getKey());
            t->setValue(y->getValue());
            x = y->getRight();
            t = y;
        }
    }

    if (pred == nullptr) {
        root = x;

    } else {
        if (t->getKey() < pred->getKey()) {
            pred->setLeft(x);
        } else {
            pred->setRight(x);
        }
    }

    return true;
}

template<typename K, typename V>
V MyBinarySearchTree<K, V>::get(K key) {
    if (key == root->getKey()) {
        return root->getValue();
    }
    Node *t = root;
    Node *pred;
    while (t != nullptr && key != t->getKey()) {
        pred = t;
        if (key == t->getKey()) {
            return false;
        }

        if (key < t->getKey()) {
            t = t->getLeft();
        } else {
            t = t->getRight();
        }

    }
    if (t != nullptr) {
        return t->getValue();
    }
}

template
class MyBinarySearchTree<int, int>;

template
class MyBinarySearchTree<double, int>;