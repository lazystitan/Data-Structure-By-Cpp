//
// Created by Riton on 2019/7/8.
//
#include <iostream>

#include "stack.h"

using namespace std;

int main() {
    Stack<int> stack;
    stack.push(1);
    int a = stack.top();
    cout << a << endl;
}