#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    for (int i = 1; i < 17; ++i) {
        rbTree.put(i, 3);
    }
//    rbTree.print();
//    rbTree.removeNodeByKey(14);
//    rbTree.print();


    auto it = rbTree.itrbegin();
    while (it != rbTree.itrend()) {
        cout << (*it).getKey() << endl;
        ++it;
    }
    return 0;
}
