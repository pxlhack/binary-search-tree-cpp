#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    rbTree.put(10, 3);
    rbTree.put(5, 3);
    rbTree.put(3, 3);
    rbTree.put(1, 3);
    rbTree.print();
    cout << endl << endl;
    bool flag = rbTree.removeNodeByKey(10);
    cout << endl;
    rbTree.print();

    return 0;
}
