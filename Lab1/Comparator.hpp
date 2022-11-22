#ifndef LAB_ITERATORS_COMPARATOR_HPP
#define LAB_ITERATORS_COMPARATOR_HPP

template<class T>
class Comparator {
public:
    static bool increase(const T &a, const T &b) {
        return a > b;
    }

    static bool descending(const T &a, const T &b) {
        return a < b;
    }
};

#endif //LAB_ITERATORS_COMPARATOR_HPP
