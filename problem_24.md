# PART 1 — L4-D6-Q2  

## Suspicious Repeat Alert Within Limited Distance

---

## Question (Story-based)

A security system monitors **badge swipe IDs** as employees enter a restricted area.  
Due to tailgating concerns, the system must **raise an alert** if the *same badge ID* is used **again within the last `K` entries**.

You are given a sequence of badge IDs in the order they were scanned and a number `K`.

Your task is to determine **whether any badge ID repeats within a distance of at most `K` scans**.

The moment such a suspicious repeat is detected, the system should **stop processing and report immediately**.

---

## Input / Output

### Input
- An array of integers representing badge IDs.
- An integer `K` representing the maximum allowed distance between two identical IDs.

### Output
- Return `true` if any ID appears twice with index difference `≤ K`.
- Otherwise, return `false`.

---

## Constraints

- The solution must run in **O(N) time**.
- **Early exit is mandatory** once a valid duplicate is found.
- Re-checking earlier elements repeatedly is **not allowed**.
- Efficient tracking of recently seen IDs is required.

---

## Sample Inputs & Outputs

### Sample Input 1
IDs = [10, 20, 30, 10]
K = 3

shell


### Output
true

yaml


**Explanation:**  
The badge `10` appears again within the last 3 scans.

---

### Sample Input 2
IDs = [5, 6, 7, 5]
K = 2

shell


### Output
false

yaml


**Explanation:**  
The repeated `5` is too far apart (distance > K).

---

### Sample Input 3
IDs = [1, 2, 3, 4]
K = 1

shell


### Output
false

yaml


---

## Notes

- The scan list should be processed **left to right exactly once**.
- Only **recent history** matters — older entries can be safely ignored.
- The problem hides a **sliding window with fast lookup** requirement.
- Returning the answer early improves both performance and clarity.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine you are watching people enter a room.

- You remember only the **last `K` people** who entered.
- When a new person comes in:
  - If you’ve seen them **recently**, raise an alert.
  - Otherwise, note them down.
- If your memory grows beyond `K`, **forget the oldest person**.

You don’t care about people who entered long ago.

---

### Logical Breakdown

We must:
1. Track which IDs are currently in the **last K window**
2. Detect if the incoming ID already exists in that window
3. Remove IDs that fall out of the window as we move forward

This guarantees:
- One pass
- No nested loops
- Immediate detection

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Recent history | Only last K scans matter | Sliding window |
| Fast lookup | Check duplicates instantly | Hash Set / Hash Map |
| Window eviction | Remove outdated IDs | Index-based removal |
| Early exit | Stop once alert is raised | Immediate return |

**Key Insight:**  
Each ID is **added once** and **removed once** → linear time.

---


# Suspicious Repeat Alert: Test Cases & Analysis

This document outlines the test scenarios for the **Suspicious Repeat Alert** (Nearby Duplicates) problem, focusing on the constraint that a duplicate must exist within a distance of at most $K$.

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `IDs: [1, 5, 9, 1], K: 3` | `true` | ID 1 repeats at index 3. Distance $3 - 0 = 3$. Since $3 \leq K$, it is suspicious. |
| `IDs: [1, 2, 3, 1], K: 2` | `false` | ID 1 repeats at index 3. Distance $3 - 0 = 3$. Since $3 > K$, it is ignored. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Immediate Neighbor" (Minimal K)
**Input:** `IDs: [10, 10, 20, 30], K: 1`  
**Output:** `true`

* **Index 0:** Add `10` to window. Window: `{10}`
* **Index 1:** Current ID is `10`. `10` is already in the window!
* **Result:** `true`

> **Explanation:** Tests the smallest possible window ($K=1$) where a repeat must be back-to-back to trigger the alert.

### 2. The "Window Boundary" (Exact Match)
**Input:** `IDs: [1, 2, 3, 4, 1], K: 4`  
**Output:** `true`

* **Indices 0-3:** Add `1, 2, 3, 4` to window. Window: `{1, 2, 3, 4}`
* **Index 4:** ID is `1`. `1` is currently in the window.
* **Result:** `true` (Distance is exactly 4)

> **Explanation:** Validates the "at most $K$" constraint. If the duplicate is exactly $K$ distance away, it still counts.

### 3. The "Moving Eraser" (Old Entries Cleared)
**Input:** `IDs: [1, 2, 3, 1], K: 2`  
**Output:** `false`

* **Index 0:** Window `{1}`
* **Index 1:** Window `{1, 2}`
* **Index 2:** Window reaches size $K$. Add `3`, remove `IDs[0]` (which is `1`). Window: `{2, 3}`
* **Index 3:** ID is `1`. `1` is NOT in the current window.
* **Result:** `false`

> **Explanation:** Confirms the system correctly "forgets" IDs once they fall out of the sliding window of size $K$.

### 4. The "Single Element / Small Input"
**Input:** `IDs: [99], K: 5`  
**Output:** `false`

* **Index 0:** Add `99` to window.
* **End:** No more elements to process.
* **Result:** `false`

> **Explanation:** Checks robustness against inputs where the total number of entries is less than the window size $K$.

### 5. The "Dense Unique" (Max Window)
**Input:** `IDs: [1, 2, 3, 4, 5, 6], K: 10`  
**Output:** `false`

* **Process indices 0-5:** All IDs are added to the window. No duplicates are encountered.
* **Result:** `false`

> **Explanation:** Tests the scenario where $K$ is larger than the actual data set, ensuring the logic doesn't crash when the window never needs to "shrink."