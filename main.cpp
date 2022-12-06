#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    for (int i = 1; i < 17; ++i) {
        rbTree.put(i, 3);
    }
    rbTree.print();
    cout << endl;
    cout << endl;

//    rbTree.print();

    return 0;
}
