#ifndef MY_BINARY_SEARCH_TREE_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_TREE_NODE_H

template<typename K, typename V>
class Node {
public:
    Node() {
        this->right = nullptr;
        this->left = nullptr;
    }

    Node(K key, V value){
        Node();
        this->key = key;
        this->value = value;
    }

    K getKey() const {
        return key;
    }

    void setKey(K key) {
        this->key = key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        this->value = value;
    }

    Node* getRight() const {
        return right;
    }

    void setRight(Node<K, V>* right) {
        this->right = right;
    }

    Node* getLeft() const {
        return left;
    }

    void setLeft(Node<K, V>* left) {
        this->left = left;
    }

protected:
    K key;
    V value;

private:
    Node<K, V>* left;
    Node<K, V>* right;
};


#endif //MY_BINARY_SEARCH_TREE_TREE_NODE_H
