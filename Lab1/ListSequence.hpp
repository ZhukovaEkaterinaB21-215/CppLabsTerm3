#ifndef LAB_ITERATORS_LISTSEQUENCE_HPP
#define LAB_ITERATORS_LISTSEQUENCE_HPP

#include "Sequence.hpp"
#include "LinkedList.hpp"

template<class T>
class LinkedListSequence : Sequence<T> {
private:
    LinkedList<T> *sequence = nullptr;
public:
    LinkedListSequence() {
        this->sequence = new LinkedList<T>();
    }

    LinkedListSequence(LinkedList<T> *obj) {
        this->sequence = new LinkedList<T>(obj);
    }

    LinkedListSequence(T *array, int n) {
        this->sequence = new LinkedList<T>(array, n);
    }

    void append(const T &data) {
        this->sequence->append(data);
    }

    void prepend(const T &data) {
        this->sequence->prepend(data);
    }

    void insert(int index, const T &data) {
        this->sequence->insert(data, index);
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
        return this->sequence->getFirst();
    }

    const T &getLast() {
        return this->sequence->getLast();
    }

    LinkedList<T> *getFirstElement() {
        return this->sequence->getFirstElement();
    }

    LinkedList<T> *getLastElement() {
        return this->sequence->getLastElement();
    }

    typename LinkedList<T>::Iterator begin() {
        return this->sequence->begin();
    }

    typename LinkedList<T>::Iterator end() {
        return this->sequence->end();
    }

    typename LinkedList<T>::Iterator rbegin() {
        return this->sequence->rbegin();
    }

    typename LinkedList<T>::Iterator rend() {
        return this->sequence->rend();
    }
};

#endif //LAB_ITERATORS_LISTSEQUENCE_HPP
