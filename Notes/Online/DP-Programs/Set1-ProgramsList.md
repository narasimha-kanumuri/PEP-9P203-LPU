 DP TWIST SET (3 Easy / 3 Medium / 3 Hard)

---

# 🟢 EASY (3)

---

### 1️⃣ Climbing Stairs with Broken Steps

Classic climbing stairs,
but some steps are blocked and cannot be used.
*(Twist: DP + forbidden states)*

---

### 2️⃣ House Robber with Circular Alarm

House robber problem,
but first and last houses are connected by alarm wire.
*(Twist: circular DP split case)*

---

### 3️⃣ Grid Paths with One Obstacle Removal

Count paths in grid moving right/down,
but you may remove exactly one obstacle.
*(Twist: state augmentation dp[r][c][used])*

---

# 🟡 MEDIUM (3)

---

### 4️⃣ Longest Increasing Subsequence with One Change Allowed

Find LIS length,
but you may modify at most one element to any value.
*(Twist: DP + extra state for modification)*

---

### 5️⃣ Coin Change with Limited Coins

Minimum coins to make sum,
but each coin has limited quantity.
*(Twist: bounded knapsack DP)*

---

### 6️⃣ Largest Alternating Square in Matrix

Find largest square where values alternate like chessboard.
*(Twist: grid DP + parity pattern)*

(From new DP pattern list)

---

# 🔴 HARD (3)

---

### 7️⃣ Maximum Increasing Path with One Teleport

Move right/down with increasing values,
but you may teleport once to any larger value cell.
*(Twist: multi-state DP + grid + transition choice)*

---

### 8️⃣ Diamond Sum with Blocked Cells

Find maximum diamond-shaped sum of size K,
but cells with −1 break the shape.
*(Twist: 2D prefix + shape DP + validation)*

---

### 9️⃣ Word Break with Minimum Cuts

Check if string can be segmented using dictionary,
but return minimum number of cuts instead of boolean.
*(Twist: DP + optimization + prefix checking)*

---

### 10️⃣ Minimum Edit Distance with Substring Replacement

Calculate edit distance between two strings,
but you can replace any substring with another string in one operation.
*(Twist: DP + substring replacement adds a new dimension to the state)*

---

### 11️⃣ Unique Paths with Energy Boost

Count paths in grid moving right/down,
but you have one energy boost that allows you to skip one cell.
*(Twist: multi-state DP with energy boost state)*

---

### 12️⃣ Knapsack with Item Dependencies

Each item has a dependency on another item,
meaning you can only take it if you also take its dependency.
*(Twist: DP + dependency graph adds a new layer of complexity)*

---

### 13️⃣ Longest Palindromic Subsequence with One Deletion

Find longest palindromic subsequence,
but you can delete at most one character from the original string.
*(Twist: DP + extra state for deletion)*

---

### 14️⃣ Maximum Subarray Sum with One Modification

Find maximum subarray sum,
but you can modify at most one element to any value.
*(Twist: DP + extra state for modification)*

---

### 15️⃣ Minimum Path Sum with One Cell Skip

Find minimum path sum in grid moving right/down,
but you can skip one cell and move to the next one.
*(Twist: multi-state DP with skip state)*

# ✅ Concept Coverage Check (Mandatory)

| Concept            | Covered |
| ------------------ | ------- |
| 1D DP              | 1,2,4,5 |
| Grid DP            | 3,6,7   |
| Multi-state DP     | 3,7     |
| Prefix / fast sum  | 8       |
| Pattern DP         | 6       |
| Knapsack DP        | 5       |
| String DP          | 9       |
| State augmentation | 3,4,7,13 |
| Advanced DP twist  | 7,8,9,13 |

✔ matches DP concept file
✔ matches teleprompter flow
✔ twist present in every problem
✔ difficulty balanced
✔ no copy wording
✔ interview-level

---
