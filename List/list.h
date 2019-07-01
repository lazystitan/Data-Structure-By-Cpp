//
// Created by Riton on 2019/7/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_LIST_H
#define DATA_STRUCTURE_BY_CPP_LIST_H

#include "node.h"

template <typename T>
class List {
private:
    int _size;
    ListNodePosition<T> header, trailer;
protected:
    void init();
    int clear();
    //Copy n nodes after p
    void copyNodes(ListNodePosition<T>, int);
    //Merge
    void merge( ListNodePosition<T> &, int, List, ListNodePosition<T>, int);
    //Using merge / selection / insertion sort to sort n nodes after p
    void merge_sort(ListNodePosition<T> &, int);
    void selection_sort(ListNodePosition<T>, int);
    void insertion_sort(ListNodePosition<T>, int);

public:
};

template<typename T>
void List<T>::init() {

}

template<typename T>
int List<T>::clear() {
    return 0;
}

template<typename T>
void List<T>::copyNodes(ListNodePosition<T>, int) {

}

template<typename T>
void List<T>::merge(ListNodePosition<T> &, int, List, ListNodePosition<T>, int) {

}

template<typename T>
void List<T>::merge_sort(ListNodePosition<T> &, int) {

}

template<typename T>
void List<T>::selection_sort(ListNodePosition<T>, int) {

}

template<typename T>
void List<T>::insertion_sort(ListNodePosition<T>, int) {

}

#endif //DATA_STRUCTURE_BY_CPP_LIST_H
