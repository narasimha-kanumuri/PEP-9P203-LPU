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