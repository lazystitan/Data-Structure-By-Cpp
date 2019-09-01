//
// Created by Riton on 2019/9/1.
//

#include <iostream>

using namespace std;

class A {
private:
    int a;
    int b;
public:
    A() : a(1), b(2) {}

};

int main() {
    A* a1 = new A();
    A a2 = A();
    a1->~A();


}
