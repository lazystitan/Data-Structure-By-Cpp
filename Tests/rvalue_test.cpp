//
// Created by Riton on 2019/6/30.
//

#include <iostream>

using namespace std;


int &get(int arr[], int p) {
    int &temp = arr[p];
    return temp;
}


int main() {

    int arr[3] = {1,2,3};

    int &x = arr[1];
    x++;
    cout <<arr[1] <<endl;
    cout <<&arr[1] <<endl;

    int &x1 = get(arr, 1);
    cout <<x1 <<endl;
    cout <<&x1 <<endl;

    char a[] = "123";
    printf("%0xd",a);


    return 0;
}

