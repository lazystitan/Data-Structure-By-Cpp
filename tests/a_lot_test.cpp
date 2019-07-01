//
// Created by Riton on 2019/7/1.
//

#include <iostream>

using namespace std;

struct Some {
    long x1;
    int x2;
    double x3;
};

int main() {
    Some *some = new Some { 12, 13, 3.14};

    cout << &some <<endl;
    cout << &some->x1<<endl;
    cout << &some->x2 <<endl;
    cout << &some->x3 <<endl;
}
