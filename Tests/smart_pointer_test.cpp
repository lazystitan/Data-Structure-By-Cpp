#include <memory>

//
// Created by Riton on 2019/9/21.
//

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    auto p = std::make_unique<vector<int>>();
    for (int i = 0; i < 10000; ++i) {
        p->push_back(i);
    }

    for (int j = 0; j < p->size(); j += 278) {
        cout << (*p)[j];
    }
}

