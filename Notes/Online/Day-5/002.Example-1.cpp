/*
A small example for a same program but tabulation and memoization approach.

Problem:
Given a number n, find the nth Fibonacci number.

We will implement both memoization (top-down) and tabulation (bottom-up) approaches to solve this problem.
*/

#include <iostream>
#include <vector>

// Memoization approach (Top-Down)
int fibMemo(int n, std::vector<int>& memo) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // Check if the value is already computed
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Compute the value recursively and store it in the memoization array
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    
    return memo[n];
}

// Tabulation approach (Bottom-Up)
int fibTab(int n) {
    if (n <= 1) {
        return n;
    }

    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}