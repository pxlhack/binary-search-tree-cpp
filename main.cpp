#include "lib/header.h"

int main() {
//    testMenu();
//    complexityTest();
    Node<int, int> node;
    for (int i = 0; i < 10; ++i) {
        cout << node.getColor() << endl;
        node.changeColor();
    }

    return 0;
}
