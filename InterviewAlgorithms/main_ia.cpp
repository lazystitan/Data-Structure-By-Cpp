//
// Created by Riton on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 * 求只出现一次的数字
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

/*
 * 求众数
 * */

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

/*
 * 给定一矩阵，元素从左到右从上到下为升序，给定目标target，高效判断矩阵中是否存在target
 * */

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

/*
 * 给定两个有序数组nums1和nums2，大小分别为m，n，
 * 在不使用额外空间的情况下，归并两数组到nums1，假设nums1有足够的空间
 * */

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

/*
 * 判断回文串，只考虑数字和字母，忽略其它字符
 * */

char to_lower_case(char c) {
    int gap = 'a' - 'A';
    if (c < 'a')
        return c + gap;
    else
        return c;

}

bool is_alphabet_or_number(char c) {
    return ((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c <= '9') && (c >= '0'));
}

bool is_palindrome(string s) {
    int i = 0, j = s.length() - 1;
    bool fisrt = true;
    while (i < j) {
        while (!is_alphabet_or_number(s[i]) && i < s.length())
            i++;

        if (fisrt) {
            if (i == s.length()) {
                cout << "all is not alphabet" << endl;
                return true;
            }
            fisrt = false;
        }

        while (!is_alphabet_or_number(s[j]) && j >= 0)
            j--;

        if (to_lower_case(s[i]) != to_lower_case(s[j])) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}



void test5() {
    string s = "A man, a plan, a canal: Panama";
    cout << (is_palindrome(s) ? "true" : "false") << endl;
    string s2 = "race a car";
    cout << (is_palindrome(s2) ? "true" : "false") << endl;
    string s3 = "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
    cout << (is_palindrome(s3) ? "true" : "false") << endl;
    string s4 = "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
    cout << (is_palindrome(s4) ? "true" : "false") << endl;
    string s5 = "0P";
    cout << (is_palindrome(s5) ? "true" : "false") << endl;
}


/*
 * 将一个字符串划分为多个回文串，要求列出所有结果
 * */
vector<vector<string>> partition(string s) {
    vector<vector<string>> v;
    //TODO
    return v;
}

ostream& operator<<(ostream &os, const vector<vector<string>> &answer) {
    for (const auto &v : answer) {
        cout << "[";
        for (const auto &vs : v) {
            cout << vs << ",";
        }
        cout << "]" << endl;
    }
    return os;
}

void test6() {
    string s = "aab";
    vector<vector<string>> v{{"aa", "b"}, {"a", "a", "b"}};
    cout << v;

}

/*
 * 反转字符数组
 * */

void reverse_string(vector<char> &s) {
    int front = 0, back = s.size() - 1;
    while (front < back) {
//        太慢
//        char temp = s[front];
//        s[front] = s[back];
//        s[back] = temp;

/*
 *  bit0 = 0, bit1 = 1;
 *  bit0 = bit0 ^ bit1 = 1;
 *  bit1 = bit0 ^ bit1 = 0;
 *  bit0 = bit0 ^ bit1 = 1;
 */

//        s[front] = s[front] ^ s[back];
//        s[back] = s[front] ^ s[back];
//        s[front] = s[front] ^ s[back];

        swap(s[front++], s[back--]);
//        front++;
//        back--;
    }
}

void test7() {
    vector<char> v{'h', 'e', 'l', 'l', 'o'};
    reverse_string(v);
    for (const auto &c : v) {
        cout << c << " ";
    }
    cout << endl;
}

/*
 * 找到第一个不重复出现的字符的索引
 */

int first_unique_char(string s) {
//    太慢，太复杂
//    map<char, pair<int, int>> m;
//    int i = 0;
//    for (auto &c : s) {
//        auto p = m.insert(map<char, pair<int, int>>::value_type(c, make_pair(i++, 1)));
//        if (!p.second) {
//            m[c].second++;
//        }
//    }
//    bool has_unique = false;
//    char c = s.back();
//    int num = s.length();
//    cout << "start char : " << c << " num : " << num << endl;
//    for (auto &key_value : m) {
//        cout << "char : " << key_value.first << " , num : " << key_value.second.first << " , times: " << key_value.second.second << " ." << endl;
//        if ((num >= key_value.second.first) && (key_value.second.second == 1)) {
//            cout << key_value.first << " is more close to head." << endl;
//            has_unique = true;
//            num = key_value.second.first;
//            c = key_value.first;
//        }
//    }
//
//    if (has_unique)
//        return num;
//    else
//        return -1;
    int arr[26] = {0};
    for (char i : s) {
        arr[i - 'a']++;
    }
    for (int j = 0; j < s.length(); ++j) {
        if (arr[s[j] - 'a'] == 1)
            return j;
    }
    return -1;
}

void test8() {
    string s = "leetcode";
    cout << first_unique_char(s) << endl;
    string s1 = "loveleetcode";
    cout << first_unique_char(s1) << endl;
    string s2 = "aabbaabbc";
    cout << first_unique_char(s2) << endl;
    string s3 = "cccaabadb";
    cout << first_unique_char(s3) << endl;
}

/*
 * 判断两个单词是否是字母异位词
 */

bool is_anagram(string s, string t) {
    if (s.length() != t.length())
        return false;
    int arr[26] = {0};
    for (auto &c : s) {
        arr[c - 'a']++;
    }
    for (auto &c : t) {
        arr[c - 'a']--;
    }
    for (auto &c : arr) {
        if (c != 0)
            return false;
    }

    return true;
}

void test9() {
    string s = "anagram", t = "nagaram";
    cout << (is_anagram(s, t) ? "true" : "false") << endl;
    s = "rat", t = "car";
    cout << (is_anagram(s, t) ? "true" : "false") << endl;

}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
    test9();
}
