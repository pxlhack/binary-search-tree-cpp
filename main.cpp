#include "lib/header.h"

int main() {
    srand(time(nullptr));
    RBTree<int, int> rbTree;
    rbTree.put(3, 3);
    rbTree.put(4, 3);
    for (int i = 0; i < 20; ++i) {
        rbTree.put(rand() % 20 + 1, 0);
        rbTree.remove(rand() % 20 + 1);
        try {
            rbTree.getValueByKey(rand() % 20 + 1);
        }
        catch (const char *c) {}
    }
//    cout << rbTree.getSize() << endl;
//    for (int i = 0; i < 100; ++i) {
//        rbTree.remove(rand() % 20);
//    }

    /* rbTree.put(57, 0);
     rbTree.put(34, 0);
     rbTree.put(89, 0);
     rbTree.put(13, 0);
     rbTree.put(23, 0);
     rbTree.put(54, 0);
     rbTree.put(14, 0);
     rbTree.put(74, 0);
     rbTree.put(45, 0);
     rbTree.put(32, 0);
     rbTree.print();
     cout << "\n\n";
     rbTree.remove(32);*/

//    cout << rbTree.getSize() << endl;
    rbTree.print();
//    int r = rbTree.getRootKey();
//    cout << "root: " << r << endl;
//
//    rbTree.remove(r);
//    cout << rbTree.getSize() << endl;
//    rbTree.print();


    /*auto it = rbTree.itrbegin();
    while (it != rbTree.itrend()) {
        cout << (*it).getKey() << endl;
        ++it;
    }*/
    return 0;
}
