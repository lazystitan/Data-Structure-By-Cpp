//
// Created by Riton on 2019/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Int {
private:
    int a;
public:
    explicit Int(int number) {
        a = number;
    };

    void set(int number) {
        a = number;
    }

    int get() {
        return a;
    }

};

int main() {
    vector<Int*> v;
    for (int i = 0; i < 5; ++i) {
        Int *temp = new Int(3);
        v.push_back(temp);
    }

    for(Int *n : v) {
        cout << n->get() << endl;
        delete  n;
    }

    for(Int *n : v) {
        cout << n->get() << endl;
    }

}

