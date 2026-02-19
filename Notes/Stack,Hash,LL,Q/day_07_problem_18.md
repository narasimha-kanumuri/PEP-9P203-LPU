# LEVEL 4 — DAY 5  

## L4-D5-Q2: Next Warmer Day Forecast (Linked Sensors)  

### PART 1 — Question, Explanation & Notes

---

## 1. Problem Statement (Story Form)

A weather research team deploys temperature sensors in a straight line.

Each sensor:

- Stores **one temperature value**
- Knows **only the next sensor ahead**

So the sensors together form a **one-way chain**.

For analysis, the team wants to know for **each sensor**:

> “What is the temperature of the **next sensor ahead** that reports a **higher value** than mine?”

If no such sensor exists ahead, the value should be recorded as **0**.

---

## 2. Clarified Task

Given the head of a **singly linked list** of integers:

- For every node, determine the **next node to the right** that has a **greater value**
- Construct and return a **new singly linked list** containing these results
- The original list must remain unchanged

---

## 3. Input / Output Specification

### Input

- Head pointer of a singly linked list  
  Example:
2 → 1 → 5

### Output

- Head pointer of a new singly linked list
5 → 5 → 0

---

## 4. Constraints (Strict)

- Input is a **singly linked list**
- Only **one forward traversal** allowed
- Total time complexity must be **O(N)**
- **No nested loops**
- Use of an **auxiliary mechanism** is mandatory
- Output must be a **new linked list**, not an array

---

## 5. Implementation Narrative  

### (ELI5 → English-to-Code)

We will explain this **as if converting English directly into code logic**.

---

### Core Difficulty

From a given node, you **cannot see backward**.  
But the answer for a node may appear **later** in the list.

So when you move forward:

- You must **remember unresolved nodes**
- And resolve them **when a higher value appears**

---

### Key Insight

When a new temperature appears:

- It may answer the question for **multiple previous sensors**
- But only those that are **waiting for a higher value**

So we need:
> A way to remember past nodes **that still need answers**

---

### Step-by-Step Logic

1. Start traversing the linked list from the head.

2. Maintain:

- A structure to store **nodes whose answer is not yet known**
- Each stored element remembers:
  - The node’s value
  - Where its answer should be written in the output list

1. For each node you visit with value `currentValue`:

#### While there exists a previous node waiting

- Compare its value with `currentValue`
- If `currentValue` is **greater**:
  - This is the answer for that node
  - Fill its output value
  - Remove it from the waiting list
- Stop when:
  - Waiting node has value ≥ `currentValue`, or
  - No waiting nodes remain

1. After resolving what you can:

- Mark the current node as **waiting**
- Its answer is unknown yet

1. Move to the next node and repeat.

2. After traversal ends:

- Any node still waiting has **no greater value ahead**
- Their output remains **0**

1. Finally:

- Return the head of the newly constructed output linked list

---

### What Is Actually Happening (Mental Model)

- Values go **in one direction**
- Answers appear **later**
- Waiting nodes are resolved **only once**
- No node is revisited or compared more than necessary

This guarantees **linear time**.

---

## 6. Notes

### Why Nested Loops Fail

- For each node, scanning ahead leads to **O(N²)** time
- Disallowed by constraints

### Why Extra Memory Is Necessary

- Singly linked lists do not allow backward access
- We must **remember unresolved nodes explicitly**

### Common Student Mistakes

- Trying to modify the input list ❌
- Using arrays for output ❌
- Using double traversal ❌
- Forgetting to initialize unanswered values to 0 ❌

---

### Hidden Data Structure Insight (for instructors)

- This is a **Next Greater Element** problem
- The required structure is a **monotonic decreasing stack**
- Stack enforces:
waiting values are strictly decreasing

- Each node is:
- Pushed once
- Popped once
- That is why the solution is **O(N)**

---

## End of PART 1
