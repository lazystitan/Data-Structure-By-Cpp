//
// Created by Riton on 2019/7/8.
//

#ifndef DATA_STRUCTURE_BY_CPP_STACK_H
#define DATA_STRUCTURE_BY_CPP_STACK_H

#include "../Vector/vector.h"

template <typename T>
class Stack : public Vector<T>
{
public:
    using Vector<T>::insert;
    using Vector<T>::remove;
    using Vector<T>::operator[];
    using Vector<T>::size;
    void push(T const &e) { insert(size(), e); }
    T pop() { return remove(size() - 1); }
    T &top() { return  (*this)[size() - 1]; }
//    void push( T const &e) { this->insert(this->size(), e);}
//    T pop() { return this->remove(this->size() - 1); }
//    T &__top() { return this->operator[](this->size()-1); }
};

#endif //DATA_STRUCTURE_BY_CPP_STACK_H
