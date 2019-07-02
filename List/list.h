//
// Created by Riton on 2019/7/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_LIST_H
#define DATA_STRUCTURE_BY_CPP_LIST_H

#include "node.h"

template <typename T>
class List {
private:
    int _size{};
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
    //constructors
    List() { init(); } //default constructor
    List(List<T> const &L); //construct from another list
    List(List<T> const &L, int r, int n); //construct from another list start at n, continues r nodes
    List(ListNodePosition<T> p, int n); //construct from n nodes after p
    ~List();

    //read-only
    int size() const { return _size; }
    bool empty() const { return _size <= 0; }
    T &operator[](int r) const;
    ListNodePosition<T> first() const { return header -> succeed; }
    ListNodePosition<T> last() const { return trailer -> precursor; }
    bool valid(ListNodePosition<T> p) const { return p && (trailer != p) && (header != p); }
    int is_ordered() const;
    ListNodePosition<T> find(T const &e) const { return find(e, header, trailer); }; //for disordered list without boundaries
    ListNodePosition<T> find(T const &e, int n, ListNodePosition<T> p) const; //for disordered list with boundaries
    ListNodePosition<T> search(T const &e) const { return search(e, header, trailer); }; //for ordered list without boundaries
    ListNodePosition<T> search(T const &e, int n, ListNodePosition<T> p) const; //for ordered list with boundaries
    ListNodePosition<T> max() const { return max(header->succeed, _size); }
    ListNodePosition<T> max(ListNodePosition<T> p, int n) const;

    //can-write
    ListNodePosition<T> insert_as_first(T const &e);
    ListNodePosition<T> insert_as_last(T const &e);
    ListNodePosition<T> insert_as_precursor(ListNodePosition<T> p, T const &e);
    ListNodePosition<T> insert_as_succeed(ListNodePosition<T> p, T const &e);
    T remove(ListNodePosition<T> p);
    void merge(List<T> &L) { merge(first(), _size, L, L.first(), L._size); }
    void sort(ListNodePosition<T> p, int n); //sort n nodes after p
    void sort() { sort(first(), _size); } //sort all
    int deduplicate();
    int uniquify();
    void reverse();

    //traverse
    void traverse( void (*) (T &));
    template <typename VST> void traverse( VST &);
};

template<typename T>
void List<T>::init() {
    header = new ListNode<T>();
    trailer = new ListNode<T>();
    header -> succeed = trailer;
    header -> precursor = nullptr;
    trailer -> precursor = header;
    trailer -> succeed = nullptr;
    _size = 0;
}

template<typename T>
int List<T>::clear() {
    //TODO
    return 0;
}

template<typename T>
void List<T>::copyNodes(ListNodePosition<T>, int) {
    //TODO

}

template<typename T>
void List<T>::merge(ListNodePosition<T> &, int, List, ListNodePosition<T>, int) {
    //TODO

}

template<typename T>
void List<T>::merge_sort(ListNodePosition<T> &, int) {
    //TODO

}

template<typename T>
void List<T>::selection_sort(ListNodePosition<T>, int) {
    //TODO

}

template<typename T>
void List<T>::insertion_sort(ListNodePosition<T>, int) {
    //TODO

}

template<typename T>
List<T>::List(const List<T> &L) {
    //TODO

}

template<typename T>
List<T>::List(const List<T> &L, int r, int n) {
    //TODO

}

template<typename T>
List<T>::List(ListNodePosition<T> p, int n) {
    //TODO

}

template<typename T>
List<T>::~List() {
    //TODO

}

template<typename T>
T &List<T>::operator[](int r) const {
    ListNodePosition<T> p = first();
    while (r-- > 0)
        p = p->succeed;
    return p->data;
}

template<typename T>
int List<T>::is_ordered() const {
    //TODO
    return 0;
}

template<typename T>
ListNodePosition<T> List<T>::find(const T &e, int n, ListNodePosition<T> p) const {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::search(const T &e, int n, ListNodePosition<T> p) const {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::max(ListNodePosition<T> p, int n) const {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_first(const T &e) {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_last(const T &e) {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_precursor(ListNodePosition<T> p, const T &e) {
    //TODO
    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_succeed(ListNodePosition<T> p, const T &e) {
    //TODO
    return nullptr;
}

template<typename T>
T List<T>::remove(ListNodePosition<T> p) {
    //TODO
    return nullptr;
}

template<typename T>
void List<T>::sort(ListNodePosition<T> p, int n) {
    //TODO

}

template<typename T>
int List<T>::deduplicate() {
    //TODO
    return 0;
}

template<typename T>
int List<T>::uniquify() {
    //TODO
    return 0;
}

template<typename T>
void List<T>::reverse() {
    //TODO

}

template<typename T>
void List<T>::traverse(void (*)(T &)) {
    //TODO

}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &) {
    //TODO
}

#endif //DATA_STRUCTURE_BY_CPP_LIST_H
