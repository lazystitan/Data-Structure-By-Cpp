//
// Created by Riton on 2021/10/8.
//


#include <iostream>
#include <stack>

using std::stack;

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

int main() {
    CQueue q = CQueue();
    q.appendTail(1);
    q.show();
    q.appendTail(2);
    q.show();
    q.deleteHead();
    q.show();


}