//
// Created by Riton on 2019/10/7.
//

#ifndef DATA_STRUCTURE_BY_CPP_AUXILIARY_OS_H
#define DATA_STRUCTURE_BY_CPP_AUXILIARY_OS_H

#include <iostream>
#include <vector>

/*
 * 辅助函数
 */

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &items) {
    os << "[";
    for (int i = 0; i < items.size() - 1; ++i) {
        os << items[i] << ",";
    }
    os << items.back() << "]";
    return os;
}


std::ostream& operator<<(std::ostream &os, const std::vector<int> &nums) {
    os << "[";
    for (int i = 0; i < nums.size() - 1; ++i) {
        os << nums[i] << ",";
    }
    os << nums.back() << "]";
    return os;
}

std::ostream& operator<<(std::ostream &os, const std::vector<std::string> &strings) {
    os << "[";
    if (strings.size() != 0) {
        for (int i = 0; i < strings.size() - 1; ++i) {
            os << strings[i] << ",";
        }
        os << strings.back();
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream &os, const std::vector<std::vector<std::string>> &vector_of_strings) {
    os << "[";
    if (vector_of_strings.size() != 0) {
        for (int i = 0; i < vector_of_strings.size() - 1; ++i) {
            os << vector_of_strings[i] << ",";
        }
        os << vector_of_strings.back();
    }
    os << "]";
    return os;
}

#endif //DATA_STRUCTURE_BY_CPP_AUXILIARY_OS_H
