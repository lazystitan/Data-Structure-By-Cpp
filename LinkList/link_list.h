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
//    Node<T> *pointer;
    void init();
    Node<T> *get_p_to_position(int position) const;
    Node<T> *get_p_to_before_position(int position) const;
public:
    LinkList();
    LinkList(T arr[], int size);
    int len() const;
    T get(int position) const;
    //返回引用可以修改，但同时也是const, 或许我不该返回一个引用，或者不该加上const？
    //Returned value can be changed, which is change the value inside the list.
    //However, the function can be add const, may I should't return a refference ,
    //or I should't add const to it?
    T &get_ref(int position) const;
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
    length = 0;
}

template<typename T>
LinkList<T>::LinkList() {
    init();
}

template<typename T>
LinkList<T>::LinkList(T arr[], int size) {
    init();
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
T &LinkList<T>::get_ref(int position) const {
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


#endif //DATA_STRUCTURE_BY_CPP_LINK_LIST_H
