# LEVEL 4 — DAY 7  
## L4-D7-Q3 — The Power Grid Restoration Problem

---

## PART 1

---

## 🧩 Question (Story-Based)

A city recently suffered a cyber attack that disrupted its smart power grid.

Each power station is assigned an **integer ID**.  
After recovery, engineers receive a list of station IDs that are currently active.

However, they discover something important:

- Some stations form **continuous operational chains**  
  (e.g., station 101, 102, 103 are consecutive and form a stable block)
- Other stations are isolated or scattered

The chief engineer wants to measure **system stability**.

> Stability is defined as the length of the longest chain of consecutively numbered active stations.

⚠️ Important:
- The station list is **unsorted**
- IDs may be large (up to 10⁹)
- Duplicate entries may exist
- You must detect the longest consecutive chain
- Sorting the list is strictly forbidden

Return the **length of the longest consecutive sequence**.

---

## 📥 Input

- An integer array `stations`
- `1 ≤ stations.length ≤ 10^5`
- `-10^9 ≤ stationID ≤ 10^9`

---

## 📤 Output

- A single integer representing the length of the longest consecutive sequence

---

## 📌 Constraints

- **Hashing is mandatory**
- **O(N) time required**
- Sorting is NOT allowed
- No nested scanning of entire array
- Must avoid recomputation for each element

---

## 🧪 Sample Inputs & Outputs

| Input | Output | Explanation |
|-------|--------|-------------|
| `[100, 4, 200, 1, 3, 2]` | `4` | Sequence: 1,2,3,4 |
| `[10, 5, 6, 7, 1]` | `3` | Sequence: 5,6,7 |
| `[1,2,2,3]` | `3` | Duplicates ignored |

---

## 📝 Notes

- The list is unsorted.
- Consecutive means `x, x+1, x+2, ...`
- Order in the array does NOT matter.
- You must think in terms of:
  - Fast membership lookup
  - Avoid expanding sequences multiple times
- This problem tests your ability to:
  - Detect natural sequence starting points
  - Avoid quadratic scanning

---

## 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

---

### 🧒 ELI5 Explanation

Imagine you have a bag of numbered tiles.

Instead of sorting them, you:

1. Put all tiles into a **magic lookup box**
   → You can instantly check if a number exists.

2. For every tile:
   - Ask:  
     “Is this the beginning of a chain?”
   - A tile is the beginning only if:
     - The number just before it (number - 1) does NOT exist

3. If it is a beginning:
   - Keep checking:
     - Does next number exist?
     - Does next next number exist?
   - Count how long this chain continues.

4. Keep track of the longest chain found.

That’s it.

---

### 🧠 Logical Reasoning

Key Insight:

If we expand from every number blindly → O(N²)

Instead:
- Only expand when we find a **sequence start**
- A number is a start if `(num - 1)` does NOT exist

This guarantees:
- Each number is processed at most once in expansion
- Total complexity stays linear

---

### 🔗 Mapping to Code (Conceptual)

We will:

1. Insert all numbers into a **hash set**
2. For each number:
   - If `(num - 1)` is NOT in set:
     - This is a sequence start
     - Expand forward:
       - Check `num + 1`, `num + 2`, ...
3. Track maximum length

This avoids:
- Sorting
- Nested loops over entire array
- Redundant scanning

---


# Longest Consecutive Chain: Test Cases & Analysis

This algorithm identifies the longest sequence of integers that can be formed using numbers from the input array, where each number in the sequence is exactly 1 greater than the previous one. The numbers do not need to be adjacent in the original array.

---

## Additional Sample Test Cases

| Sample Input | Output | Explanation |
| :--- | :--- | :--- |
| `[9, 1, 4, 7, 3, -1, 0, 5, 8, 2]` | `6` | The longest chain is `[-1, 0, 1, 2, 3, 4, 5]`. |
| `[10, 20, 30, 40]` | `1` | No stations are consecutive; the "longest" chains are all of length 1. |

---

## 5 Variety Test Cases (with Dry Runs)

### 1. The "Negative Bridge" Case
**Input:** `[-3, 2, -1, 0, -2]`  
**Output:** `4`

* **Set:** `{-3, -2, -1, 0, 2}`
* **Check -3:** `-4` not in set. Start expansion. Chain: `-3, -2, -1, 0`. Length = **4**.
* **Check 2:** `1` not in set. Start expansion. Chain: `2`. Length = 1.
* **Check -1, 0, -2:** All have `(num-1)` in set. Skip.

> **Explanation:** Validates that the logic holds across the zero-boundary and correctly handles negative integer coordinates.

### 2. The "Large Gap" Case
**Input:** `[1, 1000000, 2, 1000001, 3]`  
**Output:** `3`

* **Set:** `{1, 2, 3, 1000000, 1000001}`
* **Check 1:** `0` not in set. Start. Chain: `1, 2, 3`. Length = **3**.
* **Check 1000000:** `999,999` not in set. Start. Chain: `1000000, 1000001`. Length = 2.

> **Explanation:** Demonstrates that the absolute value of the IDs doesn't affect performance; hashing handles large numbers in $O(1)$ without needing a massive array.

### 3. The "Dense Duplicates" Case
**Input:** `[1, 2, 1, 3, 2, 1]`  
**Output:** `3`

* **Set:** `{1, 2, 3}` (Duplicates are automatically collapsed by the hash set).
* **Check 1:** `0` not in set. Start. Chain: `1, 2, 3`. Length = **3**.

> **Explanation:** Ensures that redundant IDs in the logbook don't artificially inflate the chain length or cause extra processing cycles.

### 4. The "Descending Order" Input
**Input:** `[5, 4, 3, 2, 1]`  
**Output:** `5`

* **Set:** `{1, 2, 3, 4, 5}`
* **Check 5, 4, 3, 2:** All have `(num-1)` in set. Skip.
* **Check 1:** `0` not in set. Start. Chain: `1, 2, 3, 4, 5`. Length = **5**.

> **Explanation:** Tests the "Sequence Start" logic. Even if the array is given in reverse, the algorithm waits until it hits the absolute minimum of the chain before expanding.

### 5. The "Single Link Interruption"
**Input:** `[1, 2, 3, 5, 6, 7]`  
**Output:** `3`

* **Set:** `{1, 2, 3, 5, 6, 7}`
* **Check 1:** `0` not in set. Start. Chain: `1, 2, 3`. Length = **3**.
* **Check 5:** `4` not in set. Start. Chain: `5, 6, 7`. Length = **3**.

> **Explanation:** Confirms the algorithm correctly resets and identifies separate chains when exactly one middle number (the number 4) is missing.