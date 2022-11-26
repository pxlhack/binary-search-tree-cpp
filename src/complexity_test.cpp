//#include <ctime>
//#include <cmath>
//#include <iostream>
//#include "../lib/bst.h"
//#include "../lib/complexity_test.h"
//
//
//
//void sRand() {
//    srand(time(0));
//    RRand = (INT_64) rand();
//}
//
//INT_64 LineRand() {
//    INT_64 y1, y2;
//    y1 = (aRand * RRand + cRand) % mRand;
//    y2 = (aRand * y1 + cRand) % mRand;
//    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 &
//                                         0xFFFFFFFF00000000LL) >> 32;
//    return RRand;
//}
//
//
//
//int complexityTest() {
//    cout << "ВЫРОЖДЕННЫЕ ДЕРЕВЬЯ\n";
//    test_ord(10);
//    cout << "\n";
//    test_ord(100);
//    cout << "\n";
//    test_ord(500);
//    cout << "\n";
//    test_ord(1000);
//    cout << "\n";
//    test_ord(2000);
//    cout << "\n";
//    test_ord(3000);
//    cout << "\n";
//    test_ord(4000);
//    cout << "\n";
//    test_ord(5000);
//    cout << "\n";
//    test_ord(10000);
//    cout << "\n";
//    test_ord(15000);
//    cout << "\n";
//    test_ord(20000);
//    cout << "\n";
//    test_ord(25000);
//    cout << "\n";
//    test_ord(30000);
//    cout << "\n";
//    test_ord(35000);
//    cout << "\n";
//    test_ord(40000);
//    cout << "\n";
//    test_ord(45000);
//    cout << "\n";
//    test_ord(50000);
//    cout << "\n";
//    test_ord(55000);
//    cout << "\n";
//    test_ord(75000);
//    cout << "\n";
//    test_ord(100000);
//    cout << "\n";
//    cout << "СЛУЧАЙНЫЕ ДЕРЕВЬЯ\n";
//    test_rand(10);
//    cout << "\n";
//    test_rand(100);
//    cout << "\n";
//    test_rand(500);
//    cout << "\n";
//    test_rand(1000);
//    cout << "\n";
//    test_rand(2000);
//    cout << "\n";
//    test_rand(3000);
//    cout << "\n";
//    test_rand(4000);
//    cout << "\n";
//    test_rand(5000);
//    cout << "\n";
//    test_rand(10000);
//    cout << "\n";
//    test_rand(15000);
//    cout << "\n";
//    test_rand(20000);
//    cout << "\n";
//    test_rand(25000);
//    cout << "\n";
//    test_rand(30000);
//    cout << "\n";
//    test_rand(35000);
//    cout << "\n";
//    test_rand(40000);
//    cout << "\n";
//    test_rand(45000);
//    cout << "\n";
//    test_rand(50000);
//    cout << "\n";
//    test_rand(55000);
//    cout << "\n";
//    test_rand(75000);
//    cout << "\n";
//    test_rand(100000);
//    cout << "\n";
//    return 0;
//}
//
//void test_rand(int n) {
//    //создание дерева для 64 – разрядных ключей типа INT_64
//    BST<INT_64, int> tree;
//    //массив для ключей, которые присутствуют в дереве
//    INT_64 *m = new INT_64[n];
//    //установка первого случайного числа
//    sRand();
//    //заполнение дерева и массива элементами
//    //со случайными ключами
//    for (int i = 0; i < n; i++) {
//        m[i] = LineRand();
//        tree.put(m[i], 1);
//    }
//    //вывод размера дерева до теста
//    cout << "items count:" << tree.getSize() << endl;
//    //обнуление счётчиков трудоёмкости вставки,
//    //удаления и поиска
//    double I = 0;
//    double D = 0;
//    double S = 0;
//    //генерация потока операций, 10% - промахи операций
//    for (int i = 0; i < n / 2; i++)
//        if (i % 10 == 0) { //10% промахов
//            tree.removeNodeByKey(LineRand());
//            D += tree.getTreeNodesCountViewedByPreviousOperation();
//            tree.put(m[rand() % n], 1);
//            I += tree.getTreeNodesCountViewedByPreviousOperation();
//            try {
//                tree.getValueByKey(LineRand());
//                S += tree.getTreeNodesCountViewedByPreviousOperation();
//            }
//                //обработка исключения при ошибке операции поиска
//            catch (const char *) { S += tree.getTreeNodesCountViewedByPreviousOperation(); }
//        } else { //90% успешных операций
//            int ind = rand() % n;
//            tree.removeNodeByKey(m[ind]);
//            D += tree.getTreeNodesCountViewedByPreviousOperation();
//            INT_64 key = LineRand();
//            tree.put(key, 1);
//            I += tree.getTreeNodesCountViewedByPreviousOperation();
//            m[ind] = key;
//            try {
//                tree.getValueByKey(m[rand() % n]);
//                S += tree.getTreeNodesCountViewedByPreviousOperation();
//            }
//                //обработка исключения при ошибке операции поиска
//            catch (const char *) { S += tree.getTreeNodesCountViewedByPreviousOperation(); }
//        } //конец теста
//    //вывод результатов:
//    //вывод размера дерева после теста
//    cout << "items count:" << tree.getSize() << endl;
//    //теоретической оценки трудоёмкости операций BST
//    cout << "1.39*log2(n)=" << 1.39 * (log((double)
//                                                   n) / log(2.0)) << endl;
//    //экспериментальной оценки трудоёмкости вставки
//    cout << "Count insert: " << I / (n / 2) << endl;
//    //экспериментальной оценки трудоёмкости удаления
//    cout << "Count delete: " << D / (n / 2) << endl;
//    //экспериментальной оценки трудоёмкости поиска
//    cout << "Count search: " << S / (n / 2) << endl;
//    //освобождение памяти массива m[]
//    delete[] m;
//}
//
//void test_ord(int n) {
//    //создание дерева для 64 – разрядных ключей типа INT_64
//    BST<INT_64, int> tree;
//    //массив для ключей, которые присутствуют в дереве
//    INT_64 *m = new INT_64[n];
//    //заполнение дерева и массива элементами
//    // с возрастающими чётными ключами
//    //на интервале [0, 10000, 20000, ... ,10000*n]
//    for (int i = 0; i < n; i++) {
//        m[i] = i * 10000;
//        tree.put(m[i], 1);
//    }
//    //вывод размера дерева до теста
//    cout << "items count:" << tree.getSize() << endl;
//    //обнуление счётчиков трудоёмкости вставки,
//    // удаления и поиска
//    double I = 0;
//    double D = 0;
//    double S = 0;
//    //установка первого случайного числа
//    sRand();
//    //генерация потока операций, 10% - промахи операций
//    for (int i = 0; i < n / 2; i++) {
//        if (i % 10 == 0) { //10% промахов
//            int k = LineRand() % (10000 * n);
//            k = k + !(k % 2); //случайный нечётный ключ
//            tree.removeNodeByKey(k);
//            D += tree.getTreeNodesCountViewedByPreviousOperation();;
//            tree.put(m[rand() % n], 1);
//            I += tree.getTreeNodesCountViewedByPreviousOperation();;
//            k = LineRand() % (10000 * n);
//            k = k + !(k % 2); // случайный нечётный ключ
//            try {
//                tree.getValueByKey(k);
//                S += tree.getTreeNodesCountViewedByPreviousOperation();;
//            }
//                //обработка исключения при ошибке операции поиска
//            catch (const char *) { S += tree.getTreeNodesCountViewedByPreviousOperation(); }
//        } else //90% успешных операций
//        {
//            int ind = rand() % n;
//            tree.removeNodeByKey(m[ind]);
//            D += tree.getTreeNodesCountViewedByPreviousOperation();;;
//            int k = LineRand() % (10000 * n);
//            k = k + k % 2; // случайный чётный ключ
//            tree.put(k, 1);
//            I += tree.getTreeNodesCountViewedByPreviousOperation();;;
//            m[ind] = k;
//            try {
//                tree.getValueByKey(m[rand() % n]);
//                S += tree.getTreeNodesCountViewedByPreviousOperation();;;
//            }
//                //обработка исключения при ошибке операции поиска
//            catch (const char *) { S += tree.getTreeNodesCountViewedByPreviousOperation();; }
//        }
//    }
//
//
//    //вывод результатов:
//    // вывод размера дерева после теста
//    cout << "items count:" << tree.getSize() << endl;
//    //теоретической оценки трудоёмкости операций BST
//    cout << "n/2 =" << n / 2 << endl;
//    //экспериментальной оценки трудоёмкости вставки
//    cout << "Count insert: " << I / (n / 2) << endl;
//    //экспериментальной оценки трудоёмкости удаления
//    cout << "Count delete: " << D / (n / 2) << endl;
//    //экспериментальной оценки трудоёмкости поиска
//    cout << "Count search: " << S / (n / 2) << endl;
//    //освобождение памяти массива m[]
//    delete[] m;
//
//} //конец теста
