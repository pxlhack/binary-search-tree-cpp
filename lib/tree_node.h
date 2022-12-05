#ifndef MY_BINARY_SEARCH_TREE_TREE_NODE_H
#define MY_BINARY_SEARCH_TREE_TREE_NODE_H

template<typename K, typename V>
class TreeNode {
public:
    TreeNode() {
        this->right = nullptr;
        this->left = nullptr;
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

    TreeNode *getRight() const {
        return right;
    }

    void setRight(TreeNode<K, V> *right) {
        this->right = right;
    }

    TreeNode *getLeft() const {
        return left;
    }

    void setLeft(TreeNode<K, V> *left) {
        this->left = left;
    }

protected:
    K key;
    V value;
    TreeNode<K, V> *left;
    TreeNode<K, V> *right;
};


#endif //MY_BINARY_SEARCH_TREE_TREE_NODE_H
