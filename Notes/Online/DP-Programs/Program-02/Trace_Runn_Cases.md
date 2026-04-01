# Trace run cases for House Robber Problem

## Sample Input: `nums = [2, 7, 9, 3, 1,100,12]`

| House (i) | Value | Decision: $\max(dp[i-1], dp[i-2] + val)$ | `dp[i]` |
| :--- | :--- | :--- | :--- |
| 0 | 2 | Base Case | 2 |
| 1 | 7 | $\max(2, 7)$ | 7 |
| 2 | 9 | $\max(7, 2 + 9)$ | 11 |
| 3 | 3 | $\max(11, 7 + 3)$ | 11 |
| 4 | 1 | $\max(11, 11 + 1)$ | 12 |
| 5 | 100 | $\max(12, 11 + 100)$ | 112 |
| 6 | 12 | $\max(112, 12 + 12)$ | 112 |

- **Result:** 112