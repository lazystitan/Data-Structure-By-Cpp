//
// Created by Riton on 2019/10/4.
//

#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    else {
        cout << "counting fib(" << n - 1 << ") and fib(" << n - 2 << ")..." << endl;
        return fib(n - 1) + fib(n - 2);
    }
}

int helper(vector<int> &memo, int n) {
    if (n > 0 && memo[n] == 0) {
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    }
    return memo[n];
}

int fib2(int n) {
    if (n < 1)
        return 0;
    vector<int> memo(n + 1, 0);
    memo[1] = memo[2] = 1;
    return helper(memo, n);
}

int fib_dp(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i -  1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << fib2(10) << endl;
}