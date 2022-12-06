#ifndef LAB_ITERATORS_LINKEDLIST_HPP
#define LAB_ITERATORS_LINKEDLIST_HPP

#include <iostream>

template<class T>
class ListNode {
public:
    T value;
    ListNode<T> *pNext;
    ListNode<T> *pPrev;
};

template<class T>
class LinkedList {
private:
    ListNode<T> *first = nullptr;
    ListNode<T> *last = nullptr;
    ListNode<T> *sorted;
    int count;

    void copy(LinkedList<T> *obj) {
        this->clear();
        ListNode<T> *t = obj->first;
        for (int i = 0; i < obj->count; i++) {
            this->append(t->value);
            t = t->pNext;
        }

        this->count = obj->count;
    }

public:
    LinkedList() {
        this->first = nullptr;
        this->last = nullptr;
        this->count = 0;
    }

    LinkedList(LinkedList<T> *obj) {
        this->copy(obj);
    }

    LinkedList(T *array, int n) {
        for (int i = 0; i < n; i++) {
            this->append(array[i]);
        }

        this->count = n;
    }

    ~LinkedList() {
        this->clear();
    }

    ListNode<T> *move(int index) {
        if (this->count > 0) {
            ListNode<T> *t = this->first;
            for (int i = 0; i < index; i++) {
                t = t->pNext;
            }
            return t;
        }
        return nullptr;
    }

    const T &get(int index) {
        if (this->count > 0) {
            ListNode<T> *t = this->first;
            for (int i = 0; i < index; i++) {
                t = t->pNext;
            }
            return t->value;
        }

    }


    void append(const T &data) {
        ListNode<T> *node = new ListNode<T>;
        node->value = data;
        node->pNext = nullptr;
        node->pPrev = this->last;
        if (this->first == nullptr) {
            this->first = this->last = node;
        } else {
            this->last->pNext = node;
            this->last = node;

        }
        this->count++;
    }


    void prepend(const T &data) {
        ListNode<T> *node = new ListNode<T>;
        node->value = data;
        node->pNext = nullptr;
        node->pPrev = nullptr;
        if (this->first == nullptr) {
            this->first = this->last = node;
        } else {
            node->pNext = this->first;
            this->first->pPrev = node;
            this->first = node;
        }
        this->count++;
    }

    void deleteElement(int index) {
        if (this->count == 0)
            return;
        if ((index < 0) || (index >= this->count))
            return;
        if (index == 0) {
            ListNode<T> *element = this->first;
            this->first = this->first->pNext;
            this->first->pPrev = nullptr;
            delete element;
        } else {
            ListNode<T> *element = this->move(index - 1);
            ListNode<T> *element2 = element->pNext;
            ListNode<T> *element3 = element2->pNext;
            element->pNext = element2->pNext;
            element3->pPrev = element;
            delete element2;
        }
        this->count--;
    }

    void clear() {
        while (this->first != nullptr)
            deleteElement(0);
    }

    int getLength() {
        return this->count;
    }

    T &operator[](int index) {
        if ((index < 0) || (index >= this->count)) {
            throw "Incorrect index.";
        }

        ListNode<T> *element = this->move(index);
        return element->value;
    }

    void insert(const T &data, int index) {
        if ((this->count != 0) && ((index < 0) || (index >= this->count))) {
            return;
        }

        ListNode<T> *element = this->move(index);

        if (element == nullptr) {
            this->append(data);
        } else {
            ListNode<T> *element2 = new ListNode<T>;
            element2->value = data;
            if (index == 0) {
                element2->pNext = this->first;
                this->first->pPrev = element2;
                this->first = element2;
            } else {
                element = this->move(index - 1);
                ListNode<T> *element3 = element->pNext;
                element2->pNext = element->pNext;
                element3->pPrev = element2;
                element2->pPrev = element;
                element->pNext = element2;
            }
        }
        this->count++;
    }

    const T &getFirst() {
        if (this->first != nullptr)
            return this->first->value;
        else
            throw "Error";
    }


    const T &getLast() {
        if (this->first != nullptr)
            return this->last->value;
        else
            throw "Error";
    }

    ListNode<T> *getFirstElement() {
        if (this->first != nullptr)
            return this->first;
        else
            throw "Error";
    }

    ListNode<T> *getLastElement() {
        if (this->first != nullptr)
            return this->last;
        else
            throw "Error";
    }


    class Iterator {
    public:
        ListNode<T> *p = nullptr;
        int t = 2;

        Iterator(ListNode<T> *node) noexcept: p(node) {}

        Iterator() : p(nullptr) {}

        T &operator*() {
            return p->value;
        }

        Iterator &operator++() {
            p = p->pNext;
            return *this;
        }

        Iterator &operator++(int) {
            Iterator current = *this;
            ++(*this);
            return current;
        }

        Iterator &operator--() {
            p = p->pPrev;
            return *this;
        }

        Iterator &operator--(int) {
            Iterator current = *this;
            --(*this);
            return current;
        }

        bool operator==(Iterator other_element) {
            return p == other_element.p;
        }

        bool operator!=(Iterator other_element) {
            return p != other_element.p;
        }

        int *base() const {
            return p;
        }

        bool operator<(Iterator &a) {
            return p < a.p;
        }

        bool operator>(Iterator &a) {
            return p > a.p;
        }

        bool operator<=(Iterator &a) {
            return p <= a.p;
        }

        bool operator>=(Iterator &a) {
            return p >= a.p;
        }

        int *operator->() {
            return p;
        }

        Iterator operator+(Iterator &__i) {
            return Iterator(__i.base() + p);

        }

        Iterator operator-(Iterator &__i) {
            return Iterator(__i.base() - p);
        }
    };

    Iterator begin() {
        return Iterator(this->first);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator rend() {
        return Iterator(nullptr);
    }

    Iterator rbegin() {
        return Iterator(this->last);
    }
};

#endif //LAB_ITERATORS_LINKEDLIST_HPP
