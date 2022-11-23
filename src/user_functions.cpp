#include "../lib/user_functions.h"

void testMenu() {
    BST<int, int> *pBST = nullptr;

    bool isWorked = true;
    string command;

    do {
        std::cout << HELP;
        std::cout << ">";
        std::cin >> command;

        if (isValidCommand(command)) {
            int num = stoul(command);
            switch (num) {

                case 1: {
                    createBST(&pBST);
                    cout << "~~ Created a empty tree ~~\n\n";
                    break;
                }

                case 2: {
                    createBST(&pBST);
                    randomFill(&pBST, 10);
                    cout << "~~ Created a tree with size = " << pBST->getSize() << " ~~\n";
                    cout << "Keys: ";
                    pBST->showKeysList();
                    cout << "Values: ";
                    pBST->showValuesList();
                    cout << "\n";
                    break;
                }

                case 3: {
                    if (pBST == nullptr) {
                        cout << "-- Tree is not created -- \n\n";
                        break;
                    }

                    string keyValue = getIntegerValueAsString("key");
                    if (keyValue == "e") {
                        break;
                    }
                    int key = stoul(keyValue);

                    string valueString = getIntegerValueAsString("value");
                    if (valueString == "e") {
                        break;
                    }
                    int value = stoul(valueString);

                    bool isPushed = pBST->put(key, value);
                    if (isPushed) {
                        cout << "~~ {" << key << ", " << value << "} pushed into tree ~~\n\n";
                    }
                    break;
                }

                case 4: {
                    if (pBST == nullptr) {
                        cout << "-- Tree is not created -- \n\n";
                        break;
                    }

                    string keyValue = getPositiveValueAsString("key");
                    if (keyValue == "e") {
                        break;
                    }
                    int key = stoul(keyValue);

                    try {
                        int value = pBST->getValueByKey(key);
                        bool isRemoved = pBST->removeNodeByKey(key);
                        if (isRemoved) {
                            cout << "~~ {" << key << ", " << value << "} removed from tree ~~\n\n";
                        }
                    }
                    catch (const char *e) {
                        cout << e << endl;
                    }


                    break;
                }

                case 5: {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n ";
                        break;
                    }

                    if (pBST->isEmpty()) {
                        cout << "-- Tree is empty --\n\n";
                        break;
                    }

                    int key;
                    if (setKeyFromString(&key)) {
                        break;
                    }

                    int value;
                    if (setValueFromString(&value)) {
                        break;
                    }

                    pBST->setValueForKey(value, key);

                    break;
                }

                case 6: {
                    pBST->showKeysList();
                    break;
                }

                case 7: {
                    pBST->showValuesList();
                    break;
                }

                case 8: {
                    if (pBST == nullptr) {
                        cout << "-- Tree is not created --\n\n";
                        break;
                    }
                    cout << "~~ Size = " << pBST->getSize() << " ~~\n";
                    break;
                }

                case 9: {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n";
                        break;
                    }

                    if (pBST->isEmpty()) {
                        cout << "~~ Tree is empty ~~\n\n";
                    } else {
                        cout << "-- Tree is not empty --\n\n";
                    }
                    break;
                }

                case 10 : {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n ";
                        break;
                    }

                    if (pBST->isEmpty()) {
                        cout << "-- Tree is empty --\n\n";
                        break;
                    }


                    string keyValue = getPositiveValueAsString("key");
                    if (keyValue == "e") {
                        break;
                    }
                    int key = stoul(keyValue);

                    try {
                        int value = pBST->getValueByKey(key);
                        cout << "~~ {" << key << ", " << value << "}~~\n\n";
                    }
                    catch (const char *e) {
                        cout << e << endl;
                    }

                    break;
                }

                case 11 : {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n ";
                        break;
                    }

                    if (pBST->isEmpty()) {
                        cout << "-- Tree is empty --\n\n";
                        break;
                    }


                    string keyValue = getIntegerValueAsString("key");
                    if (keyValue == "e") {
                        break;
                    }
                    int key = stoul(keyValue);

                    int count = pBST->nodesCountWithKeysMoreThan(key);
                    cout << "Count of nodes with keys more than " << key << ": " << count << "\n";
                    break;
                }

                case 12: {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n ";
                        break;
                    }

                    int count = pBST->getTreeNodesCountViewedByPreviousOperation();
                    cout << "Count of nodes: " << count << "\n";
                    break;
                }

                case 13: {
                    if (pBST == nullptr) {
                        cout << "-- Tree not created --\n\n ";
                        break;
                    }

                    pBST->clear();
                    cout << "~~ Tree cleared ~~\n\n";
                    break;
                }

                case 14: {
                    bool isIteratorsWorked = true;
                    string iteratorsCommand;
                    auto it1 = pBST->begin();
                    do {
                        cout << "1) ++\n2) --\n3) *\n4) begin\n5) end\n6) print\n0) exit\n";
                        cout << ">";
                        cin >> iteratorsCommand;


                        if (isPositiveValue(std::string_view(iteratorsCommand))) {
                            int i_num = stoul(iteratorsCommand);
                            switch (i_num) {
                                case 1: {
                                    if (it1 == pBST->end()) { cout << "iterator is not set\n"; }
                                    else {
                                        ++it1;
                                    }
                                    break;
                                }
                                case 2: {
                                    if (it1 == pBST->end()) { cout << "iterator is not set\n"; }
                                    else {
                                        --it1;
                                    }
                                    break;
                                }
                                case 3: {
                                    if (it1 == pBST->end()) { cout << "iterator is not set\n"; }
                                    else {
                                        cout << (*it1).getKey() << endl;
                                    }
                                    break;
                                }
                                case 4: {
                                    it1 = pBST->begin();
                                    break;
                                }
                                case 5: {
                                    it1 = pBST->end();
                                    break;
                                }
                                case 6: {
                                    auto it2 = pBST->begin();
                                    while (it2 != pBST->end()) {
                                        cout << (*it2).getKey() << " ";
                                        ++it2;
                                    }
                                    cout << endl;
                                    break;
                                }
                                case 0: {
                                    isIteratorsWorked = false;
                                    break;
                                }
                                default: {
                                    cout << "!!! unknown command: " << iteratorsCommand << " !!!" << endl;
                                    break;
                                }
                            }
                        } else {
                            cout << "!!! unknown command: " << iteratorsCommand << " !!!" << endl;
                        }

                    } while (isIteratorsWorked);
                    break;
                }

                case 0 : {
                    isWorked = false;
                    break;
                }

                default: {
                    cout << "!!! unknown command: " << command << " !!!" << endl;
                    break;
                }
            }
        } else {
            cout << "!!! unknown command: " << command << " !!!" << endl;
        }

    } while (isWorked);
}

