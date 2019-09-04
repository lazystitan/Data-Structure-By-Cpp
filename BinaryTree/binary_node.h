//
// Created by Riton on 2019/9/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_BINARY_NODE_H
#define DATA_STRUCTURE_BY_CPP_BINARY_NODE_H

#include <cstdlib>
#include "../Queue/queue.h"

#define stature(p) ((p) ? (p)->height : -1)

typedef enum {RB_RED, RB_BLACK} RBColor;

template <typename T>
struct BinNode {
    T data;
    BinNode * parent, * left_child, * right_child;
    int height;
    int null_path_length;
    RBColor color;

    BinNode() :
        parent(nullptr), left_child(nullptr), right_child(nullptr), height(0), null_path_length(1), color(RB_RED) {}

    explicit BinNode(T e, BinNode * p = nullptr, BinNode * l = nullptr, BinNode * r = nullptr,
            int h = 0, int npl = 1, RBColor c = RB_RED):
            data(e), parent(p), left_child(l), right_child(r), height(h), null_path_length(l), color(c) {}

    int size();
    BinNode* insert_as_left_child(T const&);
    BinNode* insert_as_right_child(T const&);
    BinNode* succeed();
    template <typename VST>
    void trav_level(VST &visit);
    template <typename VST>
    void trav_pre(VST &visit);
    template <typename VST>
    void trav_in(VST &visit);
    template <typename VST>
    void trav_post(VST &visit);
    bool operator<(BinNode const& bn) {
        return data < bn.data;
    }
    bool operator==(BinNode const& bn) {
        return data == bn.data;
    }
};

#define is_root(x) (!((x).parent))
#define is_left_child (!is_root(x) && (&(x) == (x).parent->left_child))
#define is_right_child (!is_root(x) && (&(x) == (x).parent->right_child))
#define has_parent(x) (!is_root(x))
#define has_left_child(x) ((x).left_child)
#define has_right_child(x) ((x).right_child)
#define has_child(x) (has_left_child(x) || has_right_child(x))
#define has_both_child(x) (has_left_child(x) && has_right_child(x))
#define is_leaf(x) (!has_child(x))
#define sibling(p) \
    (is_left_child(*(p)) ? (p)->parent->rc : (p)->parent->lc)
#define ucle(x) \
    (is_left_child(*((x)->parent)) ? (x)->parent->parent->right_child : (x)->parent->parent->left_child)
//may error
#define from_parent_to(x) \
    (is_root(x) ? _root : (is_left_child(x) ? (x).parent->left_child : (x).parent->right_child))

template <typename T>
BinNode<T> * BinNode<T>::insert_as_left_child(T const& e) {
    return  left_child = new BinNode(e, this);
}

template <typename T>
BinNode<T> * BinNode<T>::insert_as_right_child(T const& e) {
    return  right_child = new BinNode(e, this);
}

template<typename T>
BinNode<T> *BinNode<T>::succeed() {
//    TODO
    return nullptr;
}

template<typename T>
int BinNode<T>::size() {
    return (this->right_child ? this->right_child->size(): 0)//right
    + (this->left_child ? this->left_child->size() : 0)//left
    + 1;//this node
}

template<typename T>
template<typename VST>
void BinNode<T>::trav_level(VST &visit) {
    Queue<BinNode<T> *> queue;
    queue.enqueue(this);
    while (!queue.empty()) {
        BinNode<T> * x = queue.dequeue();
        visit(queue.dequeue());
        if (has_left_child(*x))
            queue.enqueue(x->left_child);
        if (has_right_child(*x))
            queue.enqueue(x->right_child);
    }
}

template<typename T>
template<typename VST>
void BinNode<T>::trav_pre(VST &visit) {
    if (!this)
        return;
    visit(this->data);
    trav_pre(this->left_child);
    trav_pre(this->right_child);
}

template<typename T>
template<typename VST>
void BinNode<T>::trav_post(VST &visit) {
    if (!this)
        return;
    trav_post(this->left_child);
    trav_post(this->right_child);
    visit(this->data);
}

template<typename T>
template<typename VST>
void BinNode<T>::trav_in(VST &visit) {
//        many kinds of in trav
//    switch (rand() % 5) {
//        case 1: trav_in_i1(this, visit); break;
//        case 2: trav_in_i2(this, visit); break;
//        case 3: trav_in_i3(this, visit); break;
//        case 4: trav_in_i4(this, visit); break;
//        default: trav_in_r(this, visit); break;
//    }
    if (!this)
        return;
    trav_in(this->left_child);
    visit(this->data);
    trav_in(this->right_child);
}


#endif //DATA_STRUCTURE_BY_CPP_BINARY_NODE_H
