//
// Created by Riton on 2019/7/1.
//

#include <iostream>

using namespace std;

int f() {
    return 10;
}

int main() {
    auto some = 128 / 3.0 + true;

    cout <<"some: "<<some<<endl;

    int x = f();
    decltype(f()) sum = x;

    cout << sum << endl;
    return 0;
}


