//
// Created by Riton on 2021/10/8.
//


#include <iostream>
#include <stack>
#include <tuple>
#include <climits>

using std::stack;
using std::tuple;

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

class Solution {
public:
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
};

int main() {
    std::cout << (new Solution())->sumNums(100) << std::endl;

}