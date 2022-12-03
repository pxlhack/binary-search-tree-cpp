#ifndef MY_BINARY_SEARCH_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_NODE_H

template<typename K, typename V>
class Node {
public:
    Node() {
        this->right = nullptr;
        this->left = nullptr;
        color = 'r';
    }

    Node(K key, V value) {
        this->key = key;
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
        color = 'r';
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


private:
    K key;
    V value;
    char color;
    Node *right, *left;
};

#endif //MY_BINARY_SEARCH_TREE_NODE_H
