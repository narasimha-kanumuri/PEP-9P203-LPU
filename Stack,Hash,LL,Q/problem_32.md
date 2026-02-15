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




# LRU Cache: Test Cases & Analysis

The **Least Recently Used (LRU) Cache** organizes items in order of use, allowing you to quickly identify which item hasn't been accessed for the longest time. When the cache reaches capacity, it evicts the least recently used item before adding a new one.

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `Cap: 1, put(1, 10), put(2, 20), get(1)` | `-1` | With a capacity of 1, every new `put` evicts the previous item; `1` is gone when `2` arrives. |
| `Cap: 2, put(1, 10), put(1, 20), get(1)` | `20` | Updating an existing key changes its value and refreshes its "recency" without triggering eviction. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Ping-Pong" Effect (Recency Refresh)
**Input:** `Capacity: 2, put(1, 10), put(2, 20), get(1), put(3, 30), get(2)`  
**Output:** `get(1) → 10, get(2) → -1`

* **put(1, 10):** List: `[1]`, Map: `{1}`
* **put(2, 20):** List: `[2, 1]`, Map: `{1, 2}`
* **get(1):** Node 1 moved to front. List: `[1, 2]`. Returns `10`.
* **put(3, 30):** Capacity full. Evict LRU (tail), which is `2`. Insert `3`. List: `[3, 1]`.
* **get(2):** Not in map. Returns `-1`.

> **Explanation:** Tests that `get` operations successfully move an item to the "Most Recently Used" position, protecting it from the next eviction.

### 2. The "Update Priority" (Value Change)
**Input:** `Capacity: 2, put(1, 10), put(2, 20), put(1, 100), put(3, 30), get(2)`  
**Output:** `get(2) → -1`

* **put(1, 10), put(2, 20):** List: `[2, 1]`
* **put(1, 100):** Key 1 exists. Update value to 100 and move to front. List: `[1, 2]`.
* **put(3, 30):** Evict LRU (tail), which is `2`. List: `[3, 1]`.
* **get(2):** Not found. Returns `-1`.

> **Explanation:** An update via `put` must act exactly like a `get` regarding recency—it must move the updated element to the head.

### 3. The "Full Cycle" (Capacity Boundary)
**Input:** `Capacity: 3, put(1, 1), put(2, 2), put(3, 3), put(4, 4), get(1)`  
**Output:** `get(1) → -1`

* **put(1, 1), put(2, 2), put(3, 3):** List: `[3, 2, 1]`.
* **put(4, 4):** Capacity (3) reached. Evict `1`. List: `[4, 3, 2]`.
* **get(1):** Returns `-1`.

> **Explanation:** Verifies the basic "First-In, First-Out" behavior when no intermediate `get` calls disturb the access order.

### 4. The "Single Cell" (Minimal Capacity)
**Input:** `Capacity: 1, put(1, 10), get(1), put(2, 20), get(1)`  
**Output:** `get(1) → 10, get(1) → -1`

* **put(1, 10):** List: `[1]`.
* **get(1):** Returns `10`.
* **put(2, 20):** Evict `1`, insert `2`. List: `[2]`.
* **get(1):** Returns `-1`.

> **Explanation:** Checks if the dummy head/tail logic and eviction pointers hold up when the list effectively has only one real node.

### 5. The "Re-insertion" (Zombie Key)
**Input:** `Capacity: 2, put(1, 10), put(2, 20), put(3, 30), put(1, 100), get(1)`  
**Output:** `get(1) → 100`

* **put(1, 10), put(2, 20):** List: `[2, 1]`.
* **put(3, 30):** Evict `1`. List: `[3, 2]`. Map: `{3, 2}`.
* **put(1, 100):** `1` is not in map (it was evicted). Capacity full. Evict `2`. List: `[1, 3]`.
* **get(1):** Returns `100`.

> **Explanation:** Ensures that once a key is evicted, the system treats its re-appearance as a brand-new insertion, not an update to a previous record.