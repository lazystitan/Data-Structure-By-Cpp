//
// Created by Riton on 2019/10/12.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include "../auxiliary_os.h"

using namespace std;

/*
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素
 */

bool compare_count(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> top_k_frequent(vector<int>& nums, int k) {
    vector<int> result;
    result.reserve(k);
    unordered_map<int, int> m;

    for (auto &num : nums)
        m[num]++;

    vector<pair<int, int>> temp(m.begin(), m.end());
    sort(temp.begin(), temp.end(), compare_count);

    auto iter = temp.begin();
    while (k--)
        result.push_back((*iter++).first);

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    cout << top_k_frequent(nums, k) << endl;
    nums = {1};
    k = 1;
    cout << top_k_frequent(nums, k) << endl;

}
