#ifndef LAB_ITERATORS_ARRAYSEQUENCE_HPP
#define LAB_ITERATORS_ARRAYSEQUENCE_HPP

#include "Sequence.hpp"
#include "DynamicArray.hpp"

template<class T>
class ArraySequence : Sequence<T> {
private:
    DynamicArray<T> *sequence = nullptr;
public:
    ArraySequence() {
        this->sequence = new DynamicArray<T>();
    }

    ArraySequence(DynamicArray<T> *array) {
        this->sequence = new DynamicArray<T>(array);
    }

    ArraySequence(int size) {
        this->sequence = DynamicArray<T>(size);
    }

    ArraySequence(T *array, int n) {
        this->sequence = new DynamicArray<T>(array, n);
    }

    ~ArraySequence() {
        delete sequence;
    }

    void resize(int newsize) {
        this->sequence->resize(newsize);
    }

    void append(const T &data) {
        this->sequence->pushBack(data);
    }

    void prepend(const T &data) {
        this->sequence->pushBegin(data);
    }

    void insert(int index, const T &data) {
        this->sequence->insert(index, data);
    }

    const T &get(int index) {
        return this->sequence->get(index);
    }

    int getLength() {
        return this->sequence->getLength();
    }

    T &operator[](int index) {
        return this->sequence->operator[](index);
    }

    const T &getFirst() {
        return this->sequence->get(0);
    }

    const T &getLast() {
        return this->sequence->get(this->getLength() - 1);
    }

    typename DynamicArray<T>::Iterator begin() {
        return this->sequence->begin();
    }

    typename DynamicArray<T>::Iterator end() {
        return this->sequence->end();
    }

    typename DynamicArray<T>::Iterator rbegin() {
        return this->sequence->rbegin();
    }

    typename DynamicArray<T>::Iterator rend() {
        return this->sequence->rend();
    }
};

#endif //LAB_ITERATORS_ARRAYSEQUENCE_HPP
