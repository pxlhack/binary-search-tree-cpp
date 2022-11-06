#include <iostream>
#include "header.h"


int main() {
    MyBinarySearchTree<double, int> m;
    m.put(3, 44);
    m.put(4, 4);
    m.put(1, 1);
    m.put(6, 6);
    m.put(0, 0);
    m.put(5, 5);
    m.put(2, 2);
    m.put(3.5, 333);
    m.showTree();
    cout << m.get(3) << endl;
    m.remove(3);
    m.showTree();
    cout << (m.get(3));
    return 0;
}

/*
 3
 1
 0
 2
 4
 6
 5
 */