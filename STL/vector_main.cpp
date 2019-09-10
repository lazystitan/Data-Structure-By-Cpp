//
// Created by Riton on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct {
    void operator()(int n) {
        cout << n * n * n << ",";
    }
} func;

void test1() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    for_each(v.begin(), v.end(),[](int n){cout << n * n << ",";});
    cout << endl;
    for_each(v.begin(), v.end(), func);
    cout << endl;
    for(int n : v) {
        cout << n <<",";
    }
    cout << endl;
}

void test2() {
    auto *v = new vector<int>();

    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    v->push_back(4);

    for (int n : *v) {
        cout << n << endl;
    }

    v->pop_back();

    for (int n : *v) {
        cout << n << endl;
    }

    for (int i = 0; i < v->size(); ++i) {
        cout <<(*v)[i] <<endl;
    }
    delete v;
}

int main() {
//    test1();
    test2();
    return 0;
}