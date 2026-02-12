# LEVEL 4 — DAY 5  

## L4-D5-Q4: Elevator Emergency Display (with a Twist)  

### PART 1 — Question, Explanation & Notes

---

## 1. Problem Statement (Story Form)

A high-rise building uses a **smart elevator system**.

As people enter and exit the elevator, the system tracks their **weights**.  
For safety reasons, the control panel must **always display the minimum weight currently inside** the elevator.

This display is **critical**:

- It must update **instantly**
- It must work even during rapid enter/exit operations

The system engineers warn you:

> “We don’t have memory for extra tracking devices.”

---

## 2. The Twist (Very Important)

You are **not allowed** to keep a separate structure just to track minimum values.

That means:

- ❌ No second stack  
- ❌ No arrays, vectors, maps, or lists  
- ❌ No global containers  
- ❌ No storing all past minimums separately  

You must design the system so that:
> **The main structure itself carries enough information to recover the minimum at any time.**

---

## 3. Clarified Task

Design a data structure that supports the following operations:

- `enter(weight)`  
- `exit()`  
- `getMinimumWeight()`

All operations must run in **O(1)** time.

---

## 4. Input / Output Expectations

This is a **design + implementation** problem.

Your solution must:

- Provide the above operations
- Correctly return the minimum weight at any moment
- Work even with:
  - Negative weights
  - Duplicate values
  - Arbitrary sequences of operations

---

## 5. Constraints (Strict)

- All operations must be **O(1)**
- Only **one stack-like structure** allowed
- No auxiliary stack
- No array or vector
- No post-processing
- You must be able to **prove correctness using an invariant**

---

## 6. Implementation Narrative  

### (ELI5 → English-to-Code)

This problem is **not solved by remembering all minimums**.

Instead, we do something clever:
> We **encode extra information** inside the values we store.

---

### Key Insight (Mental Model)

At any moment, the system needs to know:

- The current minimum
- What the previous minimum was **before the last change**

Instead of storing previous minimums separately:
> We hide that information **inside the stack itself**.

---

### Core Idea

We maintain:

- A variable `currentMin`
- A single stack

When a new value is added:

- If it is **not smaller** than `currentMin`:
  - Push it normally
- If it **is smaller**:
  - Push a **transformed value**
  - Update `currentMin`

This transformed value acts like:
> A **marker** that tells us how to restore the old minimum later.

---

### Step-by-Step Logic

#### Operation: `enter(x)`

1. If the stack is empty:
   - Push `x`
   - Set `currentMin = x`

2. Else if `x >= currentMin`:
   - Push `x`
   - Minimum does not change

3. Else (`x < currentMin`):
   - Push a **special encoded value**
   - Update `currentMin = x`

This encoded value remembers:

- The new minimum
- Enough information to restore the old one

---

#### Operation: `exit()`

1. If the stack is empty:
   - This is an invalid operation

2. Pop the top value:
   - If it is a **normal value**:
     - Just remove it
   - If it is an **encoded value**:
     - This means the minimum is changing
     - Decode it to restore the **previous minimum**

---

#### Operation: `getMinimumWeight()`

- Simply return `currentMin`
- No traversal
- No computation

---

## 7. Correctness Invariant (Core of the Problem)

At all times:
currentMin = minimum of all actual values currently in the stack


Additionally:
- Encoded values exist **only** to restore previous minimums
- They are never exposed as real data

As long as this invariant holds:
- `getMinimumWeight()` is always correct
- Pop operations correctly restore old minimums

---

## 8. Notes

### Why Auxiliary Stack Is Banned
- Using a second stack trivializes the problem
- This question tests **state encoding and invariants**

### Why Encoding Works
- Each encoded value acts as a reversible checkpoint
- Stack structure naturally restores state in reverse order

### Common Student Mistakes
- Using a second stack ❌
- Forgetting to update minimum on pop ❌
- Not handling negative numbers ❌
- Breaking invariant during duplicate minimums ❌

---

### Hidden Data Structure Insight (for instructors)

- This is a **Min Stack without auxiliary space**
- Uses **value encoding**
- Tests understanding of:
  - Stack invariants
  - Reversible state transitions
  - O(1) algorithm design

---

## End of PART 1