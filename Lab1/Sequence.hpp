//
// Created by ekate on 31.10.2022.
//

#ifndef LAB_ITERATORS_SEQUENCE_HPP
#define LAB_ITERATORS_SEQUENCE_HPP
template<typename T>//= BaseIterator <T>
class Sequence {
protected:
    int length;
public:
    virtual void append (const T& data) = 0;
    virtual void prepend(const T& data) = 0;
    virtual void insert(int index, const T& data) = 0;
    virtual const T& get(int index) = 0;
    virtual int getLength () = 0;
    virtual T& operator[](int index) = 0;
    virtual const T& getFirst() = 0;
    virtual const T& getLast() = 0;

};
#endif //LAB_ITERATORS_SEQUENCE_HPP
