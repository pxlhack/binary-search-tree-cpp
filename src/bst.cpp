//
// Created by pxlhack on 06.11.22.
//

#include "../lib/bst.h"
#include <iostream>

typedef unsigned long long INT_64;

template<typename K, typename V>
BST<K, V>::BST() {
    this->root = nullptr;
    this->size = 0;
    this->nodes_counter = 0;
}

template<typename K, typename V>
BST<K, V>::BST(BST &bst) {
    BST();

    std::stack<Node<K, V>> stack;
    stack.push(*bst.root);

    while (!stack.empty()) {
        Node curNode = stack.top();
        stack.pop();

        this->put(curNode.getKey(), curNode.getValue());

        if (curNode.getRight() != nullptr) {
            stack.push(*curNode.getRight());
        }

        if (curNode.getLeft() != nullptr) {
            stack.push(*curNode.getLeft());
        }
    }

}

template<typename K, typename V>
BST<K, V>::~BST() {
    //todo
}

template<typename K, typename V>
bool BST<K, V>::put(K key, V value) {
    nodes_counter = 0;
    auto *newNode = new Node<K, V>();
    newNode->setKey(key);
    newNode->setValue(value);

    if (this->root == nullptr) {
        this->root = new Node(key, value);
        this->size = 1;
        nodes_counter++;
        return true;
    } else {
        Node<K, V> *curNode = this->root;
        Node<K, V> *pred;
        nodes_counter++;
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

            nodes_counter++;

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
bool BST<K, V>::removeNodeByKey(K key) {
    nodes_counter = 0;

    Node<K, V> *curNode = this->root;
    Node<K, V> *pred;
    while (curNode != nullptr && curNode->getKey() != key) {
        pred = curNode;
        if (key < curNode->getKey()) {
            curNode = curNode->getLeft();
        } else {
            curNode = curNode->getRight();
        }
        nodes_counter++;
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
            nodes_counter++;
            flag = false;
        } else {
            if (curNode->getRight() == nullptr) {
                x = curNode->getLeft();
                nodes_counter++;
                flag = false;
            }
        }
        if (flag) {
            pred = curNode;
            Node<K, V> *y = curNode->getRight();
            while (y->getLeft() != nullptr) {
                pred = y;
                y = y->getLeft();
                nodes_counter++;
            }
            curNode->setKey(y->getKey());
            curNode->setValue(y->getValue());
            nodes_counter += 2;
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
V BST<K, V>::getValueByKey(K key) {
    nodes_counter = 0;
    if (key == this->root->getKey()) {
        return this->root->getValue();
    }
    Node<K, V> *curNode = this->root;
    while (curNode != nullptr && key != curNode->getKey()) {
        nodes_counter++;
        if (key == curNode->getKey()) {
            return curNode->getValue();
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
int BST<K, V>::getSize() {
    return this->size;
}

template<typename K, typename V>
bool BST<K, V>::isEmpty() {
    return this->size == 0;
}

template<typename K, typename V>
bool BST<K, V>::setValueForKey(V value, K key) {
    if (isEmpty()) return false;

    if (key == root->getKey()) {
        root->setValue(value);
        return true;
    }

    Node<K, V> *node;
    node = getNodeByKey(key);


    if (node != nullptr) {
        node->setValue(value);
        return true;
    }
    return false;
}


template<typename K, typename V>
void BST<K, V>::clear() {
    if (root != nullptr) {
        std::stack<Node<K, V>> stack;
        stack.push(*(this->root));

        while (!stack.empty()) {
            Node curNode = stack.top();
            stack.pop();

            removeNodeByKey(curNode.getKey());

            if (curNode.getRight() != nullptr) {
                stack.push(*curNode.getRight());
            }

            if (curNode.getLeft() != nullptr) {
                stack.push(*curNode.getLeft());
            }
        }
        this->root = nullptr;
        this->size = 0;
    }

}

template<typename K, typename V>
int BST<K, V>::getTreeNodesCountViewedByPreviousOperation() {
    return nodes_counter;
}

template<typename K, typename V>
Node<K, V> *BST<K, V>::getNodeByKey(K key) {
    Node<K, V> *node = nullptr, *curNode = this->root;

    while (curNode != nullptr && key != curNode->getKey()) {
        if (key == curNode->getKey()) {
            node = curNode;
        }

        if (key < curNode->getKey()) {
            curNode = curNode->getLeft();
        }

        if (key > curNode->getKey()) {
            curNode = curNode->getRight();
        }

    }
    return node;
}


template
class BST<int, int>;

template<>
string BST<int, int>::getStringOfKeys() {
    string keysList;

    if (this->root != nullptr) {
        std::stack<Node<int, int>> stack;
        stack.push(*(this->root));
        while (!stack.empty()) {
            Node curNode = stack.top();
            stack.pop();

            std::ostringstream strs;
            strs << curNode.getKey();
            std::string str = strs.str();
            keysList += strs.str();
            keysList += " ";

            if (curNode.getRight() != nullptr) {
                stack.push(*curNode.getRight());
            }

            if (curNode.getLeft() != nullptr) {
                stack.push(*curNode.getLeft());
            }
        }
    }
    return keysList;
}

template<>
void BST<int, int>::showKeysList() {
    cout << this->getStringOfKeys() << endl;
}

template<>
string BST<int, int>::getStringOfValues() {
    string valuesList;

    if (root == nullptr) {
        return " ";
    }


    std::stack<Node<int, int>> stack;
    stack.push(*(this->root));
    while (!stack.empty()) {
        Node curNode = stack.top();
        stack.pop();

        stringstream ss;
        ss << curNode.getValue();
        valuesList += ss.str();
        valuesList += " ";

        if (curNode.getRight() != nullptr) {
            stack.push(*curNode.getRight());
        }

        if (curNode.getLeft() != nullptr) {
            stack.push(*curNode.getLeft());
        }
    }

    return valuesList;
}

template<>
void BST<int, int>::showValuesList() {
    cout << getStringOfValues() << endl;
}

template<typename K, typename V>
int BST<K, V>::nodesCountWithKeysMoreThan(K key) {
    int count = 0;

    if (this->root != nullptr) {
        std::stack<Node<K, V>> stack;
        stack.push(*(this->root));
        while (!stack.empty()) {
            Node curNode = stack.top();

            stack.pop();

            if (curNode.getKey() > key) {
                count++;
            }


            if (curNode.getRight() != nullptr) {
                stack.push(*curNode.getRight());
            }

            if (curNode.getLeft() != nullptr) {
                stack.push(*curNode.getLeft());
            }
        }
    }

    return count;
}


template<typename K, typename V>
TreeIterator<K, V> BST<K, V>::begin() {
    return TreeIterator<K, V>(root, 0);
}

template<typename K, typename V>
TreeIterator<K, V> BST<K, V>::end() {
    return TreeIterator<K, V>(root, -1);
}


template<typename K, typename V>
RTreeIterator<K, V> BST<K, V>::rbegin() {
    return RTreeIterator<K, V>(root, size-1);
}

template<typename K, typename V>
RTreeIterator<K, V> BST<K, V>::rend() {
    return RTreeIterator<K, V>(root, -1);
}

template
class BST<INT_64, int>;