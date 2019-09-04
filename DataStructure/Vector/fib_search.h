//
// Created by Riton on 2019/7/6.
//

#ifndef DATA_STRUCTURE_BY_CPP_FIB_SEARCH_H
#define DATA_STRUCTURE_BY_CPP_FIB_SEARCH_H

#define DEFAULT_SIZE 1000

class Fib {
private:
    int *element;
    int p;
    int size;
    void expand() {
        int oldsize = size;
        size *= 2;
        int *old = element;
        element = new int[size];
        for (int i = 0; i < oldsize; ++i) {
            element[i] = old[i];
        }
        delete [] old;
    }
public:
    explicit Fib(int max) {
        size = DEFAULT_SIZE;
        element = new int[DEFAULT_SIZE];
        int f = 1, g = 0, index = 0;
        while (true)  {
            g += f; // g = 0 + 1 = 1;  g = 1 + 1 = 2; g = 2 + 1 = 3;
            if (g >= max)
                break;
            f = g - f; // f = 1 - 1 = 0; f = 2 - 1 = 1; f = 3 - 1 = 2;
            if (index++ >= size) expand();
            element[index] = g;
        };
        p = index;
    };
    int get() {
        if (p >= 0)
            return element[p];
        else
            return -1;
    };
    void prev() {
        p--;
    };
};

template <typename T>
int fib_search(T *array, T const &e, int low, int high) {
    Fib fib(high - low);
    while (low < high) {
        while (high - low < fib.get())
            fib.prev();
        int mid = low + fib.get() - 1;
        if ( e < array[mid])
            high = mid;
        else if (e > array[mid])
            low = mid;
        else
            return mid;
    }
    return -1;
}


#endif //DATA_STRUCTURE_BY_CPP_FIB_SEARCH_H
