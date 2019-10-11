//
// Created by Riton on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include "../vector_int_os.h"

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
 * TODO
 * */
vector<vector<string>> partition(string s) {
    vector<vector<string>> v;
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
 * 单链表节点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 判断是否有环
 * 快慢指针
 */

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
 * 找出相交链表的相交节点
 * 没有交点返回nullptr
 * n时间复杂度，1空间复杂度
 */

ListNode *get_intersection_node(ListNode *headA, ListNode *headB) {
    /*
     * 使用set的方法
     */

//    if (!headA || !headB)
//        return nullptr;
//
//    ListNode *p_a = headA, *p_b = headB;
//    unordered_set<ListNode*> s;
//    while (p_a) {
//        s.insert(p_a);
//        p_a = p_a->next;
//    }
//    while (p_b) {
//        if (s.find(p_b)!=s.end())
//            return p_b;
//        p_b = p_b->next;
//    }
//    return nullptr;

    /*
     * 不使用set的方法
     * 核心思想：使headA和headB与尾部的距离都等长
     */
//    ListNode *p_a = headA, *p_b = headB;
//    while (p_a && p_b) {
//        p_a = p_a->next;
//        p_b = p_b->next;
//    }
//
//    while (p_a) {
//        p_a = p_a->next;
//        headA = headA->next;
//    }
//
//    while (p_b) {
//        p_b = p_b->next;
//        headB = headB->next;
//    }
//
//    while (headA && headB) {
//        if (headA == headB) {
//            return headA;
//        }
//        headA = headA->next;
//        headB = headB->next;
//    }
//    return nullptr;

    /*
     * 代码更短的一个方法
     * 似乎是a和b都在向交点靠近
     * TODO
     */

    ListNode *a=headA,*b=headB;
    while(a!=b){
        (!a) ?a=headB:a=a->next;
        (!b) ?b=headA:b=b->next;
    }
    return a;

}

void test22() {
    ListNode *head_a = new ListNode(2), *p = head_a;

    for (int i = 0; i < 10; ++i) {
        p->next = new ListNode(i + 3);
        p = p->next;
    }
    ListNode *head_b = new ListNode(1);
    head_b->next = head_a->next->next;

    cout << get_intersection_node(head_a, head_b)->val << endl;

}

/*
 * 单链表排序
 * 时间复杂度nlogn，空间复杂度常数
 */

/*
 * 不使用pre，会造成16ms时间损失
 * 但使用了后，依然和其他人写的归并有近一倍的运行速度差距
 * 去除对辅助节点堆内存分配，减少4ms，到了96ms
 * 结合他人的解法，优化后达到48ms
 */
ListNode *sort_list(ListNode* head) {
    if(!head)
        return nullptr;

    if(!head->next)
        return head;

    ListNode *slow = head, *fast = head, *pre = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *list1 = head, *list2 = slow;
    pre->next = nullptr;
    list1 = sort_list(list1);
    list2 = sort_list(list2);

    /*
     * 不需要辅助节点的合并
     */

    pre = nullptr, head = nullptr;
    ListNode *p = nullptr;

    while (list1 || list2) {
        if (!list2 || (list1 && list2 && list1->val <= list2->val)) {
            p = list1;
            list1 = list1->next;
        } else if (!list1 || (list1 && list2 && list1->val > list2->val)) {
            p = list2;
            list2 = list2->next;
        }

        if (!head)
            head = p;
        if(pre)
            pre->next = p;
        pre = p;
    }

    /*
     * 需要辅助节点的合并
     */

//    ListNode tmp = ListNode(0);
//    head = &tmp;
//    ListNode *p = head;
//
//    while (list1 && list2) {
//        if (list1->val < list2->val) {
//            p->next = list1;
//            list1 = list1->next;
//            p = p->next;
//        } else {
//            p->next = list2;
//            list2 = list2->next;
//            p = p->next;
//        }
//    }
//    if (list1)
//        p->next = list1;
//    if (list2)
//        p->next = list2;
//    head = head->next;

    return head;
}

/*
 * 别人的快的方法
 */

ListNode* merge(ListNode* a, ListNode* b)
{
    ListNode *sorted = nullptr, *prev = nullptr, *p = nullptr;
    while (a || b)
    {
        if (!b ||(a && a->val < b->val))
        {
            p = a;
            a = a->next;
        }
        else
        {
            p = b;
            b = b->next;
        }
        if (prev)
            prev->next = p;
        prev = p;
        if (!sorted)
            sorted = p;
    }
    return sorted;
}

ListNode* sortList(ListNode* head) {
    ListNode *fast = head, *slow = head, *prev= nullptr;
    while (fast && slow)
    {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (fast!=slow && prev)
    {
        prev->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }
    return head;
}

void test23() {
    ListNode *head = new ListNode(5), *p = head;
    for (int i = 0; i < 4; ++i) {
        p->next = new ListNode(4 - i);
        p = p->next;
    }
    p->next = nullptr;

    head = sort_list(head);
    p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }

}


/*
 * 判断一个链表是否为回文链表
 * TODO
 */

bool is_palindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->val == head->next->val)
        return true;
    ListNode *pre = head, *now = head -> next;

    return false;
}

