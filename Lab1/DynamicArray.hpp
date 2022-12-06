#ifndef LAB_ITERATORS_DYNAMICARRAY_HPP
#define LAB_ITERATORS_DYNAMICARRAY_HPP

template<class T>
class DynamicArray {
private:
    int size;
    int capacity;
    T *items;
public:
    DynamicArray() {
        this->size = 0;
        this->items = nullptr;
        this->capacity = 0;
    }

    DynamicArray(DynamicArray<T> *array) {
        this->size = array->size;
        this->capacity = this->size;
        if (this->size != 0)
            this->items = new T[size];
        else
            this->items = nullptr;
        for (int i = 0; i < this->size; i++)
            this->items[i] = array->items[i];
    }

    DynamicArray(int size) {
        this->size = size;
        this->capacity = size;
        if (this->size != 0)
            this->items = new T[this->size];
        else this->items = nullptr;
    }

    DynamicArray(T *array, int n) {
        this->size = n;
        this->capacity = n;
        if (this->size != 0) {
            this->items = new T[this->size];

            for (int i = 0; i < this->size; i++) {
                this->items[i] = array[i];
            }
        } else this->items = nullptr;
    }

    ~DynamicArray() {
        if (this->items)
            delete[] this->items;
    }

    void resize(int size) {
        if (size > this->capacity) {
            int newCapasity;
            if (size >= 2 * this->size) {
                newCapasity = size;
            } else {
                newCapasity = 2 * this->size;
            }


            T *newItems = new T[newCapasity];
            for (int i = 0; i < this->size; i++)
                newItems[i] = this->items[i];
            delete[] this->items;
            this->items = newItems;
            this->capacity = newCapasity;
        }
        this->size = size;
    }

    void pushBack(const T &data) {
        this->resize(this->size + 1);
        this->items[this->size + 1] = data;
    }

    void pushBegin(const T &data) {
        this->resize(this->size + 1);
        for (int i = this->size - 1; i > 0; i--) {
            this->items[i] = this->items[i - 1];
        }
        this->items[0] = data;
    }

    void insert(int index, const T &data) {
        if (index == 0) {
            this->pushBegin(data);
        }

        if (index == this->size) {
            this->pushBack(data);
        }

        if ((index > 0) && (index < this->size)) {
            this->resize(this->size + 1);
            for (int i = this->size - 1; i > index; i--) {
                this->items[i] = this->items[i - 1];
            }
            this->items[index] = data;
        }
    }

    T &operator[](int i) {
        return this->items[i];
    }

    const T &get(int index) {
        if ((this->size > 0) && (index >= 0) && (index < this->size)) {
            return this->items[index];
        }
    }

    int getLength() {
        return this->size;
    }

    class Iterator {
    public:
        T *p;

        Iterator(int *pv) {
            p = pv;
        }

        T &operator*() {
            return *p;
        }

        T operator*() const {
            return *p;
        }

        Iterator &operator++() {
            ++p;
            return *this;
        }

        Iterator operator++(int) {
            return Iterator(p++);
        }

        Iterator &operator--() {
            --p;
            return *this;
        }

        Iterator operator--(int) {
            return Iterator(p--);
        }

        int &operator[](const std::size_t &__n) { return p[__n]; }


        bool operator==(Iterator a) {
            return p == a.p;
        }

        bool operator!=(Iterator a) {
            return p != a.p;
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

        T *operator->() {
            return p;
        }

        Iterator operator+(Iterator &__i) {
            return Iterator(__i->base() + p);
        }
    };


    Iterator begin() {
        return Iterator(this->items);
    }

    Iterator end() {
        return this->items + (this->size);
    }

    Iterator rend() {
        return Iterator(this->items - 1);
    }

    Iterator rbegin() {
        return this->items + (this->size - 1);
    }

};

#endif //LAB_ITERATORS_DYNAMICARRAY_HPP
