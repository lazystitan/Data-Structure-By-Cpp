//
// Created by Riton on 2019/6/29.
//

#include <iostream>
#include "node.h"

using namespace std;

int main() {
    auto *node = new Node(12,nullptr);

    cout << node->value << endl;
    if (node->next == nullptr) {
        cout << "next: null"<<endl;
    }

    return 0;
}

