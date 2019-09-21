//
// Created by Riton on 2019/9/21.
//
#include <iostream>
#include <list>

using namespace std;

class Base {
public:
    virtual void do_work() {
        cout << "Base's work" << endl;
    }
};

class Mid : public Base{
public:
    void do_work() override {
        cout << "Mid's work" << endl;
    }
};

void test1() {
    Mid mid;
    Mid *pm = &mid;
    Base *pb = &mid;

    pm->do_work();
    pb->do_work();

}

class ABase {
public:
    virtual void do_work() = 0;
};

class AMid : public ABase {
public:
    void do_work() override {
        cout << "AMid's work" <<endl;
    }
};

void test2() {
    AMid aMid;
    aMid.do_work();
}

class ABaseA{
public:
    virtual void do_some() = 0;
};

class MidA : public ABaseA{
public:
    void do_some() override {
        cout << "real do some" << endl;
    }
};

class ABaseB{
private:
    list<ABaseA*> *bases;
public:
    ABaseB() {
        bases = new list<ABaseA*>();
    }

    virtual ~ABaseB() = default;

    virtual void add(ABaseA* item) {
        bases->push_back(item);
    }

    virtual void do_active() {
        for(ABaseA *p : *bases) {
            p->do_some();
        }
    }
};

class MidB : public ABaseB{

public:
    MidB() = default;
    void active() {
        ABaseB::do_active();
    }
};

void test3() {
    MidA midA;
    MidB midB;
    midB.add(&midA);
    midB.active();
}


int main() {
//    test1();
//    test2();
    test3();
    return 0;

}