//
// Created by Riton on 2019/10/7.
//

#ifndef DATA_STRUCTURE_BY_CPP_VECTOR_INT_OS_H
#define DATA_STRUCTURE_BY_CPP_VECTOR_INT_OS_H

#include <iostream>
#include <vector>

/*
 * 辅助函数
 */

std::ostream& operator<<(std::ostream &os, const std::vector<int> &nums) {
    os << "[";
    for (int i = 0; i < nums.size() - 1; ++i) {
        os << nums[i] << ",";
    }
    os << nums.back() << "]";
    return os;
}

#endif //DATA_STRUCTURE_BY_CPP_VECTOR_INT_OS_H
