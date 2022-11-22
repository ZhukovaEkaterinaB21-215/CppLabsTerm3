#ifndef LAB_ITERATORS_ISORTER_HPP
#define LAB_ITERATORS_ISORTER_HPP

#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"

template<class T, class Iterator>
class ISort {
public:
    Iterator parition(Iterator first, Iterator last, bool comp(T a, T b)) {
        Iterator pivot = first;
        Iterator front = first;
        T temp = 0;
        while (front != nullptr && front != last) {
            if (comp(*last, *front)) {
                pivot = first;
                temp = *first;
                *first = *front;
                *front = temp;
                first++;
            }
            front++;
        }
        temp = *first;
        *first = *last;
        *last = temp;
        return pivot;
    }

    void QuickSortList(Iterator first, Iterator last, bool comp(T a, T b)) {
        if (first == last) {
            return;
        }
        Iterator pivot = parition(first, last, comp);
        Iterator pivot1 = pivot;
        pivot1++;
        if (pivot != nullptr && pivot1 != nullptr) {
            QuickSortList(pivot1, last, comp);
        }
        if (pivot != nullptr && first != pivot) {
            QuickSortList(first, pivot, comp);
        }
    }

    void QuickSortArray(Iterator first, Iterator last, bool comp(T a, T b)) {
        Iterator i = first, j = last;
        Iterator firstElement = i;
        Iterator middle = i;
        int count = 0;
        while (firstElement != last) {
            if (count % 2 == 1) {
                middle++;
            }
            firstElement++;
            count = count + 1;
        }
        T x = *middle;

        do {
            while (comp(x, *i)) {
                i++;
            }
            while (comp(*j, x)) {
                j--;
            }
            if (i <= j) {
                if (comp(*i, *j)) {
                    T tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last) {
            QuickSortArray(i, last, comp);
        }

        if (first < j) {
            QuickSortArray(first, j, comp);
        }
    }

    void InsertionSort(Iterator first, Iterator last, bool comp(T a, T b)) {
        T temp;
        int item;
        int size = 1;
        Iterator sizeArray = first;
        while (sizeArray != last) {
            size++;
            sizeArray++;
        }
        Iterator data = first;
        data++;
        for (int i = 1; i < size; i++) {
            temp = *data;
            item = i - 1;
            Iterator data2 = data;
            data2--;
            Iterator dataCount = data;
            while (item >= 0 && comp(*data2, temp)) {
                *dataCount = *data2;
                *data2 = temp;
                item--;
                data2--;
                dataCount--;
            }
            data++;
        }
    }

    void Merge(Iterator first, Iterator last, Iterator middle, bool comp(T a, T b)) {
        Iterator i = first;
        Iterator k = first;
        int size = 1;
        Iterator sizeArray = first;
        while (sizeArray != last) {
            size++;
            sizeArray++;
        }
        T data[size];
        Iterator middle1 = middle;
        middle1++;
        Iterator j = middle1;
        while (i <= middle && j <= last) {
            if (comp(*j, *i)) {
                Iterator firstCount = first;
                int counter = 0;
                while (firstCount != k) {
                    counter++;
                    firstCount++;
                }
                data[counter] = *i;
                k++;
                i++;
            } else {
                Iterator firstCount = first;
                int counter = 0;
                while (firstCount != k) {
                    counter++;
                    firstCount++;
                }
                data[counter] = *j;
                k++;
                j++;
            }
        }
        while (i <= middle) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != k) {
                counter++;
                firstCount++;
            }
            data[counter] = *i;
            k++;
            i++;
        }
        while (j <= last) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != k) {
                counter++;
                firstCount++;
            }
            data[counter] = *j;
            k++;
            j++;
        }
        for (i = first; i < k; i++) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != i) {
                counter++;
                firstCount++;
            }
            *i = data[counter];
        }
    }

    void MergeSortArray(Iterator first, Iterator last, bool comp(T a, T b)) {
        Iterator middle = first;
        if (first < last) {
            Iterator firstElement = first;
            middle = first;
            int count = 0;
            while (firstElement != last) {
                if (count % 2 == 1) {
                    middle++;
                }
                firstElement++;
                count = count + 1;
            }
            Iterator middle1 = middle;
            Iterator middle2 = middle;
            middle2++;
            MergeSortArray(first, middle1, comp);
            MergeSortArray(middle2, last, comp);
            Merge(first, last, middle1, comp);
        }
    }

    void MergeList(Iterator first, Iterator last, Iterator middle, bool comp(T a, T b)) {
        Iterator i = first;
        Iterator k = first;
        int size = 1;
        Iterator sizeArray = first;
        while (sizeArray != last) {
            size++;
            sizeArray++;
        }
        T data[size];
        Iterator middle1 = middle;
        middle1++;
        Iterator j = middle1;
        int c_i = 0;
        int c_j = 0;
        int c_middle = 0;
        int c_last = 0;
        Iterator counter_i = first;
        Iterator counter_j = first;
        Iterator counter_middle = first;
        Iterator counter_last = first;
        while ((counter_i != i) || (counter_j != j) || (counter_middle != middle) || (counter_last != last)) {
            if (counter_i != i) {
                counter_i++;
                c_i++;
            }

            if (counter_j != j) {
                counter_j++;
                c_j++;
            }

            if (counter_middle != middle) {
                counter_middle++;
                c_middle++;
            }

            if (counter_last != last) {
                counter_last++;
                c_last++;
            }
        }

        while (c_i <= c_middle && c_j <= c_last && i != nullptr && j != nullptr) {
            if (comp(*j, *i)) {
                Iterator firstCount = first;
                int counter = 0;
                while ((firstCount != k) && (firstCount != nullptr)) {
                    counter++;
                    firstCount++;
                }
                data[counter] = *i;
                k++;
                i++;
                c_i++;
            } else {
                Iterator firstCount = first;
                int counter = 0;
                while (firstCount != k && firstCount != nullptr) {
                    counter++;
                    firstCount++;
                }
                data[counter] = *j;
                k++;
                j++;
                c_j++;
            }
        }

        while (c_i <= c_middle && i != nullptr) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != k && firstCount != nullptr) {
                counter++;
                firstCount++;
            }
            data[counter] = *i;
            k++;
            i++;
            c_i++;
        }

        while (c_j <= c_last && j != nullptr) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != k && firstCount != nullptr) {
                counter++;
                firstCount++;
            }
            data[counter] = *j;
            k++;
            j++;
            c_j++;
        }

        Iterator c_k = k;
        //c_k--;
        for (i = first; i != k; i++) {
            Iterator firstCount = first;
            int counter = 0;
            while (firstCount != i) {
                counter++;
                firstCount++;
            }
            if (i != nullptr)
                *i = data[counter];
        }
    }

    void MergeSortList(Iterator first, Iterator last, bool comp(T a, T b)) {
        Iterator middle = first;
        int c_first = 0;
        int c_last = 0;
        Iterator counter_first = first;
        Iterator counter_last = first;
        while ((counter_first != first) || (counter_last != last)) {
            if (counter_first != first) {
                counter_first++;
                c_first++;
            }

            if (counter_last != last) {
                counter_last++;
                c_last++;
            }
        }

        if (c_first < c_last) {
            Iterator firstElement = first;
            middle = first;
            int count = 0;
            while (firstElement != last) {
                if (count % 2 == 1) {
                    middle++;
                }
                firstElement++;
                count = count + 1;
            }
            Iterator middle1 = middle;
            Iterator middle2 = middle;
            middle2++;
            MergeSortList(first, middle1, comp);
            MergeSortList(middle2, last, comp);
            MergeList(first, last, middle1, comp);
        }
    }
};

#endif //LAB_ITERATORS_ISORTER_HPP
