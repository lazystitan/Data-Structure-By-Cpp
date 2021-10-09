//
// Created by Riton on 2021/10/8.
//


#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#include <climits>

using std::stack, std::tuple, std::vector;

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
};


int main() {
//    auto n1 = new ListNode(1);
//    auto n2 = new ListNode(2);
//    auto n3 = new ListNode(3);
//    n1->next = n2;
//    n2->next = n3;
//
//    auto r = (new Solution())->reverseList(n1);
//    while (r) {
//        std::cout << r->val << std::endl;
//        r = r->next;
//    }

    auto n1 = new Node(7);
    auto n2 = new Node(13);
    auto n3 = new Node(11);
    auto n4 = new Node(10);
    auto n5 = new Node(1);
//    auto n6 = new Node(23);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
//    n5->next = n6;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
//    n5->random = n6;
//    n6->random = n5;

    auto p = n1;
    while (p) {
        std::cout << p->val << ":";
        if (p->random) {
            std::cout << p->random->val << " random address:" << p->random;
        } else {
            std::cout << "NULL";
        }
        std::cout << " next address:" << p->next << std::endl;
        p = p->next;
    }

    std::cout << std::endl;

    p = (new Solution())->copyRandomList(n1);
    while (p) {
        std::cout << p->val << ":";
        if (p->random) {
            std::cout << p->random->val << " random address:" << p->random;
        } else {
            std::cout << "NULL";
        }
        std::cout << " next address:" << p->next << std::endl;
        p = p->next;
    }
    std::cout << std::endl;

    p = n1;
    while (p) {
        std::cout << p->val << ":";
        if (p->random) {
            std::cout << p->random->val << " random address:" << p->random;
        } else {
            std::cout << "NULL";
        }
        std::cout << " next address:" << p->next << std::endl;
        p = p->next;
    }

}