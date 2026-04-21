/*
Implement a function to calculate the nth Fibonacci number using dynamic programming. The Fibonacci sequence is defined as follows:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1
The function should take an integer n as input and return the nth Fibonacci number. Use memoization or tabulation to optimize the calculation and avoid redundant computations. 
Example:
Input: n = 10
Output: 55
Explanation: The 10th Fibonacci number is 55.
Here is a C++ implementation of the Fibonacci function using dynamic programming with memoization:

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int fib(int n, vector<int>& memo) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Check if the value is already computed
    if (memo[n] != -1) {
        return memo[n];
    }

    // Compute the value recursively and store it in the memoization array
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10; // Example input
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    int result = fib(n, memo);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}