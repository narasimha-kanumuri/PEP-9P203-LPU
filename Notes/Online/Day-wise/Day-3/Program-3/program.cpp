/*

Problem 3 — Spiral Sum with Direction Switch
Concept
Matrix traversal.
Problem
Traverse the matrix in spiral order, but every second layer must be traversed in reverse spiral direction.
Example
Input
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Layer 1 → normal spiral
1 2 3 4 8 12 16 15 14 13 9 5

Layer 2 → reverse spiral
10 11 7 6

Final order
1 2 3 4 8 12 16 15 14 13 9 5 10 11 7 6

Twist
Alternate spiral direction per layer.

Logic:
1. Initialize boundaries: top, bottom, left, right.
2. Use a layer counter to track the current layer.
3. While top <= bottom and left <= right:
   a. If layer is even, traverse in normal spiral order.
   b. If layer is odd, traverse in reverse spiral order.
   c. Update boundaries after each traversal.
   d. Increment layer counter.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrderWithDirectionSwitch(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    int layer = 0;

    while (top <= bottom && left <= right) {
        if (layer % 2 == 0) { // Normal spiral
            for (int i = left; i <= right; ++i) result.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; ++i) result.push_back(matrix[i][right]);
            if (top < bottom) {
                for (int i = right - 1; i >= left; --i) result.push_back(matrix[bottom][i]);
            }
            if (left < right) {
                for (int i = bottom - 1; i > top; --i) result.push_back(matrix[i][left]);
            }
        } else { // Reverse spiral
            for (int i = right; i >= left; --i) result.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; ++i) result.push_back(matrix[i][left]);
            if (top < bottom) {
                for (int i = left + 1; i <= right; ++i) result.push_back(matrix[bottom][i]);
            }
            if (left < right) {
                for (int i = bottom - 1; i > top; --i) result.push_back(matrix[i][right]);
            }
        }
        ++layer;
        ++top;
        --bottom;
        ++left;
        --right;
    }

    return result;
}