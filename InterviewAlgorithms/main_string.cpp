//
// Created by Riton on 2019/10/12.
//

/**
 * 字符相关算法题
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#include "../auxiliary_os.h"

using namespace std;

/*
 * 判断回文串，只考虑数字和字母，忽略其它字符
 */

/*
 * 将字母转换为小写
 */
char to_lower_case(char c) {
    int gap = 'a' - 'A';
    if (c < 'a')
        return c + gap;
    else
        return c;

}

/*
 * 判断字符是否是字母或者数字
 */

bool is_alphabet_or_number(char c) {
    return ((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c <= '9') && (c >= '0'));
}

/*
 * string s是否是回文字符串
 */

bool is_palindrome_sp(string s) {
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
    cout << (is_palindrome_sp(s) ? "true" : "false") << endl;
    string s2 = "race a car";
    cout << (is_palindrome_sp(s2) ? "true" : "false") << endl;
    string s3 = "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
    cout << (is_palindrome_sp(s3) ? "true" : "false") << endl;
    string s4 = "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
    cout << (is_palindrome_sp(s4) ? "true" : "false") << endl;
    string s5 = "0P";
    cout << (is_palindrome_sp(s5) ? "true" : "false") << endl;
}


/*
 * 将一个字符串划分为多个回文串，要求列出所有结果
 * TODO
 * */

bool is_palindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}


void backtrace(string &s, vector<vector<string>> &result, vector<string> &cur, int lastindex) {
    int len = s.length();
    /*
     * 如果lastindex超过s的最后一个字符，直接返回， 递归基
     */
    if (lastindex >= len) {
        result.push_back(cur);
        return;
    }

    for (int i = lastindex; i < len; i++) {
        int sub_len = i - lastindex + 1;
        string temp = s.substr(lastindex, sub_len);
        /*
         * 如果从lastindex向前sublen的子字符串是回文
         * 首先将此字符串加入cur, 然后对其后的字符串继续分割
         */
        if (is_palindrome(temp)) {
            cur.push_back(temp);
            backtrace(s, result, cur, i + 1);
            cur.pop_back();
        }

    }
}

vector<vector<string>> partition(string s) {
    /*
     * 别人的解法，看懂了
     * 但速度不快
     */
    vector<vector<string>> result;
    vector<string> cur;
    backtrace(s, result, cur, 0);
    return result;
}

void test6() {
    string s = "aab";
    cout << partition(s) << endl;
    s = "abaaabaab";
    cout << partition(s) << endl;

}


/*
 * 反转字符数组
 * */

void reverse_string(vector<char> &s) {
    int front = 0, back = s.size() - 1;
    while (front < back) {
//        普通交换，太慢
//        char temp = s[front];
//        s[front] = s[back];
//        s[back] = temp;

/*
 *  异或原理
 *  bit0 = 0, bit1 = 1;
 *  bit0 = bit0 ^ bit1 = 1;
 *  bit1 = bit0 ^ bit1 = 0;
 *  bit0 = bit0 ^ bit1 = 1;
 */

//        使用异或交换
//        s[front] = s[front] ^ s[back];
//        s[back] = s[front] ^ s[back];
//        s[front] = s[front] ^ s[back];
//        front++;
//        back--;

//      使用stl函数交换
        swap(s[front++], s[back--]);
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
    string s = "Leetcode";
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
    string s = "Leetcode";
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
 * 字符串中不重复的子字符串个数
 */

void find(string &s, int len, int &count) {
    unordered_set<string> us;
    for (int i = 0; i <= s.size() - len; i++) {
        string temp = s.substr(i, len);
        auto p = us.insert(temp);
        if (p.second) {
//            cout << temp << endl;
            count++;
        }
    }

}

int count_substr(string &str) {
    int count = 0;
    for (int len = 1; len <= str.size(); len++) {
        find(str, len, count);
    }

    return count;
}

void test16() {
    string str = "aab";
//    cin >> str;
    vector<string> result;
    cout << count_substr(str);
}

int main() {
//    test6();
    test16();
}