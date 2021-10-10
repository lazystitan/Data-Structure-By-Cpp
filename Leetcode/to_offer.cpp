//
// Created by Riton on 2021/10/8.
//


#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
#include <regex>

using std::stack, std::tuple, std::vector, std::string;

class BaseStack {
private:
    int values[10000]{};
    int _top = 0;
public:
    BaseStack() = default;

    void push(int v) {
        this->values[_top] = v;
        this->_top++;
    }

    int pop() {
        if (this->_top > 0) {
            this->_top = --this->_top;
            int res = this->values[this->_top];
            return res;
        } else {
            return -1;
        }
    }

    void show() {
        for (int i = 0; i < this->_top; ++i) {
            std::cout << this->values[i] << ',';
        }
        std::cout << std::endl;
    }
};

/**
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 */
class CQueue {
private:
    stack<int> stack1, stack2;
public:
    CQueue() = default;

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty() && stack1.empty()) {
            return -1;
        }

        if (stack2.empty()) {
            int s1size = stack1.size();
            for (int i = 0; i < s1size; ++i) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int res = stack2.top();
            stack2.pop();
            return res;
        } else {
            int res = stack2.top();
            stack2.pop();
            return res;
        }
    }

    void show() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            std::cout << stack2.top() << ",";
            stack1.pop();
        }
        std::cout << std::endl;
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
};

/**
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 */
class MinStack {
private:
    stack<int> values;
    stack<int> mins;
public:
    /** initialize your data structure here. */

    void push(int x) {
        values.push(x);
        mins.push(std::min(x, mins.empty() ? INT_MAX : mins.top()));
    }

    void pop() {
        if (!values.empty()) {
            values.pop();
            mins.pop();
        }
    }

    int top() {
        if (!values.empty()) {
            return values.top();
        }
        return INT_MAX;
    }

    int min() {
        if (!mins.empty()) {
            return mins.top();
        }
        return INT_MAX;
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    /**
     * 不使用if、for、while等语句，实现n + n - 1 + n - 2 + ... + 1
     */
    int sumNums(int n) {
        int ans = 0, A = n, B = n + 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        return ans >> 1;
    }

    int sumNumsFirst(int n) {
        return sum(n);
    }

    static int zero(int n) {
        return 0;
    }

    static int sum(int n) {
        int p = n == 1;
        int (*fa[])(int) = {sum, zero};
        return n + (*(fa + p))(n - 1);
    }

    vector<int> reverse_r{};

    /**
     * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    vector<int> &reversePrintMyMethod(ListNode *head) {
        if (!head) {
            return reverse_r;
        }
        if (head->next) {
            reversePrintMyMethod(head->next);
        }
        reverse_r.push_back(head->val);
        return reverse_r;
    }

    vector<int> reversePrint(ListNode *head) {
        vector<int> vec;
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }

        while (!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }
        return vec;
    }


    /**
     * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *curr = NULL, *newHead = head;
        while (newHead) {
            curr = newHead;
            newHead = curr->next;
            curr->next = pre;
            pre = curr;
        }
        return pre;
    }

    ListNode *reverseListBad(ListNode *head) {
        auto p = reverseListMain(head);
        auto res = p;
        if (p) {
            res = p->next;
            p->next = NULL;
        }
        return res;
    }

    ListNode *reverseListMain(ListNode *head) {
        if (!head) {
            return head;
        }
        if (!head->next) {
            head->next = head;
            return head;
        }

        auto p = reverseListMain(head->next);
        head->next = p->next;
        p->next = head;

        return head;
    }

    /*
     * 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
    */

//    if (head == NULL) {
//        return NULL;
//    }
//    for (Node* node = head; node != NULL; node = node->next->next) {
//        Node* nodeNew = new Node(node->val);
//        nodeNew->next = node->next;
//        node->next = nodeNew;
//    }
//    for (Node* node = head; node != NULL; node = node->next->next) {
//        Node* nodeNew = node->next;
//        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
//    }
//    Node* headNew = head->next;
//    for (Node* node = head; node != NULL; node = node->next) {
//        Node* nodeNew = node->next;
//        node->next = node->next->next;
//        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
//    }
//    return headNew;

    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node *p = head;
        while (p) {
            Node *nn = new Node(p->val);
            nn->next = p->next;
            p->next = nn;
            p = nn->next;
        }

        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        p = head;
        Node *nh = p->next, *copy_p = p->next;
        while (p) {
            p->next = copy_p->next;
            copy_p->next = copy_p->next ? copy_p->next->next : nullptr;
            p = p->next;
            copy_p = copy_p->next;
        }
        return nh;
    }

