#ifndef HASHTABLE_HASHFUNCTION_HPP
#define HASHTABLE_HASHFUNCTION_HPP

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template<typename TKey, typename TValue>
class Hash_Table {
private:
    unsigned static const defaultSize = 17;
    vector<list < pair<TKey, TValue>>>
    table;
    unsigned capacity;
    unsigned size;
    unsigned element;
    unsigned counter;

    bool prime(unsigned n) {
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
                return false;
        return true;
    }

public:
    Hash_Table() {
        this->size = this->defaultSize;
        this->capacity = 0;
        this->counter = 1;
        this->table.resize(this->defaultSize, list<pair<TKey, TValue>>());
        this->element = this->defaultSize;
        while (!prime(this->element))
            this->element++;
        unsigned element_1 = this->defaultSize;
        while (element_1 != 0) {
            this->counter = this->counter * 10;
            element_1 = element_1 / 10;
        }
    }


    Hash_Table(unsigned div) {
        this->size = div;
        this->capacity = 0;
        this->counter = 1;
        this->table.resize(this->size, list<pair<TKey, TValue>>());
        this->element = this->size;
        while (!prime(this->element))
            this->element++;
        unsigned element_1 = this->size;
        while (element_1 != 0) {
            this->counter = this->counter * 10;
            element_1 = element_1 / 10;
        }
    }

    ~Hash_Table() {
        this->table.clear();
    }

    list <pair<TKey, TValue>> &get_key_value(unsigned index) {
        list <pair<TKey, TValue>> &lst = this->table[index];
        return lst;
    }

    unsigned hashFunction(int key) {
        return ((this->counter * key % this->element) % this->size);
    }

    const TValue &get(const TKey &key) {
        unsigned index = this->hashFunction(key);
        auto &cell = this->table[index];
        auto bItr = begin(cell);
        bool exists = false;
        TValue data;
        for (bItr = begin(cell); bItr != end(cell); bItr++) {
            if (bItr->first == key) {
                exists = true;
                data = bItr->second;
            }
        }
        if (!exists) {
            cout << "Key not found" << endl;
        }
        return data;
    }

    void put(const TKey &key, const TValue &value) {
        if (this->capacity > this->size / 2) {
            int a = 2 * this->size;
            this->rehash(a);
        }
        unsigned index = this->hashFunction(key);
        list <pair<TKey, TValue>> &lst = this->table.at(index);
        if (!lst.empty()) { //std::find //find_if
            auto it = lst.begin();
            for (it; it != lst.end(); ++it) {
                if (it->first == key) {
                    it->second = value;
                    return;
                }
            }
        }
        pair<TKey, TValue> element;
        element.first = key;
        element.second = value;
        this->table[index].push_back(element);
        this->capacity++;
    }

    void printTable() {
        for (int i = 0; i < this->size; i++) {
            cout << "a[" << i << "]: ";
            if (this->table[i].size() == 0) {
                cout << endl;
                continue;
            }
            auto bItr = this->table[i].begin();
            int counter = 1;
            for (bItr; bItr != this->table[i].end(); bItr++) {
                cout << "(" << counter << ") key: " << bItr->first << " value: " << bItr->second << " ";
                counter++;
            }
            cout << endl;
        }
        return;
    }

    void remove(const TKey &key) {
        unsigned index = this->hashFunction(key);
        auto &cell = this->table[index];
        auto bItr = begin(cell);
        bool exists = false;
        for (bItr = begin(cell); bItr != end(cell); bItr++) {
            if (bItr->first == key) {
                exists = true;
                bItr = cell.erase(bItr);
                this->capacity--;
                break;
            }
        }
        if (!exists) {
            std::cout << "Key not found";
        }
        return;
    }

    void rehash(unsigned n) {
        Hash_Table<int, int> hashTable = Hash_Table<int, int>(n);
        for (int i = 0; i < this->size; i++) {
            auto it = this->table[i].begin();
            for (it; it != this->table[i].end(); ++it) {
                hashTable.put(it->first, it->second);
            }
        }

        for (int i = 0; i < this->size; i++) {
            auto &cell = this->table[i];
            auto bItr = begin(cell);
            while (bItr != end(cell)) {
                bItr = cell.erase(bItr);
                this->capacity--;
            }
            if (this->table[i].size() > 0) {
                cell = this->table[i];
                bItr = begin(cell);
                bItr = cell.erase(bItr);
                this->capacity--;
            }

        }

        this->size = n;
        this->table.resize(this->size, list<pair<TKey, TValue>>());

        this->counter = 1;
        this->element = this->size;
        while (!prime(this->element))
            this->element++;
        unsigned element_1 = this->size;
        while (element_1 != 0) {
            this->counter = this->counter * 10;
            element_1 = element_1 / 10;
        }

        for (int i = 0; i < this->size; i++) {
            list <pair<TKey, TValue>> &element = hashTable.get_key_value(i);
            pair<TKey, TValue> data;
            auto it = element.begin();
            for (it; it != element.end(); ++it) {
                data.first = it->first;
                data.second = it->second;
                this->table[i].push_back(data);
                this->capacity++;
            }
        }
        return;
    }

    TValue &operator[](const TKey &key) {
        size_t index = this->hashFunction(key);
        size_t data = 0;
        list <pair<TKey, TValue>> &lst = this->get_key_value(index);
        auto it = lst.begin();
        for (it; it != lst.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        pair<TKey, TValue> data_element;
        data_element.first = key;
        data_element.second = TValue();
        lst.push_back(data_element);
        return lst.back().second;
    }

    void putForIndex(unsigned index, TKey _key, TValue _value) {
        pair<TKey, TValue> data_element;
        data_element.first = _key;
        data_element.second = _value;
        this->table[index].push_back(data_element);
    }
};

#endif //HASHTABLE_HASHFUNCTION_HPP
