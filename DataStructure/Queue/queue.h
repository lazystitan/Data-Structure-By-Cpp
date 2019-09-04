//
// Created by Riton on 2019/8/31.
//

#ifndef DATA_STRUCTURE_BY_CPP_QUEUE_H
#define DATA_STRUCTURE_BY_CPP_QUEUE_H

#include "../List/list.h"

template <typename T>
class Queue : public List<T> {

public:
    using List<T>::insert_as_last;
    using List<T>::first;
    using List<T>::remove;

    void enqueue(T const& data) {
        insert_as_last(data);
    }

    T dequeue() {
        return remove(first());
    }

    T& front() {
        return first()->data;
    }

};

#endif //DATA_STRUCTURE_BY_CPP_QUEUE_H
