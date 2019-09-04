//
// Created by Riton on 2019/7/1.
//
#include <iostream>

#include "node.h"
#include "list.h"

using namespace std;

int main() {
    auto *list = new List<int>();
    for (int i = 0; i < 100; ++i) {
        list->insert_as_last(i*i+1);
        list->insert_as_last(i*i*i);
    }
    for (int i = 0; i < list->size(); ++i) {
        cout << (*list)[i] <<" ";
    }
    cout << endl;
    auto *copied_list = new List<int>((*list), 10, 30);

    for (int i = 0; i < copied_list->size(); ++i) {
        printf("%d ", (*copied_list)[i]);
    }

    return 0;
}