/*
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
 */

ListNode* odd_even_list(ListNode* head) {
    if (!head)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head;
    return head;
}

/*
 * 节点带随机指针的链表深拷贝
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
    /*
     * 自己想的蠢方法
     * 具体的做法是：
     * 先不考虑随机指针，将原链表复制，
     * 然后针对每一个随机指针，找到其在新链表中指向的位置
     */
//    if (!head)
//        return nullptr;
//    Node *new_head = new Node(head->val, nullptr, nullptr),
//         *new_p = new_head,
//         *p = head;
//
//    while (p->next) {
//        new_p->next = new Node(p->next->val, nullptr, nullptr);
//        new_p = new_p->next;
//        p = p->next;
//    }
//
//    new_p = new_head, p = head;
//    while (p) {
//        if (p->random) {
//            Node *random_p = head, *new_random_p = new_head;
//            while (p->random != random_p) {
//                random_p = random_p->next;
//                new_random_p = new_random_p->next;
//            }
//            new_p->random = new_random_p;
//        }
//        p = p->next;
//        new_p = new_p->next;
//    }
//
//    return new_head;
    /*
     * 使用map保存记录r
     * 将map替换为unordered_map反而变慢了,后来发现是没有判断随机指针是否是nullptr
     */

//    if (!head)
//        return nullptr;
//    Node *new_head = new Node(head->val, nullptr, nullptr),
//         *new_p = new_head,
//         *p = head;
//    unordered_map<Node*, Node*> m;
//    m[head] = new_head;
//    while (p->next) {
//        new_p->next = new Node(p->next->val, nullptr, nullptr);
//        new_p = new_p->next;
//        p = p->next;
//        m[p] = new_p;
//    }
//    new_p = new_head, p = head;
//    while (p) {
//        if (p->random)
//            new_p->random = m[p->random];
//        new_p = new_p->next;
//        p = p->next;
//    }
//
//    return new_head;

    /*
     * 不需要map的方法,空间复杂度为常数
     */

    if (!head)
        return nullptr;

    Node *new_head,
         *pcur = head,
         *pnext = head->next;

    while (pcur) {
        pcur->next = new Node(pcur->val, pcur->next, nullptr);
        pcur = pcur->next->next;
    }

    pcur = head;

    while (pcur) {
        if (pcur->random)
            pcur->next->random = pcur->random->next;
        pcur = pcur->next->next;
    }

    pcur = head;
    new_head = pnext = head->next;

    while (pnext->next) {
        pcur->next = pcur->next->next;
        pnext->next = pnext->next->next;
        pcur = pcur->next;
        pnext = pcur->next;
    }

    pcur->next = nullptr;

    return new_head;
}


/*
 * 字符串中不重复的子字符串个数
 * TODO
 */

int count_substr(string &str) {
    return 1;
}

void test16() {
    string str;
    cin >> str;
    vector<string> result;
    cout << count_substr(str);
}

/*
 * 峰值元素是指其值大于左右相邻值的元素。
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 假设 nums[-1] = nums[n] = -∞
 */

