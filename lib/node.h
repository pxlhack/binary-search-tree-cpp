#ifndef MY_BINARY_SEARCH_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_NODE_H

#include <iostream>

using namespace std;

template<typename K, typename V>
class Node {
public:
    Node() {
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
        color = 'r';
    }

    Node(K key, V value) {
        this->key = key;
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
        color = 'r';
    }

    void leaf() {
        this->right = nullptr;
        this->left = nullptr;
        this->parent = nullptr;
        color = 'b';
    }

    K getKey() const {
        return key;
    }

    void setKey(K key) {
        Node::key = key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        Node::value = value;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    void changeColor() {
        color = color == 'r' ? 'b' : 'r';
    }

    char getColor() {
        return color;
    }

    void setColor(char c) {
        color = c;
    }

    Node *right, *left, *parent;
    K key;
    V value;
    char color;

    Node *grandparent() {
        Node *p = this->parent;
        if (p == NULL)
            return NULL; // No parent means no grandparent
        return p->parent; // NULL if parent is root
    }

    Node *subling() {
        Node *p = this->parent;
        if (p == NULL)
            return NULL; // No parent means no sibling
        if (this == p->left)
            return p->right;
        else
            return p->left;
    }

    Node *uncle() {
        Node *p = this->parent;
        Node *g = grandparent();
        if (g == NULL)
            return NULL; // No grandparent means no uncle
        return p->subling();
    }

    bool isLeaf() {
        return (this->left == nullptr && this->right == nullptr && this->color == 'b');
    }


};

template<typename K, typename V>
void pr(Node<K, V> *tmp, int n = 0) {
    if (tmp != NULL) {
        pr(tmp->getRight(), n + 5);

        for (int i = 0; i < n; i++)
            cout << " ";
        cout << tmp->getKey() << endl;
        pr(tmp->getLeft(), n + 5);
    }
}

#endif //MY_BINARY_SEARCH_TREE_NODE_H
