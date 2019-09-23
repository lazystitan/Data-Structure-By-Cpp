//
// Created by Riton on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cp(int a, int b) {
    return a < b;
}

int main() {
    vector<int> v{4,5,6,1,2,3};
    sort(v.begin(), v.end());
    for(int n : v) {
        cout << n << " ";
    }
    cout << endl;
    reverse(v.begin(), v.end());
    for(int n : v) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> v2{4,5,6,1,2,3};

    sort(v2.begin(), v2.end(), [](int a, int b) {return a < b; });
//    sort(v2.begin(), v2.end(), cp);
    for(int n : v2) {
        cout << n << " ";
    }
    cout << endl;

}
