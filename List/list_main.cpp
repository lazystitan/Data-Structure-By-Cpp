//
// Created by Riton on 2019/7/1.
//
#include <iostream>

#include "node.h"

using namespace std;

int main() {

    int x = 30;

    ListNode<int> node = ListNode<int>(2);
//    node = x;
    cout << node.data << endl;
    return 0;
}
