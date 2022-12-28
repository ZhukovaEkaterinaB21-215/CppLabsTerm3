#include <iostream>
#include <random>
#include "HashFunction.hpp"
#include "Tests.hpp"

const int t = 5000;

int main() {

    int a[t], b[t];
    srand(time(NULL));
    for (int i = 0; i < t; i++) {
        a[i] = 1 + rand() % 5000;
    }
    for (int i = 0; i < t; i++) {
        b[i] = 1 + rand() % 5000;
    }
    int size = t;
    Hash_Table<int, int> hashTable = Hash_Table<int, int>(size);
    for (int i = 0; i < t; i++) {
        hashTable.put(a[i], b[i]);
    }

    hashTable.printTable();

    cout << "tests:" << endl;
    tests();

    return 0;
}
