//
// Created by Riton on 2019/7/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_LIST_H
#define DATA_STRUCTURE_BY_CPP_LIST_H

//#include <assert.h>
#include <cassert>
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
    void merge( ListNodePosition<T> &, int, List<T> &, ListNodePosition<T>, int);
    //Using merge / selection / insertion sort to sort n nodes after p
    void merge_sort(ListNodePosition<T> &, int);
    void selection_sort(ListNodePosition<T>, int);
    void insertion_sort(ListNodePosition<T>, int);

    ListNodePosition<T> get_pointer(int r) const;

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
    bool is_ordered() const; // any pre-data is bigger than the data after it
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
    int old_size = _size;
    while (_size > 0) {
        remove(header->succeed);
    }
    return 0;
}

template<typename T>
void List<T>::copyNodes(ListNodePosition<T> p, int n) {
    init();
    while (n--){
        insert_as_last(p->data);
        p = p->succeed;
        assert(p);
    }

}

template<typename T>
void List<T>::merge(ListNodePosition<T> &p, int n, List &L, ListNodePosition<T> q, int m) {
    ListNodePosition<T> prep = p->precursor;
    while (m > 0) {
        if ((n > 0) && (p->data <= q->data)) {
            if (q == (p = p->succeed))
                break;
            n--;
        } else {
            insert_as_precursor(p, L.remove((q = q->succeed)->precursor));
            m--;
        }
    }
    p = prep->succeed;
}

template<typename T>
void List<T>::merge_sort(ListNodePosition<T> &p, int n) {
    if (n < 2) {
        return;
    }
    int m = n >> 1;
    ListNodePosition<T> q = p;
    for (int i = 0; i < m; ++i)
        q = q->succeed;
    merge_sort(p, m);
    merge_sort(q, n - m);
    merge(p, m, *this, q, n - m);
}

template<typename T>
void List<T>::selection_sort(ListNodePosition<T> p, int n) {
    ListNodePosition<T> head = p->precursor, tail = p;
    for (int i = 0; i < n; ++i) {
        tail = tail->succeed;
    }
    while (n > 1) {
        ListNodePosition<T> max = this->max(head->succeed, n);
        insert_as_precursor(tail, remove(max));
        tail = tail->precursor;
        n--;
    }
}

template<typename T>
void List<T>::insertion_sort(ListNodePosition<T> p, int n) {
    for (int r = 0; r < n; ++r) {
        insert_as_succeed(search(p->data, r, p), p->data);
        p = p->succeed;
        remove(p->precursor);
    }

}

template<typename T>
List<T>::List(const List<T> &L) {
    copyNodes(L.first(), L._size);
}

template<typename T>
List<T>::List(ListNodePosition<T> p, int n) {
    assert(valid(p));
    copyNodes(p, n);
}

template<typename T>
List<T>::List(const List<T> &L, int r, int n) {
    assert((n + r) <= L._size) ;
    copyNodes(L.get_pointer(r), n);
}

template<typename T>
List<T>::~List() {
    clear();
    delete header;
    delete trailer;
}

template<typename T>
T &List<T>::operator[](int r) const {
    ListNodePosition<T> p = first();
    while (r-- > 0)
        p = p->succeed;
    return p->data;
}

template<typename T>
bool List<T>::is_ordered() const {
    ListNodePosition<T> p = header->succeed;
    while ((p = p->succeed) != trailer)
        if (p->data < p->precursor->data)
            return false;
    return true;
}

template<typename T>
ListNodePosition<T> List<T>::find(const T &e, int n, ListNodePosition<T> p) const {
    while (n-- > 0)
        if (e == (p = p->precursor)->data)
            return p;

    return nullptr;
}

template<typename T>
ListNodePosition<T> List<T>::search(const T &e, int n, ListNodePosition<T> p) const {
    while (n-- <= 0)
        if (((p = p->precursor)->data) <= e)
            break;
    return p;
}

template<typename T>
ListNodePosition<T> List<T>::max(ListNodePosition<T> p, int n) const {
    ListNodePosition<T> max = p;
    for (ListNodePosition<T> cur = p;  n > 1; n--)
        if (!(cur = cur->succeed)->data > max -> data)
            max = cur;
    return max;
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_first(const T &e) {
    _size++;
    return header->insert_as_succeed(e);
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_last(const T &e) {
    _size++;
    return trailer->insert_as_precursor(e);
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_precursor(ListNodePosition<T> p, const T &e) {
    _size++;
    return p->insert_as_precursor(e);
}

template<typename T>
ListNodePosition<T> List<T>::insert_as_succeed(ListNodePosition<T> p, const T &e) {
    return p->insert_as_succeed(e);
}

template<typename T>
T List<T>::remove(ListNodePosition<T> p) {
    T e = p->data;
    p->precursor = p->succeed;
    p->succeed->precursor = p->precursor;
    delete p;
    _size--;
    return e;
}

template<typename T>
void List<T>::sort(ListNodePosition<T> p, int n) {
    switch (rand() % 3) {
        case 1: insertion_sort(p, n);   break;
        case 2: selection_sort(p, n);   break;
        case 3: merge_sort(p, n);   break;
    }

}

template<typename T>
int List<T>::deduplicate() {
    if (_size < 2) {
        return 0;
    }

    int old_size = _size;
    ListNodePosition<T> p = header;
    int r = 0;
    while (trailer != (p = p->succeed)) {
        ListNodePosition<T> q = find(p->data, r, p);
        q ? remove(q) : r++;
    }

    return old_size - _size;
}

template<typename T>
int List<T>::uniquify() {
    if (_size < 2) {
        return 0;
    }

    int old_size = _size;
    ListNodePosition<T> p = first(), q;
    while ((q=p->succeed) != trailer)
        if (p->data != q->data)
            p = q;
        else
            remove(q);

    return old_size - _size;
}

template<typename T>
void List<T>::reverse() {
    ListNodePosition<T> temp = header;
    header = trailer;
    trailer = temp;
}

template<typename T>
void List<T>::traverse(void (*visit)(T &)) {
    for (ListNodePosition<T> p = header->succeed; p != trailer; p = p->succeed)
        visit(p->data);
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &visit) {
    for (ListNodePosition<T> p = header->succeed; p != trailer; p = p->succeed)
        visit(p->data);
}

template<typename T>
ListNodePosition<T> List<T>::get_pointer(int r) const {
    ListNodePosition<T> p = header->succeed;
    while (r-- > 0)
        p = p->succeed;
    return p;
}

#endif //DATA_STRUCTURE_BY_CPP_LIST_H
