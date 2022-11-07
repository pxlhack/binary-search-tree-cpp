#include "lib/header.h"


int main() {
    MyBinarySearchTree<double, int> m;
    m.showKeyList();
    m.put(3, 44);
    m.put(4, 4);
    m.put(1, 1);
    m.put(6, 6);
    m.put(0, 0);
    m.put(5, 5);
    m.put(2, 2);
    m.put(3.5, 333);
    cout << m.getSize() << endl;
    m.showKeyList();
    m.showInorderTraversal();
    m.set(3.5, 332);
    m.showInorderTraversal();
    MyBinarySearchTree<double, int> n(m);
    m.showKeyList();
    m.clear();
    m.showKeyList();
    n.showKeyList();
    return 0;
}
