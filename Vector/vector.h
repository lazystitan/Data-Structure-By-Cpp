//
// Created by Riton on 2019/7/4.
//

#ifndef DATA_STRUCTURE_BY_CPP_VECTOR_H
#define DATA_STRUCTURE_BY_CPP_VECTOR_H

#define DEFAULT_CAPACITY 1024

template <typename T>
class Vector {
protected:
    int _size;
    int _capacity;
    T *_element;

    void copy_from(T const* array, int low, int high);
    void expand();
    void shrink();
    bool bubble(int low, int high);
    void bubble_sort(int low, int high);
    int max(int low, int high);
    void selection_sort(int low, int high);
    void merge(int low, int middle, int high);
    void merge_sort(int low, int high);
    int partition(int low, int high);
    void quick_sort(int low, int high);
    void heap_sort(int low, int high);

public:
    //constructors and destructor
    Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T default_value = 0);
    Vector(T const * array, int n) { copy_from(array, 0, n); }
    Vector(T const * array, int low, int high) { copy_from(array, low, high); }
    Vector(Vector<T> const & vec) { copy_from(vec._element, vec._size); }
    Vector(Vector<T> const & vec, int low, int high) { copy_from(vec._element, low, high); }
    ~Vector() {delete [] _element; }

    //read-only
    int size() const { return _size; }
    bool empty() const { return !_size; }
    int is_ordered() const;
    int find(T const &e) const { find(e, 0, _size); }
    int find(T const &e, int low, int high) const;
    int search(T const &e) const { return ( 0>= _size) ? -1: search(e, 0, _size); }
    int search(T const &e, int low, int high) const;

    //can-write
    T &operator[](int r) const;
    Vector<T> &operator=(Vector<T> const &vec);
    T remove(int r);
    int remove(int low, int high);
    int insert(int r, T const &e);
    int put(T const &e) { return  insert(_size, e); }
    void sort(int low, int high);
    void sort() { return sort(0, _size); }
    void de_sort(int low, int high);
    void de_sort() { return de_sort(0, _size); }
    int deduplicate();
    int uniquify();

    //traverse
    void traverse( void (*f) (T &e));
    template <typename VST>
    void traverse( VST &vst);
};

template<typename T>
void Vector<T>::copy_from(T const *array, int low, int high) {
    //TODO

}

template<typename T>
void Vector<T>::expand() {
    //TODO

}

template<typename T>
void Vector<T>::shrink() {
    //TODO

}

template<typename T>
bool Vector<T>::bubble(int low, int high) {
    //TODO
    return false;
}

template<typename T>
void Vector<T>::bubble_sort(int low, int high) {
    //TODO

}

template<typename T>
int Vector<T>::max(int low, int high) {
    //TODO
    return 0;
}

template<typename T>
void Vector<T>::selection_sort(int low, int high) {
    //TODO

}

template<typename T>
void Vector<T>::merge(int low, int middle, int high) {
    //TODO

}

template<typename T>
void Vector<T>::merge_sort(int low, int high) {
    //TODO

}

template<typename T>
int Vector<T>::partition(int low, int high) {
    //TODO
    return 0;
}

template<typename T>
void Vector<T>::quick_sort(int low, int high) {
    //TODO

}

template<typename T>
void Vector<T>::heap_sort(int low, int high) {
    //TODO

}

template<typename T>
Vector<T>::Vector(int capacity, int size, T default_value) {
    //TODO

}

template<typename T>
int Vector<T>::is_ordered() const {
    //TODO
    return 0;
}

template<typename T>
int Vector<T>::find(const T &e, int low, int high) const {
    //TODO
    return 0;
}

template<typename T>
int Vector<T>::search(const T &e, int low, int high) const {
    //TODO
    return 0;
}

template<typename T>
T &Vector<T>::operator[](int r) const {
    //TODO
    return nullptr;
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vec) {
    //TODO
    return *this;
}

template<typename T>
T Vector<T>::remove(int r) {
    //TODO
    return nullptr;
}

template<typename T>
int Vector<T>::remove(int low, int high) {
    //TODO
    return 0;
}

template<typename T>
int Vector<T>::insert(int r, const T &e) {
    //TODO
    return 0;
}

template<typename T>
void Vector<T>::sort(int low, int high) {
    //TODO

}

template<typename T>
void Vector<T>::de_sort(int low, int high) {
    //TODO

}

template<typename T>
int Vector<T>::deduplicate() {
    //TODO
    return 0;
}

template<typename T>
int Vector<T>::uniquify() {
    //TODO
    return 0;
}

template<typename T>
void Vector<T>::traverse(void (*f)(T &)) {
    //TODO

}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST &vst) {
    //TODO

}

#endif //DATA_STRUCTURE_BY_CPP_VECTOR_H