bool createBST(BST<int, int> **pBst) {
    if (*pBst != nullptr) {
        (*pBst)->clear();
    }

    *pBst = new BST<int, int>();

    return true;
}

bool isValidCommand(const string &command) {
    return isPositiveValue(std::string_view(command));
}

bool isPositiveValue(std::string_view s) {
    static const std::regex r(R"(\d{1,})");
    return regex_match(s.data(), r);
}

int getRandom(int begin, int end) {
    return rand() % (end - begin) + begin;
}

void randomFill(BST<int, int> **tree, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        (*tree)->put(getRandom(0, 2 * size), getRandom(-100, 100));
    }
}

string getIntegerValueAsString(const string &desiredValue) {
    string str;
    bool flag = true;

    do {
        cout << "Enter the " << desiredValue << ":";
        cin >> str;

        if (str == "e") break;
        if (isPositiveValue(string_view(str)) || isNegativeValue(string_view(str))) {
            flag = false;
        } else {
            cout << "Not a number!\n\n";
        }
    } while (flag);
    return str;
}

bool isNegativeValue(std::string_view s) {
    static const regex r(R"(-\d{1,})");
    return regex_match(s.data(), r);
}

string getPositiveValueAsString(const string &desiredValue) {
    string str;
    bool flag = true;

    do {
        cout << "Enter the " << desiredValue << ":";
        cin >> str;

        if (str == "e") break;
        if (isPositiveValue(string_view(str))) {
            flag = false;
        } else {
            cout << "Not a number!\n\n";
        }
    } while (flag);
    return str;
}

bool setValueFromString(int *value) {
    string valueString = getIntegerValueAsString("value");
    if (valueString == "e") {
        return true;
    }
    *value = stoul(valueString);
    return false;
}

bool setKeyFromString(int *key) {
    string positionString = getIntegerValueAsString("key");
    if (positionString == "e") {
        return true;
    }
    *key = stoul(positionString);
    return false;
}