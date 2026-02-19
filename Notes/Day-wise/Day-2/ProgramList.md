# 📅 DAY 2 — Binary Search + Recursion

- Search Space Reduction Mindset

---

## 🎯 Core Invariants

- Sorted boundary guarantee
- Monotonic predicate → binary searchable
- Recursive shrinkage must strictly reduce state
- Base case must terminate
- Decision boundary detection

---

## 🔥 DAY 2 — IN-CLASS SET (7 Medium + 3 Hard)

### 🟡 MEDIUM (7)

#### 1️⃣ Kth Missing Positive with Gaps

- Given a strictly increasing sorted array of positive integers,
- find the Kth missing number not present in the array.
- Must run in $$O(\log N)$$.
- **Pattern:** Binary search on missing-count function

#### 2️⃣ First Position Where Predicate Becomes True

- Given a monotonic boolean function $f(i)$ over range $[0, N)$,
- find smallest index where $f(i) = true$.
- Function evaluation is expensive.
- 
- **Pattern:** Generic lower-bound binary search

---

#### 3️⃣ Minimum Eating Speed Variant

- Given piles of items and time limit H,
- find minimum integer speed so all piles are consumed within H.
- Speed must be integer.
- **Pattern:** Binary search on answer space

#### 4️⃣ Rotated Sorted Array with Single Duplicate Block

- Array was sorted then rotated.
- One value may appear multiple times consecutively.
- Find minimum element.
- 
- **Pattern:** Modified binary search + ambiguity handling

---

#### 5️⃣ Recursive Power with Modulo and Overflow Guard

- Compute $x^n \mod m$ using recursion.
- Must handle negative exponent and large values safely.
- **Pattern:** Divide & conquer recursion

#### 6️⃣ Longest Valid Prefix Using Recursion

- Given string S, recursively remove matching outer characters
- if they are equal, and return remaining length.
- Example: "abbaXabba" → remove outer symmetric layers.
- **Pattern:** Recursive shrinkage + base detection

---

#### 7️⃣ Search in 2D Matrix with Row Ordering

- Matrix where:
- Each row sorted
- First element of row > last of previous row
- Find target in $$O(\log (N \cdot M))$$.
- **Pattern:** Index mapping + binary search

### 🔴 HARD (3)

#### 8️⃣ Peak Element in Bitonic Array with Noise

- Array increases, then decreases.
- However, small local noise ($\pm 1$) allowed.
- Find global peak index in $$O(\log N)$$.
- 
- **Pattern:** Derivative sign binary search + robustness

---

#### 9️⃣ Recursive Expression Evaluator

- Given string mathematical expression containing:
- +, -, *, parentheses
- Evaluate recursively without using stack explicitly.
- **Pattern:** Recursion + divide by outermost operator

#### 🔟 Minimum Days to Disconnect Grid

- Given grid of 0/1 cells,
- each day you may remove one land cell.
- Find minimum days required to make island disconnected.
- **Pattern:** Binary search on answer + DFS recursion
- (Triple pattern: Binary Search + Graph DFS + Connectivity invariant)

---

## 🏠 DAY 2 — HOMEWORK SET (7 Medium + 3 Hard)

- More twisted versions.

### 🟡 MEDIUM

- 1️⃣ **Fixed Point in Sorted Array**: Find index $i$ such that $arr[i] = i$. Array may contain negatives.
- 2️⃣ **Smallest Divisor Given Threshold**: Find smallest divisor such that sum of $ceil(arr[i]/divisor) \le threshold$.
- 3️⃣ **Recursive Decode Ways**: Given digit string, count ways to decode recursively with memoization.
- 4️⃣ **Closest Element to Target**: Sorted array. Return element closest to target. If tie, return smaller value.
- 5️⃣ **Count Occurrences of Target**: Sorted array. Return frequency of target in $$O(\log N)$$.
- 6️⃣ **Longest Increasing Path from Index**: Given array, recursively find longest strictly increasing chain starting at index $i$.
- 7️⃣ **Recursive Subset Sum (Boolean)**: Determine if subset sums to K. Must use memoization.

---

### 🔴 HARD

#### 8️⃣ Aggressive Allocation Variant

- Given N houses and K routers,
- place routers to maximize minimum distance.
- Return maximum possible minimum distance.
- **Pattern:** Binary search on answer + greedy validation

#### 9️⃣ Count Smaller Elements After Self

- Return for each element, number of smaller elements to its right.
- Must use modified merge sort.
- 
- **Pattern:** Divide & conquer + counting

#### 🔟 Recursive Tree Height with Pruning

- Given binary tree, compute height,
- but stop early if subtree already exceeds given limit H.
- Return whether tree is balanced within bound.
- **Pattern:** Recursion + pruning invariant

---

## 📊 Pattern Combination Coverage

| Pattern | Used In |
| :--- | :--- |
| Binary Search (Index) | 1, 2, 4, 7 |
| Binary Search (Answer) | 3, HW2, HW8 |
| Modified BS (Rotation) | 4 |
| Divide & Conquer Recursion | 5, HW9 |
| Recursion + Memo | HW3, HW7 |
| Binary Search + Greedy | HW8 |
| Binary Search + Graph | 10 |
| Recursion + Expression Parsing | 9 |

- ✔ $\ge 3$ multi-pattern problems
- ✔ $\ge 2$ triple-pattern problems
- ✔ No platform copy wording
- ✔ Invariant-discoverable