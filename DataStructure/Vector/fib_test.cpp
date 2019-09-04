//
// Created by Riton on 2019/7/7.
//

#include <iostream>

#include "fib_search.h"

using namespace std;

int main() {

    Fib fib(100);

    int number = 0;
    while ((number = fib.get()) != -1) {
        cout << number <<" ";
        fib.prev();
    }
    cout << endl;

    int array[] = {1, 4, 5, 8, 10, 21, 31, 43, 60, 89, 100, 103, 104, 106, 120, 150, 171, 200};

    cout << fib_search(array, 103, 0, 18) <<endl;

    return 0;
}