int find_peak_element(vector<int>& nums) {
    /*
     * 这样写可以但是太慢
     * 由于求的是任意一个峰值， 一个一个找显然浪费了
     */
//    int len = nums.size();
//    bool is_up = true;
//
//    for (int i = 0; i < len - 1; ++i) {
//        if (nums[i] > nums[i+1])
//            return i;
//    }
//    return len - 1;

    /*
     * 核心思想：
     * 找到中心，
     * 如果中心呈上升，有以下几种情况：
     * 中心前
     * 1.中心前一直上升 （没有峰值）
     * 2.中心前有上升有下降
     * 3.中心前一直下降
     * 中心后
     * 1.中心后一直有上升有下降
     * 2.中心后一直上升
     * 可以发现，中心后必有峰值，中心前可能没有
     *
     * 如果中心呈下降，有以下几种情况：
     * 中心前有
     * 1.中心前一直上升（中心点为峰值）
     * 2.中心前一直下降 （第一个元素为峰值）
     * 3.中心前有下降，有上升 （有，不确定位置）
     * 中心后有
     * 1.中心后一直下降 （没有）
     * 2.中心后有下降有上升 （有， 不确定位置）
     * 可以发现中心前（包括中心）必有峰值，中心后有可能没有
     *
     * 综上所述，根据中心的趋势，可以直接在一定可以发现峰值的一侧寻找，从而减少计算
     */

    int right = nums.size() - 1;
    int left = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void test17() {
    vector<int> nums{1,2,1,3,5,6,4};
    cout << find_peak_element(nums) << endl;
}

/*
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
 * 可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 */

int find_duplicate(vector<int>& nums) {
    /*
     * 注意特殊条件：所有数字都大于等于1，小于等于n
     * 下方算法虽通过排序解决了问题，但没有用到已知的条件
     */
//    sort(nums.begin(), nums.end());
//    for (int i = 0; i < nums.size() - 1; ++i) {
//        if (nums[i] == nums[i + 1])
//            return nums[i];
//    }
//    return 0;

    /*
     * 应用所有数字都大于等于1，小于等于n的已知条件，但造成了空间复杂度为n，要求为1，
     * 此时时间复杂度为n
     */
//    auto *appear = new int[nums.size() - 1]{0};
//    for (int num : nums) {
//        if (appear[num - 1] == 0)
//            appear[num - 1]++;
//        else
//            return num;
//    }
//    return 0;

    /*
     *从右向左，如果找到重复的元素，返回，否则将当前元素放到合适的位置，重新开始检测
     */
    for(int i=nums.size()-1;i>0;)
    {
        //如果当前元素是对应下标，i向左滑动
        if(nums[i]==i)
            i--;
        //否则
        else
        {
            //如果当前元素与下标为当前元素保存的的元素相同，说明当前元素是重复元素
            if(nums[i]==nums[nums[i]])
                return nums[i];
            //否则交换当前元素与当前元素为下标的空间保存的元素
            int tmp=nums[nums[i]];
            nums[nums[i]]=nums[i];
            nums[i]=tmp;
        }
    }
    return nums[0];
}

void test18() {
    vector<int> nums{3,1,3,4,2};
    cout << find_duplicate(nums) << endl;
    nums = {1,3,4,2,2};
    cout << find_duplicate(nums) << endl;
}

/*
 * 给定一个整数数组 nums，按要求返回一个新数组 counts。
 * 数组 counts 有该性质：
 * counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
 *
 * 还有更快的解法
 * TODO
 */
vector<int> count_smaller(vector<int>& nums) {

    /*
     * 最蠢的办法，超时
     * 比较次数：外层循环len - 1，内循环len - 1 - i，共计 (n^2 - n)/2
     */

//    int len = nums.size();
//    vector<int> result(len, 0);
//
//    for (int i = len - 2; i >= 0; i--) {
//        int count = 0;
//        for (int j = len - 1; j > i; j--) {
//            if (nums[i] > nums[j])
//                count++;
//        }
//        result[i] = count;
//    }
//
//    return result;

    /*
     *  ̶减̶少̶了̶比̶较̶次̶数̶(̶也̶可̶能̶没̶有̶)̶，̶但̶依̶然̶不̶够̶快̶
     * 比较次数依然是 (n^2 - n)/2
     */

//    int len = nums.size();
//    vector<int> result(len, 0);
//
//    for (int i = len - 1; i > 0; i--) {
//        for (int j = 0; j < i; ++j) {
//            if (nums[i] < nums[j])
//                result[j]++;
//        }
//    }
//
//    return result;

    /*
     * lower_bound的单次比较次数是log(2)N + 1
     * lower_bound中的总比较次数log(2)(n-1)! + n - 1
     * log(2)n!化简后约为(1/2 + n)log(2)n - 1.44(n - 1/12n) + 0.83
     * 当n很大时，可以认为是nlog(2)n - 1.44n + 0.83
     * 故lower_bound的比较次数约为(n-1)log(2)(n-1) - 0.44n - 0.17
     */

    int len = nums.size();
    vector<int> result;

    vector<int> sorted_nums;
    for (int i = len - 1; i >= 0; i--) {
        auto iter = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]);
        int pos = iter - sorted_nums.begin();
        sorted_nums.insert(iter, nums[i]);
        result.push_back(pos);
    }
    reverse(result.begin(), result.end());

    return result;
}

void test19() {
    vector<int> nums{5,2,6,1};
    cout << count_smaller(nums) << endl;
    nums = {1};
    cout << count_smaller(nums) << endl;
    nums.clear();
    for (int i = 0; i < 100000; ++i) {
        nums.emplace_back(random() % 100000);
    }
    cout << count_smaller(nums) << endl;

}

/*
 * 给定一个无序的数组 nums，
 * 将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序
 * TODO
 */

