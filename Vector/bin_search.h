//
// Created by Riton on 2019/7/6.
//

#ifndef DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H
#define DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H

// O(log N)

template <typename T>
int bin_search_a(T * array, T const &e, int low, int high) {
    while (low < high) {
        int mid = (low + high) / 2;
        if  (e < array[mid])
            high = mid;
        else if (e > array[mid])
            low = mid;
        else
            return mid;
    }
    return -1; // failed
}

template <typename T>
int bin_search_b(T * array, T const &e, int low, int high) {
    //TODO
    return -1;
}

template <typename T>
int bin_search_c(T * array, T const &e, int low, int high) {
    //TODO
    return -1;
}


#endif //DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H
