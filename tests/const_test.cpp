//
// Created by Riton on 2019/7/1.
//

#include <iostream>

int main() {

    const double pi = 3.14;
//    double *ptr = &pi; error
    const double *cptr = &pi;
//    *cptr = 3.16; error

    double pi2 = 3.14;
    const double *cptr2 = &pi2;
//    *cptr2 = 3.16; error
//defining a pointer as a pointer to const affects only what we can do with pointer





    return 0;
}