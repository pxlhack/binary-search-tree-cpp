#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    rbTree.put(3, 3);
    rbTree.put(5, 3);
    rbTree.put(1, 3);
    rbTree.put(10, 3);
    rbTree.print();
    return 0;
}
