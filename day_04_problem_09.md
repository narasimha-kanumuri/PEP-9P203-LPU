# L3-Q6: Add Two Numbers Represented by Singly Linked Lists (Forward Order)

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

You are given two **non-empty singly linked lists** representing two **non-negative integers**.  
- Each node contains a **single digit (0–9)**.
- The digits are stored in **forward order**.

Add the two numbers and return the sum as a **new singly linked list**, also in **forward order**.

---

### Constraints

- Digits are stored **most significant digit first**.
- **Input lists must NOT be modified** (no reversing, no mutation).
- Lengths of the two lists **may differ**.
- Result may have an **extra carry digit** at the front.
- Only **singly linked list operations** are allowed.
- **No array-based digit reconstruction** of the full number.
- Time complexity must be **O(N)**.
- Extra space allowed only if **logically justified** (e.g., recursion stack or explicit stack).
- Pointer safety and correctness are mandatory.

---

### Examples

#### Example 1
```
Input:
L1: 7 → 2 → 4 → 3
L2: 5 → 6 → 4

Output:
7 → 8 → 0 → 7
```

Explanation:
```
7243 + 564 = 7807
```

---

#### Example 2
```
Input:
L1: 9 → 9 → 9
L2: 1

Output:
1 → 0 → 0 → 0
```

---

#### Example 3
```
Input:
L1: 0
L2: 0

Output:
0
```

---

### ELI5 (Explain Like I’m 5)

You are adding two numbers **from left to right**, but addition normally happens **from right to left** (units place first).

Since you are **not allowed to turn the lists around**, you must find a clever way to:
- Reach the **last digits first**
- Add them
- Carry the result back toward the front

Think of it like:
> You can’t walk backward on a bridge, but you can **climb up**, look down, and come back with answers.

---

### Key Insight (Why This Is a Level 3 Problem)

- You **cannot reverse** the input lists.
- You **cannot add directly** from the head.
- Carry propagation goes **backward**, but pointers only go **forward**.

So the core challenge is:
> How do we simulate backward addition on a forward-only structure?

---

### High-Level Strategy

We solve this in **three logical phases**:

1. **Align the lists by length**
2. **Add digits recursively from the tail**
3. **Handle leftover carry at the head**

---

### Deep Implementation Narrative (English → Code Mapping)

#### Step 1: Compute Lengths

- Traverse `L1` and `L2` separately.
- Count the number of nodes in each list.
- Let lengths be `len1` and `len2`.

**Why?**  
To know which list reaches the “units place” later.

**Code Mapping**
- Function: `int getLength(Node* head)`
- Loop until `nullptr`, increment counter.

---

#### Step 2: Recursive Addition Core

We define a recursive function that:
- Moves forward until both lists are aligned at the **same distance from the end**
- Then adds digits **while returning back up the recursion stack