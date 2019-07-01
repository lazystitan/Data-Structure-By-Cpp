//
// Created by Riton on 2019/7/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_NODE_H
#define DATA_STRUCTURE_BY_CPP_NODE_H

template <typename T> struct ListNode;

template <typename T> using ListNodePosition = ListNode<T> *;

template <typename T>
struct ListNode {
    T data;
    ListNodePosition<T> precursor;
    ListNodePosition<T> succeed;

    ListNode() = default;

    ListNode(T e, ListNodePosition<T> p = nullptr, ListNodePosition<T> s = nullptr)
        : data(e), precursor(p), succeed(s){ };
    ListNodePosition<T> insert_as_precursor( T const &e);
    ListNodePosition<T> insert_as_succeed( T const &e);

};

template<typename T>
ListNodePosition<T> ListNode<T>::insert_as_precursor(const T &e) {
    auto *new_node = new ListNode(e, this->precursor, this);
    this->precursor->succeed = new_node;
    this->precursor = new_node;

    return new_node;
}

template<typename T>
ListNodePosition<T> ListNode<T>::insert_as_succeed(const T &e) {
    auto *new_node = new ListNode(e, this->succeed, this->succeed->succeed);
    this->succeed->precursor = new_node;
    this->succeed = new_node;

    return new_node;
}

#endif //DATA_STRUCTURE_BY_CPP_NODE_H
