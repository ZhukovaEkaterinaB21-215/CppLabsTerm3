//
// Created by ekate on 31.10.2022.
//

#ifndef LAB_ITERATORS_ARRAYSEQUENCE_HPP
#define LAB_ITERATORS_ARRAYSEQUENCE_HPP
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <class T>
class ArraySequence: Sequence<T>
{
private:
    DynamicArray<T>* sequence = nullptr;
    int size;
public:
    ArraySequence()
    {
        this->sequence = new DynamicArray<T>();
        this->size = 0;
    }

    ArraySequence(DynamicArray<T>* array)
    {
        this->sequence = new DynamicArray<T>(array);
    }

    ArraySequence(int size)
    {
        this->sequence = DynamicArray<T>(size);
    }

    ArraySequence(T* array, int n)
    {
        this->sequence = new DynamicArray<T>(array, n);
    }

    ~ArraySequence()
    {
        delete sequence;
    }

    void resize(int newsize)
    {
        this->sequence->resize(newsize);
        this->size = newsize;
    }

    void append (const T& data)
    {
        this->sequence->pushBack(data);
        this->size++;
    }

    void prepend(const T& data)
    {
        this->sequence->pushBegin(data);
        this->size++;
    }

    void insert(int index, const T& data)
    {
        this->sequence->insert(index, data);
        this->size++;
    }

    const T& get(int index)
    {
        return  this->sequence->get(index);
    }

    int getLength ()
    {
        return this->sequence->getLength();
    }

    T& operator[](int index)
    {
        return  this->sequence->operator[](index);
    }

    const T& getFirst()
    {
        return this->sequence->get(0);
    }

    const T& getLast()
    {
        return this->sequence->get(this->getLength()-1);
    }

    typename DynamicArray<T>::Iterator begin()
    {
        return this->sequence->begin();
    }

    typename DynamicArray<T>::Iterator end()
    {
        return this->sequence->end();
    }

    typename DynamicArray<T>::Iterator rbegin()
    {
        return this->sequence->rbegin();
    }

    typename DynamicArray<T>::Iterator rend()
    {
        return this->sequence->rend();
    }

    void InsertionSort(int size, bool comp (T a, T b))
    {
        return this->sequence->InsertionSort(size, comp);
    }
};
#endif //LAB_ITERATORS_ARRAYSEQUENCE_HPP
