//
// Created by Riton on 2019/9/5.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct {
    void operator()(int n) {
        cout << n * n * n << ",";
    }
} func;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    for_each(v.begin(), v.end(),[](int n){cout << n * n << ",";});
    cout << endl;
    for_each(v.begin(), v.end(), func);
    cout << endl;
    for(int n : v) {
        cout << n <<",";
    }
    cout << endl;
    return 0;
}