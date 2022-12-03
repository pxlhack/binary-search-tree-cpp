#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    rbTree.put(3, 3);
    rbTree.put(4, 3);
    rbTree.showKeysList();
    return 0;
}
