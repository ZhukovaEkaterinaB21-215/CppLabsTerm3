#ifndef LAB_ITERATORS_TESTS_HPP
#define LAB_ITERATORS_TESTS_HPP

#include <iostream>
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include <chrono>
#include <random>
#include "Comparator.hpp"
#include "ISorter.hpp"
#include <assert.h>

void QuickSortTestsArray() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, DynamicArray<int>::Iterator> *iSort = new ISort<int, DynamicArray<int>::Iterator>;
    iSort->QuickSortArray(arraySequence->begin(), arraySequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == arraySequence->get(i));
    }
    std::cout << "True" << std::endl;
}

void QuickSortTestsList() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    LinkedListSequence<int> *listSequence = new LinkedListSequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, LinkedList<int>::Iterator> *iSort1 = new ISort<int, LinkedList<int>::Iterator>;
    iSort1->QuickSortList(listSequence->begin(), listSequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == listSequence->get(i));
    }
    std::cout << "True" << std::endl;
}

void MergeSortTestsArray() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, DynamicArray<int>::Iterator> *iSort = new ISort<int, DynamicArray<int>::Iterator>;
    iSort->MergeSortArray(arraySequence->begin(), arraySequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == arraySequence->get(i));
    }
    std::cout << "True" << std::endl;
}

void MergeSortTestsList() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    LinkedListSequence<int> *listSequence = new LinkedListSequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, LinkedList<int>::Iterator> *iSort1 = new ISort<int, LinkedList<int>::Iterator>;
    iSort1->MergeSortList(listSequence->begin(), listSequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == listSequence->get(i));
    }
    std::cout << "True" << std::endl;
}

void InsertionSortTestsArray() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, DynamicArray<int>::Iterator> *iSort = new ISort<int, DynamicArray<int>::Iterator>;
    iSort->InsertionSort(arraySequence->begin(), arraySequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == arraySequence->get(i));
    }
    std::cout << "True" << std::endl;
}

void InsertionSortTestsList() {
    int a[] = {5, 8, 15, 22, 58, 100, 12, 89, 54, 76, 23, 84, 1, 0, 0, 88, 11, 3, 55, 9};
    int size = 20;
    LinkedListSequence<int> *listSequence = new LinkedListSequence<int>(a, size);
    Comparator<int> *comparator = new Comparator<int>;
    ISort<int, LinkedList<int>::Iterator> *iSort1 = new ISort<int, LinkedList<int>::Iterator>;
    iSort1->InsertionSort(listSequence->begin(), listSequence->rbegin(), comparator->increase);
    int right[] = {0, 0, 1, 3, 5, 8, 9, 11, 12, 15, 22, 23, 54, 55, 58, 76, 84, 88, 89, 100};
    ArraySequence<int> *arraySequenceRight = new ArraySequence<int>(right, size);
    for (int i = 0; i < size; i++) {
        assert(arraySequenceRight->get(i) == listSequence->get(i));
    }
    std::cout << "True" << std::endl;
}

#endif //LAB_ITERATORS_TESTS_HPP
