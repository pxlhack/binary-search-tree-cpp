#include "lib/header.h"

void test()
{

}

int main() {
    RBTree<int, int> rbTree;
    for (int i = 1; i < 17; ++i) {
        rbTree.put(i, 3);
    }
    rbTree.print();
    cout << endl;
    cout << endl;

    cout << rbTree.getSize() << endl;
    cout << rbTree.getValueByKey(6) << endl;

//    rbTree.print();

    return 0;
}
