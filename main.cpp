#include "lib/header.h"

int main() {
    RBTree<int, int> rbTree;
    for (int i = 1; i < 17; ++i) {
        rbTree.put(i, 3);
    }


//    auto it = rbTree.begin();
//    cout << (*it).getKey() << endl;
//    int count = 0;
//    while (it != rbTree.end()) {
//        cout << (*it).getKey() << endl;
//        ++it;
//        count++;
//    }

//    cout << count << endl;


    return 0;
}
