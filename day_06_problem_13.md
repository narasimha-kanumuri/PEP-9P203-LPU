# L4-Q2: Reorder a Singly Linked List Using a Queue

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given the head of a **singly linked list**, reorder the list in the following pattern:

```
L0 → L1 → L2 → ... → Ln-1 → Ln
```

Reorder it to:
```
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
```

You must perform the reordering **using a queue** and **pointer rewiring only**.

Return the head of the reordered list.

---

### Constraints (Strict)

- The list is **singly linked**
- **Queue is allowed**
- **No recursion**
- **No arrays / vectors**
- **No creation of new list nodes**
- **Node values must not be modified**
- **Only pointer rewiring is allowed**
- Time complexity: **O(N)**
- Space complexity: **O(N)** (queue)
- The algorithm must work for:
  - even length lists
  - odd length lists
- Pointer safety and termination correctness are mandatory

---

### Examples

#### Example 1 (Even Length)
```
Input:
1 → 2 → 3 → 4 → 5 → 6

Output:
1 → 6 → 2 → 5 → 3 → 4
```

---

#### Example 2 (Odd Length)
```
Input:
1 → 2 → 3 → 4 → 5

Output:
1 → 5 → 2 → 4 → 3
```

---

#### Example 3 (Minimal Case)
```
Input:
1 → 2

Output:
1 → 2
```

---

### ELI5 (Explain Like I’m 5)

Think of people standing in a line.

- First person stays where they are
- Last person comes next
- Then second person
- Then second-last person
- And so on…

We:
- First **remember all people in order** using a queue
- Then **rebuild the line** by taking from the **front and back alternately**

But since we only have a queue:
- We must be **very careful** how we extract and reconnect people

---

### Why This Is a Level 4 Problem

At first glance, this looks like a simple rearrangement.

But constraints make it hard:
- Singly linked list → no backward traversal
- Queue → FIFO only
- No arrays → no index access
- Pointer rewiring only → no node recreation

This tests **controlled consumption of a queue** while maintaining **list termination invariants**.

---

### Core Insight

We break the problem into **two logical phases**:

1. **Linearization phase**  
   Store node *addresses* (not values) into a queue.

2. **Controlled reconstruction phase**  
   Rewire `next` pointers by alternately pulling:
   - front node
   - back node (simulated via rotation)

---

### High-Level Strategy

#### Phase 1: Push All Nodes into Queue

Traverse the list once:
- Push each `Node*` into the queue
- Do **not** change pointers yet

At the end:
- Queue contains nodes in original order

---

#### Phase 2: Rebuild List Using Queue

We rebuild the list by:
- Alternately selecting:
  - front element
  - last element

But queues are FIFO.

To simulate “take from back”:
- Rotate the queue:
  - Move first `(size - 1)` elements to the back
  - Then pop the last one

This keeps us compliant with **queue-only access**.

---

### Deep Implementation Narrative (English → Code Mapping)

---

#### Step 1: Queue Construction

```
curr = head
while curr:
    queue.push(curr)
    curr = curr->next
```

**Invariant**
- Queue holds exact node addresses in original order
- No pointers modified yet

---

#### Step 2: Initialize Reconstruction

- Create `newHead` using the first element in queue
- Maintain a `tail` pointer for stitching

---

#### Step 3: Alternating Reordering Loop

While queue is not empty:

1. **Take from front**
   - `frontNode = queue.front()`
   - pop it
   - attach it after `tail`

2. **Take from back (if exists)**
   - Rotate queue `size-1` times
   - pop last node
   - attach it after `tail`

After each attachment:
- Update `tail`
- Explicitly set `tail->next = nullptr` to avoid cycles

---

#### Step 4: Termination Handling

- Stop when queue becomes empty
- Ensure final node’s `next` is `nullptr`

---

### Invariants Maintained

- No node is duplicated
- No node is lost
- Every `next` pointer is written **exactly once**
- No cycles introduced
- List always remains properly terminated

---

### Complexity Analysis

- Time:
  - Queue fill: `O(N)`
  - Reconstruction:
    - Worst-case rotation cost → `O(N^2)`
- Space:
  - Queue stores `N` node pointers → `O(N)`

**Note:**  
This inefficiency is intentional — this is a **reasoning test**, not an optimization test.

---

### Common Wrong Approaches (Disallowed)

- Using deque instead of queue
- Using array/vector
- Creating new nodes
- Modifying node values
- Breaking list termination (`next` not set to nullptr)

---

### What Will Be Done in Part 2

- Full C++ implementation using:
  - `queue<Node*>`
- Separate test file
- **10 test cases**, including:
  - odd/even length lists
  - minimal lists
  - larger lists
  - termination and cycle checks

---
