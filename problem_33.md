# LEVEL 4 — DAY 7  

## L4-D7-Q5 — The Financial Audit Anomaly

---

# PART 1

---

## 🧩 Question (Story-Based)

A financial intelligence team is auditing a suspicious transaction log.

Each entry in the log represents:

- A positive number → money credited
- A negative number → money debited

The auditors suspect that at some point in the timeline:

> The total running balance might have returned to zero.

If that happens, it means there exists a **continuous block of transactions**
where the total net change was exactly zero.

Your task is to determine:

> Does there exist any continuous sequence of transactions whose total sum is exactly zero?

If yes → return `true`  
If not → return `false`

---

## 📥 Input

- An integer array `transactions`
- `1 ≤ transactions.length ≤ 10^5`
- `-10^9 ≤ transactions[i] ≤ 10^9`

---

## 📤 Output

- `true` → if a zero-sum subarray exists  
- `false` → otherwise

---

## 📌 Constraints

- **Hashing is mandatory**
- Must use **prefix-sum reasoning**
- **O(N)** time required
- Sorting is NOT allowed
- Nested scanning is NOT allowed
- Early termination preferred

---

## 🧪 Sample Inputs & Outputs

| Input | Output | Explanation |
|-------|--------|-------------|
| `[4, 2, -3, 1, 6]` | `true` | Subarray `[2, -3, 1]` sums to 0 |
| `[1, 2, 3]` | `false` | No zero-sum block |
| `[1, -1]` | `true` | Entire array sums to 0 |
| `[3, -1, -2, 5]` | `true` | First three elements sum to 0 |

---

## 📝 Notes

- You are NOT told to compute prefix sums explicitly.
- You must infer:
  - Running totals matter
  - Repeated totals imply something important
- Brute force (checking all subarrays) is unacceptable.
- Think in terms of:
  - “Have I seen this total before?”

---

# 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

---

## 🧒 ELI5 Explanation

Imagine walking along a path and keeping track of how far you've moved from the starting point.

- You start at position 0.
- After each step (transaction), you update your position.
- If at any moment:
  - You return to a position you’ve already been at,
  - That means the movement between those two moments cancelled out.

Similarly:

- If your running sum becomes 0 → you returned to starting balance.
- If your running sum repeats:
  - That means the transactions in between sum to 0.

---

## 🧠 Logical Reasoning

Let:

`prefixSum[i] = transactions[0] + ... + transactions[i]`

If:

`prefixSum[i] == prefixSum[j]` (where i < j)

Then:

`transactions[i+1 ... j]` sums to zero.

So the strategy becomes:

- Maintain a running sum
- Store all seen prefix sums in a hash set
- If:
  - runningSum == 0 → return true
  - runningSum already seen → return true
- Else:
  - insert runningSum into set
- Continue scanning

---

## 🔗 Mapping to Code (Conceptual)

We will:

1. Initialize:
   - runningSum = 0
   - hashSet to store prefix sums

2. Traverse array:
   - runningSum += current element
   - If runningSum == 0 → return true
   - If runningSum exists in set → return true
   - Else insert into set

3. If traversal ends → return false

---

## 🚫 What Will Break O(N)?

- Nested loops checking all subarrays
- Recomputing sums repeatedly
- Sorting the array

---

## 🧠 Why This Problem Is Important

This is foundational for:

- Subarray sum problems
- Longest zero-sum block
- Count of zero-sum subarrays
- Prefix-sum + hashing design pattern

It teaches recognition of **hidden cancellation patterns**.

---

# Zero-Sum Transaction Detection: Test Cases & Analysis

This algorithm identifies if any contiguous sequence of transactions in a financial log results in a net change of zero. This is a classic application of the **Prefix Sum** pattern combined with a **Hash Set** for $O(n)$ detection.

---

## Additional Sample Test Cases

| Sample Input | Output | Explanation |
| :--- | :--- | :--- |
| `[10, -10]` | `true` | The first transaction is canceled out exactly by the second, returning the balance to zero. |
| `[5, 4, -2, -2]` | `true` | The sequence `[4, -2, -2]` sums to zero; the prefix sum becomes 9, then 7, then returns to 5 (already seen). |

---

## 5 Variety Test Cases (with Dry Runs)

### 1. The "Hidden Interior" Case
**Input:** `[10, 5, -2, -3, 8]`  
**Output:** `true`

* **amount = 10:** `runningSum = 10`. Not in `seenSums`. Add `{10}`.
* **amount = 5:** `runningSum = 15`. Not in `seenSums`. Add `{10, 15}`.
* **amount = -2:** `runningSum = 13`. Not in `seenSums`. Add `{10, 15, 13}`.
* **amount = -3:** `runningSum = 10`. **ALREADY SEEN!** (seen at step 1).

> **Explanation:** Since the running sum returned to 10, the transactions that occurred after the first 10 (`-2` and `-3`) must have summed to zero.

### 2. The "Immediate Zero" Case
**Input:** `[0, 5, 10]`  
**Output:** `true`

* **amount = 0:** `runningSum = 0`.
* **Check:** `runningSum == 0` is true. Immediate return.

> **Explanation:** A transaction of 0 is technically a subarray that sums to zero. The algorithm detects this at the very first index.

### 3. The "Full Circle" Case
**Input:** `[1, 2, 3, -6]`  
**Output:** `true`

* **runningSum sequence:** `1 → 3 → 6 → 0`.
* **Step 4:** At the final step, `runningSum` becomes 0.
* **Result:** `true`

> **Explanation:** This tests the case where the entire array, from start to finish, cancels out to a net change of zero.

### 4. The "Oscillating Balance" Case
**Input:** `[1, -1, 1, -1]`  
**Output:** `true`

* **amount = 1:** `runningSum = 1`. Add `{1}`.
* **amount = -1:** `runningSum = 0`. Return `true`.

> **Explanation:** Even though the balance fluctuates, the very first time it hits a duplicate prefix sum (or zero), the algorithm terminates early for maximum efficiency.

### 5. The "No Anomaly" Case (Negative/Positive Mix)
**Input:** `[5, -2, 10, -4, 1]`  
**Output:** `false`

* **runningSum sequence:** `5, 3, 13, 9, 10`.
* **seenSums set:** `{5, 3, 13, 9, 10}`.
* **Result:** `false` (No sum was 0 and no sum was ever repeated).

> **Explanation:** Even with a mix of debits and credits, if the running balance never returns to a previous state, no zero-sum "loop" exists in the financial log.