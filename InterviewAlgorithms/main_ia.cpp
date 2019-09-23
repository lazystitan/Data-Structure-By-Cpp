//
// Created by Riton on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 * 使用异或运算符
 * */
int single_number(vector<int> &nums) {
    int pre = 0;
    for (int n : nums )
        pre ^= n;
    return pre;
}

void test1() {
    vector<int> v{1,2,2,1,3};
    cout << single_number(v) << endl;
}

int majority_element(vector<int> &nums) {
//    map<int, int> m;
//    int n = nums.size() / 2;
//    for (int num : nums) {
//        auto p = m.insert(map<int, int>::value_type(num, 1));
//        if (!p.second)
//            m[num]++;
//    }
//
//    for (auto & iter : m) {
//        if (iter.second > n)
//            return iter.first;
//    }
//
//    return 0;

    /*
     * 摩尔投票算法
     * 核心思想：不同的数字进行抵消
     * */
    int value = 0;
    int count = 0;
    for(int num : nums)
    {
        if(count==0)
        {
            count++;
            value = num;
        }

        else
        {
            if(num==value)
                count++;
            else
                count--;

        }
    }
    return value;

}

void test2() {
//    vector<int> v{1, 1, 1, 1, 1, 2, 2};
    vector<int> v{1, 2, 3, 2, 4, 2, 5, 2};
    cout << majority_element(v) << endl;
}

bool search_matrix(vector<vector<int>>& matrix, int target) {
//    最蠢的办法
//    bool result = false;
//    int m = matrix.size();
//    if (m == 0)
//        return false;
//    int n = matrix[0].size();
//    if (n == 0)
//        return false;
//
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (matrix[i][j] == target)
//                return true;
//        }
//    }
//
//    return result;

//    依旧很蠢的方法
//    bool result = false;
//    int m = matrix.size();
//    if (m == 0)
//        return false;
//    int n = matrix[0].size();
//    if (n == 0)
//        return false;
//
//    int start_line = -1;
//
//    for (int i = m-1; i >= 0; --i) {
//        if (matrix[i][0] == target)
//            return true;
//        else if (matrix[i][0] < target) {
//            start_line = i;
//            break;
//        }
//    }
//
//    if (start_line == -1)
//        return false;
//
//    while (start_line >= 0) {
//        for (int j = 0; j < n; ++j) {
//            if (matrix[start_line][j] == target)
//                return true;
//        }
//        start_line--;
//    }
//
//    return result;


    int m = matrix.size();
    if (m == 0)
        return false;
    int n = matrix[0].size();
    if (n == 0)
        return false;

    int x = 0;
    int y = n - 1;
    while ((x < m) && (y >= 0)) {
        if (matrix[x][y] == target)
            return true;
        else if (target > matrix[x][y])
            x++;
        else
            y--;
    }

    return false;
}

void test4() {
//    vector<vector<int>> mat{
//        {1,4,7,11,15},
//        {2,5,8,12,19},
//        {3,6,9,16,22},
//        {10,13,14,17,24},
//        {18,21,23,26,30}
//    };
    vector<vector<int>> mat{{-5}};

    int tar = -5;
    cout << search_matrix(mat, tar) << endl;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//    int p = 0;
//    int i = 0;
//    while ((i < m) && (p < n)) {
//        if (nums1[i] > nums2[p]) {
//            for (int j = m; j > i; --j) {
//                nums1[j] = nums1[j - 1];
//            }
//            nums1[i] = nums2[p];
//            m++;
//            p++;
//        }
//        i++;
//    }
//    for (; p < n; ++p, ++m) {
//        nums1[m] = nums2[p];
//    }
    for (int i = 0; i < n; ++i) {
        nums1[i + m] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

void test3() {
    vector<int> v1{4,5,6,0,0,0};
    vector<int> v2{1,2,3};
    merge(v1, 3, v2, 3);
    for (int n: v1) {
        cout << n << " ";
    }
}

int main() {
//    test1();
//    test2();
//    test3();
    test4();
}