void wiggle_sort(vector<int> &nums) {
    /*
     * 最蠢的办法
     * 先排序，然后从两边隔一个元素交换，形成波浪
     * 失败，因为有相同元素
     */
//    sort(nums.begin(), nums.end());
//    int i = 1;
//    int j = (nums.size() % 2 == 1) ? nums.size() - 1 : nums.size() - 2;
//    while (i < j) {
//
//        swap(nums[i], nums[j]);
//
//        i+= 2;
//        j -= 2;
//    }

    sort(nums.begin(), nums.end());
    auto sorted_nums = nums;
    auto min = sorted_nums.begin();
    auto max = sorted_nums.end();
    max--;
    nums.clear();
    while (min < max) {
        nums.push_back(*min);
        if (min < max)
            nums.push_back(*max);
        min++;
        max--;
    }
}

void test20() {
    vector<int> nums{1, 5, 1, 1, 6, 4};
    wiggle_sort(nums);
    cout << nums << endl;
    nums = {1, 3, 2, 2, 3, 1};
    cout << nums << endl;

}

/*
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 例：
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * TODO
 */

/*
 * 自己想出来的方法，太慢，太复杂
 * bug,当全为0时，0的数量大于某一值，会让sort出现错误，未知原因
 */

//vector<int> oct_vec(int num) {
//
//    if (num == 0)
//        return {0};
//
//    vector<int> num_oct_vec;
//    while (num != 0) {
//        num_oct_vec.push_back(num % 10);
//        num /= 10;
//    }
//    reverse(num_oct_vec.begin(), num_oct_vec.end());
//    return num_oct_vec;
//}
//
//bool compare_oct_vec(vector<int> &nums1, vector<int> &nums2) {
//    int i = 0;
//    vector<int> nums1_first = nums1;
//    nums1_first.insert(nums1_first.end(), nums2.begin(), nums2.end());
//    vector<int> nums2_first = nums2;
//    nums2_first.insert(nums2_first.end(), nums1.begin(), nums1.end());
//    while (i < nums1_first.size()) {
//        if (nums1_first[i] < nums2_first[i])
//            return false;
//        else if (nums1_first[i] > nums2_first[i])
//            return true;
//        else
//            i++;
//    }
//    return true;
//}
//
//string largest_number(vector<int>& nums) {
//    bool flag = false;
//    for (auto &n : nums) {
//        if (n != 0) {
//            flag = true;
//            break;
//        }
//    }
//
//    if (!flag)
//        return "0";
//
//    vector<vector<int>> oct_vecs;
//    oct_vecs.reserve(nums.size());
//    for (auto &num : nums) {
//        oct_vecs.push_back(oct_vec(num));
//    }
//
//    sort(oct_vecs.begin(), oct_vecs.end(), compare_oct_vec);
//    string result = "";
//    for (auto &v : oct_vecs) {
//        for (auto &num : v) {
//            result.append(to_string(num));
//        }
//    }
//    return result;
//
//}

/*
 * 思路清晰，实现简单的方法
 */

//bool cmp(int a,int b){
//    string str1 = to_string(a);
//    string str2 = to_string(b);
//    return str1 + str2 > str2 + str1;
//}
//
//string largest_number(vector<int>& nums) {
//    string res;
//    if(nums.empty())
//        return res;
//    sort(nums.begin(),nums.end(),cmp);
//    if(nums[0] == 0)
//        return "0";
//    for(int num : nums){
//        res += to_string(num);
//    }
//    return res;
//}

/*
 * 最快的方法，实现思路和我最初的相似
 */

bool func_sort(const int& a, const int& b)
{
    long long n_a = 10;
    while (a / n_a) n_a *= 10;
    long long n_b = 10;
    while (b / n_b) n_b *= 10;
    long long r_a = (long long)a * n_b + (long long)b;
    long long r_b = (long long)b * n_a + (long long)a;
    return r_a > r_b;
}

string largest_number(vector<int>& nums) {
    sort(nums.begin(), nums.end(), func_sort);
    string str = "";
    bool flag = false;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (!flag)
        {
            if (nums[i] == 0)
            {
                continue;
            }
        }
        flag = true; // 存在非零数
        str += to_string(nums[i]);
    }
    return flag ? str : "0";
}

void test21() {
    vector<int> nums{3,30,34,5,9};
    cout << largest_number(nums) << endl;
    nums = {10,2};
    cout << largest_number(nums) << endl;
    nums = {1,2,3,4,5,6,7,8,9,0};
    cout << largest_number(nums) << endl;
    nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << largest_number(nums) << endl;
    nums = {824,938,1399,5607,6973,5703,9609,4398,8247};
    cout << largest_number(nums) << endl;
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
//    test15();
//    test17();
//    test18();
//    test19();
//    test20();
//    test21();
//    test22();
    test23();
}
