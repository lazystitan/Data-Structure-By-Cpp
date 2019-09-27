//
// Created by Riton on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

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

/*
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
 * 判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词
 * 词典中的词可以重复使用，
 * 词典中没有重复的单词
 * 未通过，太慢
 * TODO
 */

bool is_this_word(int position, string &s ,string &word) {
    for (int i = 0; i < word.length(); ++i) {
        if (s[position + i] != word[i])
            return false;
    }
    return true;
}

bool try_match_one(int position, string &s, vector<string> wordDict) {
    if (position == s.length())
        return true;
    for (auto &word : wordDict) {
//        cout << "matching : " << word << endl;
        if (is_this_word(position, s, word) && try_match_one(position + word.length(), s, wordDict))
            return true;
    }
    return false;
}

bool word_break(string s, vector<string> &wordDict) {
//    没考虑重复前缀的词
//    bool has_matched = false;
//    int i = 0;
//    int offset = 0;
//    while (i < s.length()) {
//        has_matched = false;
//        for (auto &word : wordDict) {
//            if (is_this_word(i, s, word)) {
//                offset = word.length();
//                has_matched = true;
//                cout << "matched with " << word << ", offset is " << offset << endl;
//                break;
//            }
//        }
//
//        if (offset == 0)
//            break;
//
//        if (has_matched) {
//            i += offset;
//            cout << "now i is : " << i << ", length is : " << s.length() << endl;
//            cout << "i < length : " <<  (i < s.length()) << endl;
//            offset = 0;
//
//        }
//        else {
//            break;
//        }
//    }
//
//    return has_matched;

    bool arr[26]{false};

    for (auto &word : wordDict) {
        for (auto &ch : word) {
            arr[ch - 'a'] = true;
        }
    }

    for (auto &ch : s) {
        if (!arr[ch - 'a'])
            return false;
    }

//    return false;
    return try_match_one(0, s, wordDict);
}

void test10() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << word_break(s, wordDict) << endl;
    s = "cars";
    wordDict = {"car", "ca", "rs"};
    cout << word_break(s, wordDict) << endl;
    s = "carss";
    wordDict = {"car", "cas", "rs"};
    cout << word_break(s, wordDict) << endl;
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << word_break(s, wordDict) << endl;

}

/*
 * 旋转数组
 */

void rotate(vector<int> &nums, int k) {
//    笨方法
//    int len = nums.size();
//    k %= nums.size();
//    vector<int> temp(k);
//    for (int j = 0; j < k; ++j) {
//        temp[j] = nums[len - k + j];
//    }
//
//    for (int i = len - 1; i >= k; --i) {
//        nums[i] = nums[i - k];
//    }
//    for (int l = 0; l < k; ++l) {
//        nums[l] = temp[l];
//    }

//    不需要额外空间的方法

    if (nums.empty()) {
        return ;
    }
    k = k % nums.size();
    if (k == 0) {
        return;
    }
    reverse(nums.begin(), nums.end()-k);
    reverse(nums.end()-k, nums.end());
    reverse(nums.begin(), nums.end());

}

void test11() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    for (auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/*
 * 判断是否存在重复元素
 */

bool contain_duplicate(vector<int> &nums) {
//    太慢
/*
 * 构建一颗n个节点的红黑树的复杂度为nlogn，插入操作logn，遍历操作n
 * 快排/堆排序复杂度nlogn，遍历logn
 * 但红黑树使用了额外的空间
 */
//    set<int> s;
//    for( auto &num : nums) {
//        auto p = s.insert(num);
//        if (!p.second)
//            return true;
//    }
//    return false;
    if (nums.empty())
        return false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i+1])
            return true;
    }
    return false;
}

void test12() {
    vector<int> nums{1, 2, 3, 1};
    cout << contain_duplicate(nums) << endl;
}

/*
 * 移动0
 */
void move_zeroes(vector<int> &nums) {
//    太慢
//    if (nums.empty())
//        return;
//    int p = nums.size();
//    int i = p - 1;
//    while (i >= 0) {
//        if (nums[i] == 0) {
//            for (int j = i; j < p - 1; ++j) {
//                swap(nums[j], nums[j+1]);
//            }
//            p--;
//            nums[p] = 0;
//        }
//        i--;
//    }

//    快慢指针
    for(int i = 0, j = 0; i < nums.size(); i ++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j ++;
            //同样快指针慢指针，快指针遇到不是0的和慢指针交换数据
        }
    }
}

void test13() {
    vector<int> nums{0,1,0,3,12};
    move_zeroes(nums);
    for (auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;
    nums = {0,0,1};
    move_zeroes(nums);
    for (auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/*
 * 求两个数组的交集
 * 直接通过
 */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int i = 0, j = 0; (i < nums1.size()) && (j < nums2.size());) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

/*
 * 存在递增的三元子序列
 */

bool increasing_triplet(vector<int> &nums) {
    if (nums.size() < 3)
        return false;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (auto &num : nums) {
        if (num > min2) {
            return true;
        }
        if (num < min1 ) {
            min1 = num;
        }
        if ((num > min1) && (num < min2)){
            min2 = num;
        }
//        cout << "min1: "  << min1 << ", min2: " << min2 << endl;
    }
    return false;
};

void test14() {
    vector<int> nums{5,4,3,2,1};
    cout << increasing_triplet(nums) << endl;
    reverse(nums.begin(), nums.end());
    cout << increasing_triplet(nums) << endl;
    nums = {2,1,5,0,3};
    cout << increasing_triplet(nums) << endl;
}

/*
 * 第K个最大的元素
 */

int find_k_th_largest(vector<int> &nums, int k) {
    /*
     * 想法很好，先排序再找，但会产生无用操作
     * 假设从p将数组分为前后两个，让大的在右边，小的在左边，排序算法会对两侧都继续进行排序
     * 但是实际上只需要对右侧进行排序即可，左侧的排序属于多余操作
     */
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

void test15() {
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    cout << find_k_th_largest(nums, k) << endl;
}

/*
 * 数据流的中位数
 * 例如【1，2，3，4】中位数是（2+3）/2 = 2.5；
 * 又如【1，2，3】中位数是2；
 * TODO
 */

class MedianFinder {
private:
    vector<int> _v;
public:
    MedianFinder() = default;

    void addNum(int num) {
        _v.push_back(num);
    }

    double findMedian() {
        if (_v.size() % 2 == 0) {
            int succeed = _v.size()/2;
            int pre = succeed - 1;
            return ((double)(_v[succeed] + _v[pre]))/2.0;
        } else {
            return _v[_v.size()/2];
        }
    }
};

/*
 * 判断是否有环
 * 快慢指针
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool has_cycle(ListNode *head) {
    if (!head)
        return false;
    ListNode *p = head, *q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return true;
    }
    return false;
}

/*
 * 节点带随机指针的链表深拷贝
 * TODO
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() = default;

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* copy_random_list(Node* head) {

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
//    test9();
//    test10();
//    test11();
//    test12();
//    test13();
//    test14();
    test15();
}