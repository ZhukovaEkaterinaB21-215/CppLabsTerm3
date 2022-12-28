#ifndef HASHTABLE_TESTS_HPP
#define HASHTABLE_TESTS_HPP

#include <iostream>
#include <random>
#include <assert.h>
#include <string>
#include <functional>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void tests() {
    Hash_Table<int, int> hashTable = Hash_Table<int, int>(6);
    Hash_Table<int, int> hashTable1 = Hash_Table<int, int>(24);
    hashTable.put(1, 8);
    hashTable.put(9, 7);
    hashTable.put(21, 13);
    hashTable.put(112, 97);
    hashTable.put(91, 84);
    hashTable.put(5, 128);
    hashTable.put(13, 103);
    hashTable.put(64, 34);
    hashTable.put(88, 99);
    hashTable.put(20, 11);
    hashTable.put(143, 8);
    hashTable.put(19, 822);


    hashTable1.putForIndex(13, 1, 8);
    hashTable1.putForIndex(1, 9, 7);
    hashTable1.putForIndex(12, 21, 13);
    hashTable1.putForIndex(6, 112, 97);
    hashTable1.putForIndex(23, 91, 84);
    hashTable1.putForIndex(7, 5, 128);
    hashTable1.putForIndex(0, 13, 103);
    hashTable1.putForIndex(20, 64, 34);
    hashTable1.putForIndex(13, 88, 99);
    hashTable1.putForIndex(4, 20, 11);
    hashTable1.putForIndex(3, 143, 8);
    hashTable1.putForIndex(15, 19, 822);

    for (int i = 0; i < 24; i++) {
        list<pair<int, int>> lst1 = hashTable.get_key_value(i);
        list<pair<int, int>> lst2 = hashTable.get_key_value(i);
        if (((lst1.size() != 0) && (lst2.size() != 0)) || ((lst1.size() == 0) && (lst2.size() == 0))) {
            if (lst1.size() == lst2.size()) {
                auto it1 = lst1.begin();
                auto it2 = lst2.begin();
                for (it1; it1 != lst1.end(); ++it1) {
                    assert(it1->first == it2->first);
                    assert(it1->second == it2->second);
                    ++it2;
                }
            } else {
                cout << "[ERROR] the sizes of the lists do not match" << endl;
                break;
            }
        } else {
            cout << "[ERROR] the sizes of the lists do not match" << endl;
            break;
        }

    }
    cout << "the tests passed without errors" << endl;
}

#endif //HASHTABLE_TESTS_HPP
