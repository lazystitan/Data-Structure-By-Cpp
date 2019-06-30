//
// Created by Riton on 2019/6/30.
//

#ifndef DATA_STRUCTURE_BY_CPP_LINK_LIST_H
#define DATA_STRUCTURE_BY_CPP_LINK_LIST_H

#include "node.h"

//first way to put it outside class template
//template <typename T> class LinkList;
//template <typename T> std::ostream &operator<<(std::ostream &os, const LinkList<T> &list);

template <typename T>
class LinkList {
private:
    Node<T> *head;
//    Node<T> *pointer;
    void init();
public:
    LinkList();
    LinkList(T arr[], int size);
    int len() const;
    T get(int position) const;
    T &get_ref(int position);
    void put(T value);
    T pop();
    void insert(T value, int position);
    void del(int position);
    void rev();
    ~LinkList();

    T &operator[](int position);

//first way
//friend std::ostream &operator<< <T>(std::ostream &os, const LinkList<T> &list);

//second way
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const LinkList<U> &list);
};

template<typename T>
void LinkList<T>::init() {
    head = new Node<T>();
}

template<typename T>
LinkList<T>::LinkList() {
    init();
}

template<typename T>
LinkList<T>::LinkList(T arr[], int size) {
    init();
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
    auto *p = head -> next;
    int len = 0;
    while (p) {
        len ++;
        p = p -> next;
    }
    return len;
}

template<typename T>
void LinkList<T>::insert(T value, int position) {
    if (position > len() - 1) {
        exit( 2 );
    }

    Node<T> *p = head;
    int number = 0;
    while (number < position) {
        number++;
        p = p ->next;
    }
    new Node<T>(p, value, p->next);
}

template<typename T>
void LinkList<T>::put(T value) {
    Node<T> *p = head;
    while (p -> next) {
        p = p -> next;
    }

    new Node<T>(p, value, p ->next);

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

    return result;
}

template<typename T>
T LinkList<T>::get(int position) const {
    if (position > len() - 1) {
        exit( 2 );
    }

    Node<T> *p = head;
    int number = 0;
    while (number <= position) {
        number++;
        p = p ->next;
    }
    return p->value;
}

template<typename T>
void LinkList<T>::del(int position) {
    if (position > len() - 1) {
        exit( 2 );
    }

    Node<T> *now = head, *pre;
    int number = 0;
    while (number < position) {
        number++;
        now = now ->next;
    }

    pre = now;
    now = now -> next;
    pre -> next = now -> next;
    delete now;
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
    if (position > len() - 1) {
        exit( 2 );
    }

    Node<T> *p = head;
    int number = 0;
    while (number <= position) {
        number++;
        p = p ->next;
    }

    T &value_r = p->value;

    return value_r;
}

template<typename T>
T &LinkList<T>::get_ref(int position) {
    if (position > len() - 1) {
        exit( 2 );
    }

    Node<T> *p = head;
    int number = 0;
    while (number <= position) {
        number++;
        p = p ->next;
    }

    T &r = p->value;
    return r;
}


#endif //DATA_STRUCTURE_BY_CPP_LINK_LIST_H
