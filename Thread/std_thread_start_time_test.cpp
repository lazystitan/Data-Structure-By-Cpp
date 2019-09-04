//
// Created by Riton on 2019/9/4.
//

#include <iostream>
#include <thread>

using namespace std;

void do_work() {
    cout << "do work done" <<endl;
}

int main() {
    thread thread0(do_work);
    //thread start right after thread created
    thread0.join();
    return 0;
}

