//
// Created by Riton on 2019/6/30.
//

#ifndef DATA_STRUCTURE_BY_CPP_LINK_LIST_H
#define DATA_STRUCTURE_BY_CPP_LINK_LIST_H

#include "node.h"

//first way to put overload of iostream operator outside class template
//template <typename T> class LinkList;
//template <typename T> std::ostream &operator<<(std::ostream &os, const LinkList<T> &list);

template <typename T>
class LinkList {
private:
    int length;
    Node<T> *head;
    Node<T> *get_p_to_position(int position) const;
    Node<T> *get_p_to_before_position(int position) const;
public:
    LinkList();
    LinkList(const LinkList<T> &list);
    LinkList(T arr[], int size);
    int len() const;
    bool empty() const { return length <= 0; }
    T get(int position) const;
    T &get_ref(int position);
    void put(T value);
    T pop();
    void insert(T value, int position);
    void del(int position);
    void rev();
    void sort();
    ~LinkList();

    T &operator[](int position);

//first way
//friend std::ostream &operator<< <T>(std::ostream &os, const LinkList<T> &list);

//second way
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const LinkList<U> &list);
};

template <typename T>
LinkList<T>::LinkList() {
    head = new Node<T>();
    length = 0;
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T> &list) {
    head = new Node<T>();
    length = list.length;
    Node<T> *p = head, *q = list.head;
    while (q) {
        p = new Node<T>(p,q->value);
        q = q ->next;
    }
    p -> next = nullptr;
}

template<typename T>
LinkList<T>::LinkList(T arr[], int size) {
    head = new Node<T>();
    length = size;
    Node<T> *p = head;
    for (int i = 0; i < size; i++)
        p = new Node<T>(p, arr[i]);
    p -> next = nullptr;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkList<T> &list) {
    auto p = list.head -> next;
    while (p != nullptr)
    {
        os << p->value <<" ";
        p = p -> next;
    }
    return os;
}

template<typename T>
int LinkList<T>::len() const {
    return length;
}

template<typename T>
void LinkList<T>::insert(T value, int position) {
    if (position > length - 1) {
        exit( 2 );
    }
    Node<T> *p = this->get_p_to_before_position(position);
    new Node<T>(p, value, p->next);
    length++;
}

template<typename T>
void LinkList<T>::put(T value) {
    Node<T> *p = head;
    while (p -> next) {
        p = p -> next;
    }

    new Node<T>(p, value, p ->next);
    length++;
}

template<typename T>
T LinkList<T>::pop() {
    Node<T> *p = head;
    while (p -> next -> next) {
        p = p ->next;
    }
    T result = p ->next ->value;
    delete p -> next;
    p -> next = nullptr;
    length--;
    return result;
}

template<typename T>
T LinkList<T>::get(int position) const {
    if (position > length - 1) {
        exit( 2 );
    }

    Node<T> *p = this->get_p_to_position(position);
    return p->value;
}

template<typename T>
void LinkList<T>::del(int position) {
    if (position > length - 1) {
        exit( 2 );
    }

    Node<T> *now = this->get_p_to_before_position(position);

    Node<T> *pre = now;
    now = now -> next;
    pre -> next = now -> next;
    delete now;
    length--;
}

template<typename T>
void LinkList<T>::rev() {
    Node<T> *pre = head -> next,
        *now = pre -> next,
        *after = now -> next;

    pre -> next = nullptr;
    while (after) {
        now -> next = pre;
        pre = now;
        now = after;
        after = after -> next;
    }

    now -> next = pre;
    head -> next = now;
}

template<typename T>
LinkList<T>::~LinkList() {
    Node<T> *p = head;
    while (p) {
        head = p;
        p = p->next;
        delete head;
    }
}

template<typename T>
T &LinkList<T>::operator[](int position) {
    if (position > length - 1) {
        exit( 2 );
    }
    Node<T> *p = this->get_p_to_position(position);
    T &value_r = p->value;
    return value_r;
}

template<typename T>
T &LinkList<T>::get_ref(int position) {
    if (position > length - 1) {
        exit( 2 );
    }
    Node<T> *p = this->get_p_to_position(position);
    T &r = p->value;
    return r;
}

template<typename T>
Node<T> *LinkList<T>::get_p_to_position(int position) const {
    Node<T> *p = this->get_p_to_before_position(position);
    return p -> next;
}

template<typename T>
Node<T> *LinkList<T>::get_p_to_before_position(int position) const {
    Node<T> *p = head;
    int number = 0;
    while (number < position) {
        number++;
        p = p ->next;
    }
    return p;
}

template<typename T>
void LinkList<T>::sort() {
    //TODO
}

#endif //DATA_STRUCTURE_BY_CPP_LINK_LIST_H
