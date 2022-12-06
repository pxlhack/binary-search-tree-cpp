#include "lib/header.h"
#include <fstream>

void test()
{
    int size[250];

    for (int i = 1; i <= 250; i++)
        size[i - 1] = i * 100;

    ofstream f_r_i("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_ins.txt");
    ofstream f_r_r("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_rem.txt");
    ofstream f_r_s("D:/FFFFFFFFFFFFFFFFFFFFFFFFFFFF/rb_see.txt");

    for(int i = 0; i < 250; i++)
    {
        RBTree<int, int> rbT;
        for(int j = 0; j < size[i]; j++)
        {
            rbT.put(j, 2);
        }

        f_r_i << float(rbT.getTreeNodesCountViewedByPreviousOperation()) / 6.5 << endl;

        rbT.getValueByKey(size[i] - 1);

        f_r_s << float(rbT.getTreeNodesCountViewedByPreviousOperation()) / 1.8 << endl;

        rbT.removeNodeByKey(size[i] - 1);

        f_r_r << float(rbT.getTreeNodesCountViewedByPreviousOperation()) / 7 << endl;
    }

    f_r_i.close();
    f_r_r.close();
    f_r_s.close();

}

int main() {

    test();
    return 0;
}
