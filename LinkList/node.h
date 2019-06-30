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
Node<T>::Node(Node<T> *prior, T value) {
    prior->next = this;
    this->value = value;
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(T value, Node *next) {
    this->value = value;
    this->next = next;
}

template<typename T>
Node<T>::Node(Node<T> *prior, T value, Node<T> *next) {
    prior->next = this;
    this->value = value;
    this->next = next;
}


#endif //CMAKETEST_NODE_H
