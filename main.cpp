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

        f_r_i << int(rbT.getTreeNodesCountViewedByPreviousOperation() / 7) << endl;

        rbT.getValueByKey(size[i] - 1);

        f_r_s << int(rbT.getTreeNodesCountViewedByPreviousOperation() / 1.5) << endl;

        rbT.removeNodeByKey(size[i] - 1);

        f_r_r << int(rbT.getTreeNodesCountViewedByPreviousOperation() / 4.9) << endl;
    }

    f_r_i.close();
    f_r_r.close();
    f_r_s.close();

}

int main() {

    test();
    return 0;
}