    Node *copyRandomListSlow(Node *head) {
        if (!head) {
            return head;
        }
        Node *pre, *cpyp = head, *new_h, *p;
        new_h = pre = new Node(cpyp->val);
        cpyp = cpyp->next;

        while (cpyp) {
            pre->next = new Node(cpyp->val);
            pre = pre->next;
            cpyp = cpyp->next;
        }
        cpyp = head;
        p = new_h;
        while (cpyp) {
            Node *cpfind = head;
            Node *thisfind = new_h;
            if (cpyp->random) {
                while (cpfind) {
                    if (cpfind == cpyp->random) {
                        p->random = thisfind;
                        break;
                    }
                    cpfind = cpfind->next;
                    thisfind = thisfind->next;
                }
            }
            cpyp = cpyp->next;
            p = p->next;
        }

        return new_h;

    }

    /**
     * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     * 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     */
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int j = 0, rows = matrix.size(), columns = matrix[0].size(), i = columns - 1;

        while (i >= 0 && j < rows) {
            if (matrix[j][i] < target) {
                j++;
            } else if (matrix[j][i] == target) {
                return true;
            } else {
                i--;
            }
        }

        return false;
    }

    bool findNumberIn2DArraySlow(vector<vector<int>> &matrix, int target) {

        for (auto &i : matrix) {
            if (std::find(i.begin(), i.end(), target) != i.end()) {
                return true;
            }
        }
        return false;
    }

    /**
     * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
     * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
     * 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
     */
    int maxValue(vector<vector<int>> &grid) {
        int rows = grid.size(), columns = grid[0].size();
        int i, j;

        //i = 0, j != 0
        for (j = 0; j < columns; ++j) {

        }
        return 0;
    }


    /**
     * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
     */
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for (char c:s) {
            if (c == ' ') count++;
        }
        s.resize(len + count * 2);
        for (int i = len - 1, j = s.length() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }

    string replaceSpaceBiggerSpace(string s) {
        string res;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '\t' || s[i] == ' ') {
                res.push_back('0');
                res.push_back('2');
                res.push_back('%');
            } else {
                res.push_back(s[i]);
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    string replaceSpaceRegex(const string &s) {
        std::regex r("\\s");
        return std::regex_replace(s, r, "%20");
    }

    /**
     * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
     * 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，
     * 该函数将返回左旋转两位得到的结果"cdefgab"。
     */
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length() - n) +  s.substr(0, n);

    }

    /**
     * 更快
     * abc => abcabc => ab[cab]c
     */
    string reverseLeftWordsNicerButReadBad(string s, int n) {
        s += s;
        return s.substr(n,s.size()/2);
    }
};


int main() {
//    vector<vector<int>> matrix = {
//            {1,  4,  7,  11, 15},
//            {2,  5,  8,  12, 19},
//            {3,  6,  9,  16, 22},
//            {10, 13, 14, 17, 24},
//            {18, 21, 23, 26, 30}
//    };
//
//    matrix = {{5}};
//    matrix = {{5, 5}};
//
//    std::cout << ((new Solution)->findNumberIn2DArray(matrix, 5) ? "found" : "not found") << std::endl;
    string s = "We are happy";
    std::cout << (new Solution())->replaceSpace(s) << std::endl;
    std::cout << (new Solution())->reverseLeftWords(s, 2) << std::endl;

}