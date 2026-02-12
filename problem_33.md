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
