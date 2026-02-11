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