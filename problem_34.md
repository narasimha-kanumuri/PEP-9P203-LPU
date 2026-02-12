# LEVEL 4 — DAY 7  
## L4-D7-Q6 — The Surveillance Window Analyzer

---

# PART 1

---

## 🧩 Question (Story-Based)

A cybersecurity team monitors a high-security server farm.

Each second, the monitoring system logs a **server ID** that generated activity.

Over time, this produces a long list of integers representing activity patterns.

The chief analyst wants to understand:

> In every continuous monitoring window of size `K`,  
> how many **distinct servers** were active?

This helps detect:
- Sudden spikes in diversity (possible attacks)
- Low diversity (possible bottlenecks)

Your task is to compute, for every window of size `K`,  
the count of **distinct server IDs** inside that window.

---

## 📥 Input

- An integer array `activity`
- An integer `K`

Constraints:
- `1 ≤ activity.length ≤ 10^5`
- `1 ≤ K ≤ activity.length`
- `-10^9 ≤ activity[i] ≤ 10^9`

---

## 📤 Output

- An array of integers
- Each element represents the distinct count for a window

---

## 📌 Constraints (Strict)

- **Hash Map + Sliding Window mandatory**
- Must run in **O(N)** time
- No recomputation for each window
- No sorting
- No nested scanning per window

---

## 🧪 Sample Inputs & Outputs

### Example 1

Input:
activity = [1, 2, 1, 3, 4, 2, 3]
K = 4

makefile
Copy code

Output:
[3, 4, 4, 3]

yaml
Copy code

Explanation:

Windows:
- [1,2,1,3] → 3 distinct
- [2,1,3,4] → 4 distinct
- [1,3,4,2] → 4 distinct
- [3,4,2,3] → 3 distinct

---

### Example 2

Input:
activity = [5, 5, 5, 5]
K = 2

makefile
Copy code

Output:
[1, 1, 1]

yaml
Copy code

---

## 📝 Notes

- You are NOT allowed to:
  - Recompute distinct count for each window from scratch
  - Use nested loops over window elements
- Think about:
  - What changes when window moves?
  - Only one element leaves
  - Only one element enters
- Efficient state maintenance is key.

---

# 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

---

## 🧒 ELI5 Explanation

Imagine looking through a moving camera frame.

- The frame shows `K` seconds at a time.
- Every time it moves:
  - One old second disappears
  - One new second appears

Instead of counting everything again:

- Keep a notebook of:
  - How many times each server appears inside the window
- When a server leaves:
  - Decrease its count
  - If count becomes 0 → remove it
- When a server enters:
  - Increase its count

At any moment:

> The number of distinct servers  
> = size of your notebook.

---

## 🧠 Logical Reasoning

We maintain:

- A **frequency map** for elements inside the window
- A sliding window using two indices:
  - `left`
  - `right`

Algorithm outline:

1. Build first window (size K)
2. Record distinct count
3. Slide window one step at a time:
   - Remove `activity[left]`
   - Add `activity[right]`
4. Update counts efficiently

Each element:
- Enters once
- Leaves once

Total operations → linear

---

## 🔗 Mapping to Code (Conceptual)

We will:

1. Initialize:
   - unordered_map<int,int> freq
   - vector<int> result

2. Process first K elements

3. For i from K to N-1:
   - Remove element i-K
   - Add element i
   - Store freq.size()

---

## 🚫 What Will Break O(N)?

- Clearing map for every window
- Nested scanning
- Sorting window

---

## 🧠 Why This Problem Is Important

This is a classic sliding window pattern used in:

- Network traffic analysis
- Fraud detection
- Real-time log analytics
- Interview hard questions

It teaches:

- State reuse
- Incremental updates
- Frequency tracking

---


# Server Activity Diversity: Test Cases & Analysis

This algorithm monitors a sliding window of server activity logs and counts how many unique (distinct) server IDs are active within that specific time window ($K$).

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `activity: [1, 1, 2, 2], K: 2` | `[1, 2, 1]` | Transitions from identical IDs `[1,1]` (1 distinct) to mixed `[1,2]` (2 distinct) to identical `[2,2]` (1 distinct). |
| `activity: [1, 2, 3], K: 3` | `[3]` | Since the window size equals the array length, there is only one result representing the entire set. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Diversity Spike" (Sudden Change)
**Input:** `activity: [1, 1, 1, 2, 3, 4], K: 3`  
**Output:** `[1, 2, 3, 3]`

* **First Window [1,1,1]:** Freq `{1:3}`. Distinct Count: **1**.
* **Slide to [1,1,2]:** Remove one `1` (count 2), add `2` (count 1). Freq `{1:2, 2:1}`. Distinct Count: **2**.
* **Slide to [1,2,3]:** Remove one `1` (count 1), add `3` (count 1). Freq `{1:1, 2:1, 3:1}`. Distinct Count: **3**.
* **Slide to [2,3,4]:** Remove last `1` (count 0 → erase), add `4` (count 1). Freq `{2:1, 3:1, 4:1}`. Distinct Count: **3**.

> **Explanation:** Shows how the distinct count increments as new unique server IDs enter the monitoring window and old ones are fully removed.

### 2. The "Bottleneck" (Converging to Identity)
**Input:** `activity: [1, 2, 3, 4, 4, 4], K: 3`  
**Output:** `[3, 3, 2, 1]`

* **Initial [1,2,3]:** Size **3**.
* **Slide [2,3,4]:** Size **3**.
* **Slide [3,4,4]:** Remove `2`, add `4`. Freq `{3:1, 4:2}`. Size **2**.
* **Slide [4,4,4]:** Remove `3`, add `4`. Freq `{4:3}`. Size **1**.

> **Explanation:** Demonstrates the logic for decreasing distinct counts as diverse IDs leave the window and are replaced by repeating IDs.

### 3. The "Alternating Pulse" (Oscillation)
**Input:** `activity: [1, 0, 1, 0, 1], K: 2`  
**Output:** `[2, 2, 2, 2]`

* **[1,0]:** 2 distinct.
* **[0,1]:** 2 distinct.
* **[1,0]:** 2 distinct.
* **[0,1]:** 2 distinct.

> **Explanation:** Tests the map's ability to handle frequent additions and removals of the same IDs without losing track of the distinct count.

### 4. The "Unique Streak" (Maximum Diversity)
**Input:** `activity: [10, 20, 30, 40], K: 2`  
**Output:** `[2, 2, 2]`

* **Dry Run:** Every window will remove one unique ID and add a completely different unique ID. The map size (distinct count) will stay constant at $K$.

> **Explanation:** Validates that the system correctly maintains the maximum possible diversity count when all elements in the window are unique.

### 5. The "Negative ID Range" (Full Range Search)
**Input:** `activity: [-1, 5, -1, 5], K: 2`  
**Output:** `[2, 2, 2]`

* **[-1, 5]:** Count 2.
* **[5, -1]:** Count 2.
* **[-1, 5]:** Count 2.

> **Explanation:** Confirms the hash map correctly handles negative integers, which are common in server rack IDs or offset-based logging systems.