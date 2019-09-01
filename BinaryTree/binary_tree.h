//
// Created by Riton on 2019/9/1.
//

#ifndef DATA_STRUCTURE_BY_CPP_BINARY_TREE_H
#define DATA_STRUCTURE_BY_CPP_BINARY_TREE_H

#include "binary_node.h"

template <typename T>
class BinTree {
protected:
    int _size;
    BinNode<T> * _root;
    virtual int update_height(BinNode<T> * x);
    void update_height_above(BinNode<T> * x);

public:
    BinTree() : _size(0), _root(nullptr) {}
    ~BinTree() {
        if (_size > 0)
            remove(_root);
    }
    int size() {
        return _size;
    };
    bool empty() {
        return _size == 0;
    }
    BinNode<T> * root() const {
        return _root;
    }
    BinNode<T> * insert_as_root(T const& e);
    BinNode<T> * insert_as_left_child(BinNode<T>* x, T const& e);
    BinNode<T> * insert_as_right_child(BinNode<T>* x, T const& e);
    BinNode<T> * attach_as_left_child(BinNode<T>* x, BinTree<T>* s);
    BinNode<T> * attach_as_right_child(BinNode<T>* x, BinTree<T>* s);
    int remove(BinNode<T> * x);
    BinTree<T>* secede(BinNode<T> * x);
    template <typename VST>
    void trav_level(VST& visit) {
        if (_root)
            _root->trav_level(visit);
    }template <typename VST>
    void trav_pre(VST& visit) {
        if (_root)
            _root->trav_pre(visit);
    }template <typename VST>
    void trav_in(VST& visit) {
        if (_root)
            _root->trav_in(visit);
    }template <typename VST>
    void trav_post(VST& visit) {
        if (_root)
            _root->trav_post(visit);
    }
    //Where is lt(BinNode<T> * , BinNode<T> *) comes from??
    bool operator<(BinTree<T> const& t) {
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const& t) {
        return _root && t._root && (_root == t._root);
    }

};

template<typename T>
int BinTree<T>::update_height(BinNode<T> *x) {
    int lh = stature(x->left_child), rh = stature(x->right_child);
    return x->height = 1 + (lh > rh ? lh : rh);
}

template<typename T>
void BinTree<T>::update_height_above(BinNode<T> *x) {
    //first version, can be optimized
    while (x) {
        update_height(x);
        x = x->parent;
    }
}

template<typename T>
BinNode<T> *BinTree<T>::insert_as_root(const T &e) {
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNode<T> *BinTree<T>::insert_as_left_child(BinNode<T>* x, const T &e) {
    _size++;
    x->insert_as_left_child(e);
    return x->left_child;
}

template<typename T>
BinNode<T> *BinTree<T>::insert_as_right_child(BinNode<T>* x, const T &e) {
    _size++;
    x->insert_as_right_child(e);
    return x->right_child;
}

template<typename T>
BinNode<T> *BinTree<T>::attach_as_left_child(BinNode<T>* x, BinTree<T>* s) {
    if (x->left_child = s->_root)
        x->left_child->parent = x;
    _size += s->_size;
    update_height_above(x);
    s->_root = nullptr;
    s->_size = 0;
//    wtf
//    release(x)
//    delete s;
    s->~BinTree();
    s = nullptr;
    return x;
}

template<typename T>
BinNode<T> *BinTree<T>::attach_as_right_child(BinNode<T>* x, BinTree<T>* s) {
    if (x->right_child = s->_root)
        x->right_child->parent = x;
    _size += s->_size;
    update_height_above(x);
    s->_root = nullptr;
    s->_size = 0;
//    wtf
//    release(x)
//    delete s;
    s->~BinTree();
    s = nullptr;
    return x;
}

template<typename T>
int BinTree<T>::remove(BinNode<T> *x) {
    return 0;
}

//delete subtree
template<typename T>
BinTree<T> *BinTree<T>::secede(BinNode<T> *x) {
//    wtf
    from_parent_to(*x) = nullptr;
    update_height_above(x->parent);
    BinTree<T>* s = new BinTree<T>;
    s->_root = x;
    x->parent = nullptr;
    s->_size = x->size();
    _size -= s->_size;
    return s;
}

#endif //DATA_STRUCTURE_BY_CPP_BINARY_TREE_H
