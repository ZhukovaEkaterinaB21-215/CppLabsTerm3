#include <iostream>
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include <chrono>
#include <random>
#include "Comparator.hpp"
#include "ISorter.hpp"
#include "Tests.hpp"

void PrintArrayInt(ArraySequence<int> *arraySequence) {
    for (int i = 0; i < arraySequence->getLength() - 1; i++) {
        int a = arraySequence->get(i);
        std::cout << a << ", ";
    }
    int a = arraySequence->get(arraySequence->getLength() - 1);
    std::cout << a;
}

void PrintListInt(LinkedListSequence<int> *linkedListSequence) {
    for (int i = 0; i < linkedListSequence->getLength() - 1; i++) {
        int a = linkedListSequence->get(i);
        std::cout << a << ", ";
    }
    int a = linkedListSequence->get(linkedListSequence->getLength() - 1);
    std::cout << a;
}

const int t = 150;

int main() {
    Comparator<int> *comparator = new Comparator<int>;
    int a[t];
    srand(time(NULL));
    for (int i = 0; i < t; i++) {
        a[i] = 1 + rand() % 500000;
    }
    int count = t;
    ArraySequence<int> *arraySequenceQuickSort = new ArraySequence<int>(a, count);
    ArraySequence<int> *arraySequenceMergeSort = new ArraySequence<int>(a, count);
    ArraySequence<int> *arraySequenceInsertionSort = new ArraySequence<int>(a, count);
    LinkedListSequence<int> *linkedListSequenceQuickSort = new LinkedListSequence<int>(a, count);
    LinkedListSequence<int> *linkedListSequenceMergeSort = new LinkedListSequence<int>(a, count);
    LinkedListSequence<int> *linkedListSequenceInsertionSort = new LinkedListSequence<int>(a, count);

    ISort<int, DynamicArray<int>::Iterator> *iSort = new ISort<int, DynamicArray<int>::Iterator>;

    //Quick Sort. Array
    auto start = std::chrono::steady_clock::now();
    iSort->QuickSortArray(arraySequenceQuickSort->begin(), arraySequenceQuickSort->rbegin(), comparator->increase);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Quick Sort. Array:" << std::endl;
    auto diff = end - start;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;

    //Merge Sort. Array
    auto start1 = std::chrono::steady_clock::now();
    iSort->MergeSortArray(arraySequenceMergeSort->begin(), arraySequenceMergeSort->rbegin(), comparator->increase);
    auto end1 = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Merge Sort. Array:" << std::endl;
    auto diff1 = end1 - start1;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff1).count() << " ms" << std::endl;

    //Insertion Sort. Array
    auto start2 = std::chrono::steady_clock::now();
    iSort->InsertionSort(arraySequenceInsertionSort->begin(), arraySequenceInsertionSort->rbegin(),
                         comparator->increase);
    auto end2 = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Insertion Sort. Array:" << std::endl;
    auto diff2 = end2 - start2;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff2).count() << " ms" << std::endl;

    ISort<int, LinkedList<int>::Iterator> *iSort1 = new ISort<int, LinkedList<int>::Iterator>;

    //Quick Sort. List
    auto start3 = std::chrono::steady_clock::now();
    iSort1->QuickSortList(linkedListSequenceQuickSort->begin(), linkedListSequenceQuickSort->rbegin(),
                          comparator->increase);
    auto end3 = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Quick Sort. List:" << std::endl;
    auto diff3 = end3 - start3;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff3).count() << " ms" << std::endl;

    //Merge Sort. List
    auto start4 = std::chrono::steady_clock::now();
    iSort1->MergeSortList(linkedListSequenceMergeSort->begin(), linkedListSequenceMergeSort->rbegin(),
                          comparator->increase);
    auto end4 = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Merge Sort. List:" << std::endl;
    auto diff4 = end4 - start4;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff4).count() << " ms" << std::endl;

    //Insertion Sort. List
    auto start5 = std::chrono::steady_clock::now();
    iSort1->InsertionSort(linkedListSequenceInsertionSort->begin(), linkedListSequenceInsertionSort->rbegin(),
                          comparator->increase);
    auto end5 = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Insertion Sort. List:" << std::endl;
    auto diff5 = end5 - start5;
    std::cout << std::endl;
    std::cout << std::chrono::duration<double, std::milli>(diff5).count() << " ms" << std::endl;

    std::cout << std::endl;
    QuickSortTestsArray();
    QuickSortTestsList();
    MergeSortTestsArray();
    MergeSortTestsList();
    InsertionSortTestsArray();
    InsertionSortTestsList();
    return 0;
}
