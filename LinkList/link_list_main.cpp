//
// Created by Riton on 2019/6/29.
//

#include <iostream>
#include "node.h"
#include "link_list.h"

using namespace std;

int main() {
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
//        arr[i] = i * 2 + 1;
        arr[i] = i;
        cout << "(" << i << "," << i * 2 + 1 << ") ";
    }
    cout << endl;
    auto *list = new LinkList<int>(arr, 10);
    cout << *list << endl;
    cout << "len:" << list->len() << endl;

    list->insert(10, 8);
    list->put(11);
    cout << *list << endl;

    int result = list->pop();
    cout << "result: " << result << endl;
    cout << *list << endl;

    result = list -> get(2);
    cout << "result: " << result << endl;

    list -> del(3);
    cout << *list << endl;

    list -> rev();
    cout << *list << endl;

    result = (*list).get(5);
    int &result2 = (*list)[5];
    int &result3 = list->get_ref(5);
    cout << result << ":" << result2 << ":" << result3 <<endl;
    cout << &result3 << ":" << &result2 << endl;

    (*list)[5] = 128;
    cout << *list << endl;




    return 0;
}


