//
// Created by pxlhack on 06.11.22.
//

#include "../lib/my_binary_search_tree.h"
#include <iostream>

template<typename K, typename V>
MyBinarySearchTree<K, V>::MyBinarySearchTree() {
    this->root = nullptr;
    this->size = 0;
}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::put(K key, V value) {
    Node<K, V> *newNode = new Node<K, V>();
    newNode->setKey(key);
    newNode->setValue(value);

    if (this->root == nullptr) {
        this->root = new Node(key, value);
        this->size = 1;
        return true;
    } else {
        Node<K, V> *curNode = this->root;
        Node<K, V> *pred;
        while (curNode != nullptr) {
            pred = curNode;
            if (key == curNode->getKey()) {
                return false;
            }

            if (key < curNode->getKey()) {
                curNode = curNode->getLeft();
            } else {
                curNode = curNode->getRight();
            }

        }
        if (key < pred->getKey()) {
            pred->setLeft(new Node(key, value));
        } else {
            pred->setRight(new Node(key, value));
        }
        this->size++;
        return true;
    }
}

template<typename K, typename V>
MyBinarySearchTree<K, V>::~MyBinarySearchTree() {

}

template<typename K, typename V>
void MyBinarySearchTree<K, V>::showKeyList() {
    if (this->root != nullptr) {
        std::stack<Node<K, V>> stack;
        stack.push(*(this->root));
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
    }
    cout << endl;
}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::remove(K k) {

    Node<K, V> *curNode = this->root;
    Node<K, V> *pred;
    while (curNode != nullptr && curNode->getKey() != k) {
        pred = curNode;
        if (k < curNode->getKey()) {
            curNode = curNode->getLeft();
        } else {
            curNode = curNode->getRight();
        }
    }
    if (curNode == nullptr) {
        return false;
    }


    Node<K, V> *x;

    if (curNode->getLeft() == nullptr && curNode->getRight() == nullptr) {
        x = nullptr;

    } else {
        bool flag = true;
        if (curNode->getLeft() == nullptr) {
            x = curNode->getRight();
            flag = false;
        } else {
            if (curNode->getRight() == nullptr) {
                x = curNode->getLeft();
                flag = false;
            }
        }
        if (flag) {
            pred = curNode;
            Node<K, V> *y = curNode->getRight();
            while (y->getLeft() != nullptr) {
                pred = y;
                y = y->getLeft();
            }
            curNode->setKey(y->getKey());
            curNode->setValue(y->getValue());
            x = y->getRight();
            curNode = y;
        }
    }

    if (pred != nullptr) {
        if (curNode->getKey() < pred->getKey()) {
            pred->setLeft(x);
        } else {
            pred->setRight(x);
        }
    }
    this->size--;
    return true;
}

template<typename K, typename V>
V MyBinarySearchTree<K, V>::get(K key) {
    if (key == this->root->getKey()) {
        return this->root->getValue();
    }
    Node<K, V> *curNode = this->root;
    while (curNode != nullptr && key != curNode->getKey()) {
        if (key == curNode->getKey()) {
            return false;
        }

        if (key < curNode->getKey()) {
            curNode = curNode->getLeft();
        } else {
            curNode = curNode->getRight();
        }

    }
    if (curNode != nullptr) {
        return curNode->getValue();
    } else {
        throw "not found!";
    }
}

template<typename K, typename V>
int MyBinarySearchTree<K, V>::getSize() {
    return this->size;
}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::isEmpty() {
    return this->size == 0;
}

template<typename K, typename V>
bool MyBinarySearchTree<K, V>::set(K key, V newValue) {
    bool isRemoved = this->remove(key);
    if (isRemoved) {
        return this->put(key, newValue);
    }
    return false;
}

template<typename K, typename V>
MyBinarySearchTree<K, V>::MyBinarySearchTree(MyBinarySearchTree &myBinarySearchTree) {
    MyBinarySearchTree();
    std::stack<Node<K, V>> stack;
    stack.push(*myBinarySearchTree.root);
    while (!stack.empty()) {
        Node curNode = stack.top();
        stack.pop();

        put(curNode.getKey(), curNode.getValue());

        if (curNode.getRight() != nullptr) {
            stack.push(*curNode.getRight());
        }

        if (curNode.getLeft() != nullptr) {
            stack.push(*curNode.getLeft());
        }
    }

}

template<typename K, typename V>
void MyBinarySearchTree<K, V>::clear() {
    std::stack<Node<K, V>> stack;
    stack.push(*(this->root));
    while (!stack.empty()) {
        Node curNode = stack.top();
        stack.pop();

        remove(curNode.getKey());

        if (curNode.getRight() != nullptr) {
            stack.push(*curNode.getRight());
        }

        if (curNode.getLeft() != nullptr) {
            stack.push(*curNode.getLeft());
        }
    }
    this->root = nullptr;
}


template
class MyBinarySearchTree<double, int>;

template
class MyBinarySearchTree<int, int>;