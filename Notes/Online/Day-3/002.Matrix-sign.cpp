/*
Problem 2 — Largest Plus Sign in Matrix
Concept
2D scanning + directional counting.
Problem
Given a binary matrix, find the size of the largest plus shape.
A plus shape consists of:
center
equal arms in 4 directions

Example
Matrix

0 1 0
1 1 1
0 1 0

Largest plus
size = 1

Example 2
0 1 0 0
1 1 1 1
0 1 1 0
0 1 0 0

Largest plus size:
2

Twist
Cells with value 2 behave as wildcards and can act as 1.
Students get confused by this.
*/

#include <iostream>
#include <vector>
using namespace std;

int largestPlusSign(vector<vector<int>>& matrix) {
    int N = matrix.size();
    if (N == 0) return 0;
    int M = matrix[0].size();
    
    vector<vector<int>> left(N, vector<int>(M, 0));
    vector<vector<int>> right(N, vector<int>(M, 0));
    vector<vector<int>> up(N, vector<int>(M, 0));
    vector<vector<int>> down(N, vector<int>(M, 0));
    
    // Fill left and up
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 1 || matrix[i][j] == 2) {
                left[i][j] = (j > 0 ? left[i][j-1] : 0) + 1;
                up[i][j] = (i > 0 ? up[i-1][j] : 0) + 1;
            }
        }
    }
    
    // Fill right and down
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (matrix[i][j] == 1 || matrix[i][j] == 2) {
                right[i][j] = (j < M - 1 ? right[i][j+1] : 0) + 1;
                down[i][j] = (i < N - 1 ? down[i+1][j] : 0) + 1;
            }
        }
    }
    
    int maxSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 1 || matrix[i][j] == 2) {
                int size = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                maxSize = max(maxSize, size);
            }
        }
    }
    
    return maxSize;
}