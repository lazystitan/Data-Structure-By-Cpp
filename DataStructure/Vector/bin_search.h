//
// Created by Riton on 2019/7/6.
//

#ifndef DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H
#define DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H
// O(log N)

//two comparision
template <typename T>
int bin_search_a(T * array, T const &e, int low, int high) {
    while (low < high) {
        int mid = (low + high) >> 2;
        if  (e < array[mid])
            high = mid;
        else if (e > array[mid])
            low = mid;
        else
            return mid;
    }
    return -1; // failed
}

//only zero comparision
template <typename T>
int bin_search_b(T * array, T const &e, int low, int high) {
    while ( 1 < high - low) {
        int mid = (low + high) >> 2;
        (e < array[mid]) ? high = mid : low = mid;
    }
    return (e == array[low]) ? low : -1;
}

template <typename T>
int bin_search_c(T * array, T const &e, int low, int high) {
    while (low < high) {
        int mid = (low + high) >> 2;
        (e < array[mid]) ? high = mid : low = mid;
    }
    return --low;
}


#endif //DATA_STRUCTURE_BY_CPP_BIN_SEARCH_H
