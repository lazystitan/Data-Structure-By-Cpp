//
// Created by Riton on 2019/9/12.
//

/*
 * 题目：
 * f1(x) = 2x + 1
 * f2(x) = 2x + 2
 * 给一个数y，从0起始，连续使用f1、f2，在最小的步数下，得到y
 * 分析：
 * 采用逆向思维，从y向前思考。通过使用f1和f2的逆函数，得到步数。
 * 因为f2增加更快，所以尽量使用f2的逆函数。可以发现，f2的结果必为偶数，f1的结果必为奇数，
 * 因此，在结果为偶数使用f2的逆函数，反之使用f1，直到为0。
 * */

#include <iostream>
#include <stack>

using namespace std;

//f1 reverse
int f1_r(int outcome, stack<char> &s) {
    s.push('2');
    return (outcome - 1) / 2;
}

//f2 reverse
int f2_r(int outcome, stack<char> &s) {
    s.push('3');
    return outcome/2 - 1;
}

int select(int outcome, stack<char> &s) {
    int step = 0;
    while (outcome != 0)
    {
        if (outcome % 2 == 0) {
            outcome = f2_r(outcome, s);
        } else {
            outcome = f1_r(outcome, s);
        }
        step++;
    }
    return step;
}

int main() {
    int y = 0;
    stack<char> s = stack<char>();
    cin >> y;

    int step = select(y, s);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}


