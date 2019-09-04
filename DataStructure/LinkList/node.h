//
// Created by Riton on 2019/6/29.
//

#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T value;
    Node<T> *next;
    Node() = default;
    Node(Node<T> *prior, T value);
    Node(T value, Node<T> *next);
    Node(Node<T> *prior, T value, Node<T> *next);
};


template<typename T>
Node<T>::Node(Node<T> *prior, T value) : value(value), next(nullptr) {
    prior->next = this;
}

template <typename T>
Node<T>::Node(T value, Node *next) : value(value), next(next) {}

template<typename T>
Node<T>::Node(Node<T> *prior, T value, Node<T> *next) : value(value), next(next) {
    prior->next = this;
}


#endif //CMAKETEST_NODE_H
