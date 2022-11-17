//
// Created by ekate on 31.10.2022.
//

#ifndef LAB_ITERATORS_LISTSEQUENCE_HPP
#define LAB_ITERATORS_LISTSEQUENCE_HPP
#include "Sequence.hpp"
#include "LinkedList.hpp"
template <class T>
class LinkedListSequence: Sequence<T>
{
private:
    LinkedList<T>* sequence = nullptr;
    int size;
public:
    LinkedListSequence()
    {
        this->sequence = new LinkedList<T>();
        this->size = 0;
    }

    LinkedListSequence(LinkedList<T>* obj)
    {
        this->sequence = new LinkedList<T>(obj);
        size = obj->getLength();
    }

    LinkedListSequence(T* array, int  n)
    {
        this->sequence = new LinkedList<T>(array, n);
        this->size = n;
    }

    void append (const T& data)
    {
        this->sequence->append(data);
        this->size++;
    }

    void prepend(const T& data)
    {
        this->sequence->prepend(data);
        this->size++;
    }

    void insert(int index, const T& data)
    {
        this->sequence->insert(data, index);
        this->size++;
    }

    const T& get(int index)
    {
        return this->sequence->get(index);
    }

    int getLength ()
    {
        return this->sequence->getLength();
    }

    T& operator[](int index)
    {
        return this->sequence->operator[](index);
    }

    const T& getFirst()
    {
        return this->sequence->getFirst();
    }

    const T& getLast()
    {
        return this->sequence->getLast();
    }

    LinkedList<T>* getFirstElement()
    {
        return this->sequence->getFirstElement();
    }

    LinkedList<T>* getLastElement()
    {
        return this->sequence->getLastElement();
    }

    typename LinkedList<T>::Iterator begin()
    {
        return this->sequence->begin();
    }

    typename LinkedList<T>::Iterator end()
    {
        return this->sequence->end();
    }

    typename LinkedList<T>::Iterator rbegin()
    {
        return this->sequence->rbegin();
    }

    typename LinkedList<T>::Iterator rend()
    {
        return this->sequence->rend();
    }

    void PrintList()
    {
        this->sequence->PrintList();
    }
};
#endif //LAB_ITERATORS_LISTSEQUENCE_HPP
