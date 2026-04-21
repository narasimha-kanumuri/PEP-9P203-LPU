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
