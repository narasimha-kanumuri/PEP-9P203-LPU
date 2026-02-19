# 📅 DAY 3 — Sorting (Tool) + Greedy + DS Revision

- **Focus:** Partition invariants, merge invariants, greedy proof intuition
- **Embedded:** 1 Stack, 1 Linked List, 1 Queue problem

---

## 🔥 IN-CLASS SET (7 Medium + 3 Hard)

### 🟡 MEDIUM (7)

#### 1️⃣ Dutch National Flag with Unknown Range
- Array contains only three distinct values — but values are not known beforehand.
- Sort in $O(N)$ without counting sort.
- **Twist:** Discover pivot categories dynamically.
- 

#### 2️⃣ Merge Intervals with Weight Preservation
- Intervals have weights. When merging overlapping intervals, sum their weights.
- **Pattern:** Sorting + greedy + accumulation invariant.

---

#### 3️⃣ Stable Partition Around Pivot
- Reorder array so values $< X$ appear before $X$ and $\ge X$ after — but relative order must remain unchanged.
- **Twist:** Stability constraint + in-place limitation.

#### 4️⃣ Linked List Reorder by Absolute Value
- Given singly linked list, reorder nodes by increasing absolute value without creating new nodes.
- **Pattern:** Sorting logic + pointer manipulation.

#### 5️⃣ Minimum Platforms with Buffer Time
- Given train arrival/departure times, add mandatory 5-minute cleaning gap before next arrival.
- **Pattern:** Sorting + greedy + adjusted interval logic.
- 

---

#### 6️⃣ Stack-Based Expression Normalizer
- Given arithmetic expression with redundant parentheses, remove unnecessary brackets while preserving evaluation order.
- **Pattern:** Stack + structural invariant.

#### 7️⃣ Queue Reconstruction by Height Variant
- Each person has $(height, frontCount, parityConstraint)$. Reconstruct queue satisfying both constraints.
- **Pattern:** Sorting + greedy + extra constraint twist.

---

### 🔴 HARD (3)

#### 8️⃣ QuickSort with Duplicate Compression
- Modify QuickSort so that equal elements are grouped in one partition pass. Return number of swaps performed.
- **Pattern:** 3-way partition + performance tracking invariant.

#### 9️⃣ Minimum Swaps to Make Array “K-Sorted”
- Array is almost sorted — every element is at most K distance away. Return minimum swaps required to fully sort.
- **Pattern:** Sorting + heap/greedy reasoning + inversion logic.

#### 🔟 Merge K Sorted Linked Lists Without Extra Heap
- You may not use priority queue. Use divide & conquer merging strategy only.
- **Pattern:** Sorting + linked list + recursion invariant.
- 

---

## 🏠 HOMEWORK SET (7 Medium + 3 Hard)

### 🟡 MEDIUM
- 1️⃣ **Largest Number by Custom Comparator**: Arrange integers to form the largest possible number. Handle leading zeros.
- 2️⃣ **Minimum Arrows to Burst Balloons Variant**: Arrow shot affects $\pm D$ distance around point.
- 3️⃣ **Check If Array Can Be Sorted by One Segment Reverse**: Boundary detection logic.
- 4️⃣ **Remove Overlapping Intervals with Penalty**: Minimize total penalty to eliminate overlaps.
- 5️⃣ **Zig-Zag Linked List Rearrangement**: Reorder as $a < b > c < d > e \dots$
- 6️⃣ **Stack Sequence Validation with Capacity Limit**: Validate sequence with max stack capacity $C$.
- 7️⃣ **Circular Queue Scheduling**: Tasks with cooldown $K$, minimize idle time.

---

### 🔴 HARD

#### 8️⃣ Count Inversions with Stability Constraint
- Count inversions but treat equal values as non-inversions only if original order preserved.
- **Pattern:** Merge sort + stability invariant.

#### 9️⃣ Minimum Adjacent Swaps to Group All 1s Together
- Binary array arranged circularly. Return minimum swaps.
- **Pattern:** Sorting logic + sliding window twist.

#### 🔟 Partition Array into Minimum Increasing Subsequences
- Partition array into minimum number of strictly increasing subsequences.
- **Pattern:** Greedy + patience sorting invariant + combinatorial reasoning.
- 

---

## ✅ Coverage Achieved

| Requirement | Status |
| :--- | :--- |
| QuickSort partition & Merge invariants | ✔ |
| Stability & Greedy proof logic | ✔ |
| DS Embedded (Stack, LL, Queue) | ✔ |
| Multi-pattern & Triple-pattern blends | ✔ |
| Twist in every problem | ✔ |

Would you like me to generate a deep-dive "Problem Story" for the **QuickSort with Duplicate Compression** hard problem?