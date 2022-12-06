#include "lib/header.h"
#include <fstream>

void test()
{
    int size[] = {10, 50, 100, 250, 300, 450, 500, 650, 700, 750};

    ofstream f_r_i("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_ins.txt");
    ofstream f_r_r("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_rem.txt");
    ofstream f_r_s("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_see.txt");

    for(int i = 0; i < 10; i++)
    {
        RBTree<int, int> rbT;
        for(int j = 0; j < size[i]; j++)
        {
            rbT.put(j, 2);
        }

        f_r_i << rbT.getTreeNodesCountViewedByPreviousOperation() << endl;

        rbT.getValueByKey(size[i] / 2);

        f_r_s << rbT.getTreeNodesCountViewedByPreviousOperation() << endl;

        rbT.removeNodeByKey(size[i] / 2);

        f_r_r << rbT.getTreeNodesCountViewedByPreviousOperation() << endl;
    }

    f_r_i.close();
    f_r_r.close();
    f_r_s.close();

}

int main() {

    test();
    return 0;
}
