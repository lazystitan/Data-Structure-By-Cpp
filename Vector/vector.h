//
// Created by Riton on 2019/7/4.
//

#ifndef DATA_STRUCTURE_BY_CPP_VECTOR_H
#define DATA_STRUCTURE_BY_CPP_VECTOR_H

#include <cstdlib>

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
    explicit Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T default_value = 0);
    Vector(T const * array, int n) { copy_from(array, 0, n); }
    Vector(T const * array, int low, int high) { copy_from(array, low, high); }
    Vector(Vector<T> const & vec) { copy_from(vec._element, vec._size); }
    Vector(Vector<T> const & vec, int low, int high) { copy_from(vec._element, low, high); }
    ~Vector() { delete [] _element; }

    //read-only
    int size() const { return _size; }
    bool empty() const { return !_size; }
    bool is_ordered() const;
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
    _element = new T[_capacity = 2 * (high - low)];
    _size = 0;
    while (low < high) {
        _element[_size++] = array[low++];
    }
}

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T *old_element = _element;
    _element = new T[_capacity <<= 1];
    for (int i = 0; i < _size; ++i) {
        _element[i] = old_element[i];
    }
    delete [] old_element;
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;
    if (_size << 2 > _capacity) return;
    T *old_element = _element;
    _element = new T[_capacity >>= 1];
    for (int i = 0; i < _size; ++i) {
        _element[i] = old_element[i];
    }
    delete [] old_element;
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
    _element = new T[_capacity = capacity];
    for (_size = 0;  _size < size ; size++) {
        _element[_size] = default_value;
    }

}

template<typename T>
bool Vector<T>::is_ordered() const {
    for (int i = 0; i < _size - 1; ++i)
        if (_element[i] > _element[i + 1])
            return false;
    return true;
}

template<typename T>
int Vector<T>::find(const T &e, int low, int high) const {
    while ((high-- > low)&&(_element[high] == e));
    return high;
}

template<typename T>
int Vector<T>::search(const T &e, int low, int high) const {
    return (rand() % 2) ?
        bin_search(_element, e, low, high) : fib_search(_element, e, low, high);
}

template<typename T>
T &Vector<T>::operator[](int r) const {
    return _element[r];
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vec) {
    if (_element)
        delete [] _element;
    copy_from(vec._element, 0, vec._size);
    return *this;
}

template<typename T>
T Vector<T>::remove(int r) {
    T e = _element[r];
    remove(r, r + 1);
    return e;
}

template<typename T>
int Vector<T>::remove(int low, int high) {
    if (low == high)
        return 0;
    while (high > _size)
        _element[low++] = _element[high++];
    shrink();
    return high - low;
}

template<typename T>
int Vector<T>::insert(int r, const T &e) {
    expand();
    for (int i = _size; i > r; i--)
        _element[i] = _element[i - 1];
    _element[r] = e;
    _size++;
    return r;
}

template<typename T>
void Vector<T>::sort(int low, int high) {
    //TODO

}

template<typename T>
void Vector<T>::de_sort(int low, int high) {
    T *p = _element + low;
    for (int i = high - low; i > 0 ; i--) {
        T temp = p[i - 1];
        int r = rand() % i;
        p[i - 1] =  p[r];
        p[r] = temp;
    }

}

template <typename T>
int Vector<T>::deduplicate() {
    int old_size = _size;
    int i = 1;
    while (i < _size)
        (find(_element[i], 0, i) < 0) ? i++ : remove(i);
    return old_size - _size;
}

template<typename T>
int Vector<T>::uniquify() {
    int i = 0, j = 0;
    while (++j < _size)
        if (_element[i] != _element[j])
            _element[i++] = _element[j];
    _size = ++i;
    shrink();
    return 0;
}

template<typename T>
void Vector<T>::traverse(void (*f)(T &)) {
    for (int i = 0; i < _size; ++i)
        f(_element[i]);
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST &vst) {
    for (int i = 0; i < _size; ++i)
        vst(_element[i]);
}

#endif //DATA_STRUCTURE_BY_CPP_VECTOR_H
