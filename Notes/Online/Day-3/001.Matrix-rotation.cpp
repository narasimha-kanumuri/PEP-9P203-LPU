/*
Problem 1 — Row Rotation with Locked Diagonal
Concept
Matrix manipulation + indexing logic.
Problem
You are given an N × M matrix.
Rotate each row to the right by K positions, but elements on the main diagonal must remain unchanged.
Example
Input
Matrix:
1 2 3
4 5 6
7 8 9

K = 1

Normal rotation would give
3 1 2
6 4 5
9 7 8

But diagonal elements must stay same:
1 _ _
_ 5 _
_ _ 9

Final result
1 3 2
6 5 4
8 7 9

Constraints
1 ≤ N,M ≤ 200
1 ≤ K ≤ 10^9

Twist
Diagonal elements cannot move.
*/

#include <iostream>
#include <vector>
using namespace std;

void rotateRow(vector<vector<int>>& matrix, int row, int K) {
    int M = matrix[0].size();
    vector<int> temp(M);
    
    // Copy the row to a temporary array
    for (int j = 0; j < M; j++) {
        temp[j] = matrix[row][j];
    }
    
    // Rotate the row to the right by K positions
    for (int j = 0; j < M; j++) {
        int newPos = (j + K) % M;
        if (newPos == row) { // Skip diagonal element
            newPos = (newPos + 1) % M;
        }
        matrix[row][newPos] = temp[j];
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    
    // Input the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Rotate each row
    for (int i = 0; i < N; i++) {
        rotateRow(matrix, i, K);
    }
    
    // Output the rotated matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}