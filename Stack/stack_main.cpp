//
// Created by Riton on 2019/7/8.
//
#include <iostream>

#include "stack.h"

using namespace std;

/**
 * recursive
 *void convert(Stack<char> &stack, long long number, int base) {
 *    static char digit[] =
 *            {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
 *    if ( number > 0 ){
 *        stack.push(digit[number % base]);
 *        convert(stack, number / base, base);
 *    }
 *}
 **/

void convert(Stack<char> &stack, long long number, int base) {
    static char digit[] =
            {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    while ( number > 0 ) {
        int remainder = (int) ( number % base);
        stack.push(digit[remainder]);
        number /= base;
    }
}

int main() {
    Stack<char> stack;

    convert(stack, 20000 , 8);

    while (!stack.empty()) {
        cout << stack.pop();
    }
}



