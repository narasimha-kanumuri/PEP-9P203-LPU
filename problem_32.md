# LEVEL 4 — DAY 7  
## L4-D7-Q4 — The Research Lab Memory System

---

# PART 1

---

## 🧩 Question (Story-Based)

A high-security research lab runs thousands of experiments daily.

Each experiment produces a **result file**, identified by an integer ID.

The lab’s supercomputer has **very limited fast-access memory**.  
It can only store a fixed number of experiment results at a time.

When a scientist requests a result:

- If the result is already in fast memory → it is returned instantly.
- If not → it must be fetched from slow storage and loaded into memory.

However, when memory is full:

> The system must remove the experiment result that has not been used for the longest time.

This replacement policy must always be maintained.

Your task is to design a memory system that supports:

- `get(id)` → return the result if present, otherwise `-1`
- `put(id, value)` → insert or update a result

Both operations must run in **O(1)** time.

---

## 📥 Input (Conceptual)

The system will be initialized with:

- An integer `capacity`

Then a sequence of operations:

- `get(id)`
- `put(id, value)`

---

## 📤 Output

For each `get(id)` operation:

- Return the stored value
- Return `-1` if not present

---

## 📌 Constraints

- `1 ≤ capacity ≤ 10^5`
- `0 ≤ id, value ≤ 10^9`
- Up to `10^5` operations
- Both operations must run in **O(1)** average time
- Must use:
  - **Hash Map**
  - **Doubly Linked List**
- Eviction rule must follow:
  - Remove the **Least Recently Used** item
- The eviction invariant must be clearly maintained

---

## 🧪 Example Scenario

Capacity = 2

Operations:

put(1, 10)
put(2, 20)
get(1) → returns 10
put(3, 30) → evicts key 2
get(2) → returns -1
put(4, 40) → evicts key 1
get(1) → returns -1
get(3) → returns 30
get(4) → returns 40



---

## 📝 Notes

- You are NOT told directly which structure to use.
- Array or vector-based shifting will violate O(1).
- A single hash map alone is insufficient.
- A singly linked list alone is insufficient.
- Think about:
  - Fast lookup
  - Fast deletion
  - Fast reordering
- This is a **design-heavy problem**, not just implementation.

---

# 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

---

## 🧒 ELI5 Explanation

Imagine a bookshelf that can hold only **2 books**.

Every time you read a book:
- You move it to the **front of the shelf**

When you add a new book:
- If shelf is full:
  - Remove the book at the **back**
  - That’s the one nobody touched for the longest time

To do this efficiently:
- You need:
  - A way to quickly find any book → index book by ID
  - A way to quickly move books around → reorder instantly

---

## 🧠 Logical Reasoning

We need to maintain two properties:

1. **Fast lookup by key**
   → Hash Map (key → node)

2. **Fast reordering of usage**
   → Doubly Linked List

Why Doubly Linked List?
- We must:
  - Remove any node in O(1)
  - Move node to front in O(1)
  - Remove tail in O(1)

A singly linked list cannot remove arbitrary node in O(1)  
An array requires shifting → O(N)

---

## 🔐 Core Invariant (Very Important)

At all times:

- Head of list = Most Recently Used (MRU)
- Tail of list = Least Recently Used (LRU)
- Hash map always points to nodes currently in list

Eviction Rule:

When capacity exceeded:
- Remove node at tail
- Delete its key from hash map

---

## 🧱 Data Structure Design

We will need:

### 1. Doubly Linked List Node:
- key
- value
- prev pointer
- next pointer

### 2. Hash Map:
- key → pointer to corresponding node

---

## 🔄 Operation Design

### get(id):

- If not in map → return -1
- If present:
  - Move node to front (mark as recently used)
  - Return value

---

### put(id, value):

Case 1: Key exists
- Update value
- Move node to front

Case 2: Key does not exist
- If capacity full:
  - Remove tail node
  - Delete its key from map
- Create new node
- Insert at front
- Add to map

---

## 🚫 What Will Break O(1)?

- Searching linked list linearly
- Using vector erase
- Using sorting
- Using priority queue

---

## 🧠 Why This Problem Is Important

This is a **classic systems design pattern** used in:

- Operating systems page replacement
- Database caching
- Web server caching
- CPU memory management

But your implementation must be built from scratch.

---

