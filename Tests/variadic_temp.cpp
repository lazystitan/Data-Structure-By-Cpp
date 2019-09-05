//
// Created by Riton on 2019/9/5.
//

#include <iostream>
#include <bitset>

using namespace std;

void print() {};

template <typename T, typename ... Types>
void print(const T &first_arg, const Types &... args) {
    cout << first_arg <<endl;
    print(args...);
}

int main() {
    print(7.5, "some", bitset<16>(377), 43);
    return 0;
}
