//
// Created by Riton on 2019/11/17.
//

#include <iostream>

using namespace std;

class BaseA {
public:
    virtual void action() {
        cout << "Base A action" << endl;
    }
};

class BaseB {
public:
    virtual void action() {
        cout << "Base B action" << endl;
    }
};

class BaseC {
public:
    virtual void action() {
        cout << "Base C action" << endl;
    }
};

class DerClass : public BaseA, public  BaseB, public BaseC {
public:
    void action() override {
        cout << "Derived class action" << endl;
    }
};

int main() {

    DerClass d;
    d.action();

    return 0;
}