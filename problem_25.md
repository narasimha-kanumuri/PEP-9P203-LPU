# PART 1 — L4-D6-Q3  
## Longest Streak Without Repeated Visitors

---

## Question (Story-based)

A museum tracks visitors using **wristband IDs** as they walk through a long exhibition hallway.

The museum curator wants to know the **longest continuous stretch of visitors** such that **no wristband ID repeats within that stretch**.

You are given the sequence of wristband IDs in the exact order they were detected.

Your task is to find the **length of the longest contiguous segment** where **all IDs are unique**.

---

## Input / Output

### Input
- An array of integers representing wristband IDs.

### Output
- An integer representing the **maximum length** of a contiguous subarray with all distinct elements.

---

## Constraints

- The solution must run in **O(N) time**.
- Only **one pass** through the array is allowed.
- **Nested loops are not permitted**.
- Efficient tracking of seen elements is required.

---

## Sample Inputs & Outputs

### Sample Input 1
IDs = [1, 2, 3, 1, 2, 3, 4]

shell


### Output
4

yaml


**Explanation:**  
The longest unique stretch is `[1, 2, 3, 4]`.

---

### Sample Input 2
IDs = [5, 5, 5, 5]

shell


### Output
1

yaml


---

### Sample Input 3
IDs = []

shell


### Output
0

yaml


---

## Notes

- The subarray must be **contiguous**.
- Removing or reordering elements is not allowed.
- The problem hides a **sliding window with memory** approach.
- Forgetting old elements correctly is crucial.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine walking along the hallway and writing down visitor IDs on a board.

- You want the board to always show **only unique IDs**.
- When a repeated ID appears:
  - You start erasing from the left until that ID becomes unique again.
- At every step:
  - You measure how long the board currently is.
  - You remember the **longest length** seen so far.

You never walk backward — only forward.

---

### Logical Breakdown

We need to:
1. Keep track of **where each ID was last seen**
2. Maintain a window `[left … right]` that contains only unique IDs
3. Move the left boundary forward when duplicates appear
4. Update the maximum window size during traversal

This ensures:
- Each index is visited once
- The window only expands or contracts forward

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Window start | Marks valid unique range | `left` pointer |
| Current index | Expands the window | `right` pointer |
| Last seen position | Detects duplicates | Hash Map |
| Max length | Final answer | Integer tracker |

**Key Insight:**  
The left pointer never moves backward → linear time guarantee.

---


# Longest Unique Streak: Test Cases & Analysis

This problem focuses on finding the maximum length of a contiguous subarray where every element is unique. It uses a **Sliding Window** approach with two pointers: `left` and `right`.

---

## Additional Sample Test Cases

| Sample Input | Output | Explanation |
| :--- | :--- | :--- |
| `[1, 2, 3, 4, 5]` | `5` | All IDs are unique; the longest streak is the entire array. |
| `[1, 2, 1, 2, 1]` | `2` | Duplicates appear quickly; any unique streak is capped at length 2 (e.g., `[1, 2]`). |

---

## 5 Variety Test Cases (with Dry Runs)

### 1. The "Mid-Array Reset"
**Input:** `[10, 20, 30, 20, 40, 50]`  
**Output:** `4`

* **right=0..2:** Window is `[10, 20, 30]`. `maxLen = 3`.
* **right=3:** ID `20` seen at index 1. `left` moves to $1 + 1 = 2$. Window is `[30, 20]`.
* **right=4..5:** Window expands to `[30, 20, 40, 50]`. `maxLen` updates to **4**.

> **Explanation:** Tests the ability to shift the `left` pointer to the middle of the array and continue growing.

### 2. The "Staircase" (Increasing Unique Chains)
**Input:** `[1, 2, 1, 2, 3, 1, 2, 3, 4]`  
**Output:** `4`

* **Streak 1:** `[1, 2]` (Len 2) - `1` repeats, `left` shifts.
* **Streak 2:** `[2, 1, 3]` (Len 3) - `2` repeats, `left` shifts.
* **Streak 3:** `[1, 2, 3, 4]` (Len 4) - `1` repeats, `left` shifts.

> **Explanation:** Validates that the algorithm correctly updates `maxLen` as longer unique segments appear progressively later.

### 3. The "Sandwiched Duplicate"
**Input:** `[1, 2, 3, 2, 1]`  
**Output:** `3`

* **right=0..2:** Window `[1, 2, 3]`. `maxLen = 3`.
* **right=3:** `2` repeats. `left` jumps to index 2 (immediately after the first `2`). Window: `[3, 2]`.
* **right=4:** `1` repeats, but its last seen index (0) is **less than** `left` (2). We ignore it. Window: `[3, 2, 1]`.

> **Explanation:** Crucial test for the `lastSeen[id] >= left` condition. It ensures the `left` pointer never moves backward for duplicates already outside the current window.

### 4. The "Bookends" (Repeat at Start and End)
**Input:** `[9, 1, 2, 3, 9]`  
**Output:** `4`

* **right=0..3:** Window `[9, 1, 2, 3]`. `maxLen = 4`.
* **right=4:** `9` is seen at index 0. `left` moves to $0 + 1 = 1$. Window: `[1, 2, 3, 9]`.
* **Result:** `maxLen` stays **4**.

> **Explanation:** Checks if the algorithm handles a duplicate that spans the entire length of the previous maximum unique streak.

### 5. Single Element / All Identical
**Input:** `[7, 7, 7, 7]`  
**Output:** `1`

* **right=0:** `left=0`, `maxLen=1`.
* **right=1:** `7` seen at index 0. `left` moves to index 1. Window `[7]`. `maxLen=1`.
* **right=2..3:** Pattern repeats. `left` always catches up to `right`.

> **Explanation:** Edge case ensuring that if no two elements are unique, the length never exceeds 1 regardless of array size.