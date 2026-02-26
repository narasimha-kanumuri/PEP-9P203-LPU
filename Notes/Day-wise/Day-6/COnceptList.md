Below is your **DAY 6 – Complete Concept Material**
Aligned with:

* Day 6 topic from curriculum table (Heaps + Disjoint Sets) 
* 9-Day structure (Heaps + Priority + Top-K + Integration) 
* Master Engine invariant philosophy 

---

# 📅 DAY 6 — Heaps + Priority Queues + Disjoint Sets

# ⚡ Controlled Ordering & Fast Connectivity

---

# 🎯 Day 6 Objective

Understand how to:

* Always access the **smallest or largest element quickly**
* Maintain partial order efficiently
* Manage dynamic connectivity between elements
* Understand amortized complexity

Today is about **controlled structure** — not full sorting.

---

# PART 1 — HEAPS

---

# 🧠 1. What Is a Heap? (Zero Knowledge Entry)

A heap is a special tree structure where:

### Min-Heap:

Parent ≤ Children

### Max-Heap:

Parent ≥ Children

Important:
Heap is **NOT fully sorted**.

Only guarantee:
Top element is smallest (or largest).

---

# 🧠 2. Heap Structural Properties

A heap is:

* A **complete binary tree**
* Filled left to right
* No gaps except possibly last level

Because of this:

We can store heap in an array.

---

# 🧠 3. Array Representation

If index = i

Left child:

```
2i + 1
```

Right child:

```
2i + 2
```

Parent:

```
(i - 1) / 2
```

No pointers needed.

---

# 🧠 4. Heap Invariant (Most Important)

For every node:

Min-Heap:

```
parent ≤ left_child
parent ≤ right_child
```

This must ALWAYS hold.

If violated → structure invalid.

---

# 🧠 5. Insert Operation (Push)

Steps:

1. Add element at end.
2. Bubble up (Swim).
3. Swap until heap invariant restored.

Why bubble up?

Because new element might violate parent relation.

Time:
O(log N)

Because height of heap = log N.

---

# 🧠 6. Remove Top (Pop)

Steps:

1. Swap root with last element.
2. Remove last.
3. Bubble down (Sink).
4. Restore heap invariant.

Time:
O(log N)

---

# 🧠 7. Heapify (Build Heap Efficiently)

Given unsorted array:

You can build heap in:

O(N)

Not O(N log N).

Why?

Because lower levels require less work.

Key insight:

Half nodes are leaves.
They need no fixing.

---

# 🧠 8. Why Use Heap Instead of Sorting?

If you need:

* Only smallest K elements
* Repeated minimum access
* Streaming data

Heap gives:

O(log N) per update

Sorting every time would be expensive.

---

# 🧠 9. Top-K Problems

Example:

Find K largest numbers.

Strategy:

Maintain min-heap of size K.

If new element > heap.top:
Replace.

Time:
O(N log K)

Better than sorting O(N log N) when K small.

---

# 🧠 10. Kth Largest Element

Use:

Min-heap of size K.

At end:
Top = Kth largest.

---

# 🧠 11. Merge K Sorted Lists

Approach:

Push first element of each list into heap.

Pop smallest.
Push next from same list.

Heap size = K.

Time:
O(N log K)

---

# 🧠 12. Median from Data Stream

Maintain:

* Max heap (left half)
* Min heap (right half)

Balance sizes.

Median:

* If equal → average
* If unequal → top of larger heap

Invariant:

All elements in left ≤ all in right.

---

# 🧠 13. Priority Queue

A priority queue is:

Heap + Interface.

It allows:

* push
* pop
* top

But you don't manage array manually.

---

# 🧠 14. Heap vs BST

Heap:

* Fast min/max
* Not sorted order traversal

BST:

* Sorted order
* Slower insert/search if unbalanced

Heap is for priority.
BST is for ordered queries.

---

# PART 2 — DISJOINT SET (UNION-FIND)

---

# 🧠 15. What Is Disjoint Set?

Data structure that manages:

* Groups of connected elements
* Fast union
* Fast connectivity check

Used in:

* Graph connectivity
* Kruskal’s algorithm
* Network components

---

# 🧠 16. Core Operations

1. find(x)
   → Find representative of set

2. union(x, y)
   → Merge two sets

---

# 🧠 17. Parent Array Model

Each element points to parent.

Initially:

Each node is its own parent.

---

# 🧠 18. Find Operation

Climb parents until:

parent[x] == x

That node is root.

---

# 🧠 19. Path Compression

After finding root:

Make every visited node directly point to root.

This flattens tree.

Future finds become faster.

---

# 🧠 20. Union by Rank / Size

Always attach smaller tree under larger tree.

Prevents tall trees.

---

# 🧠 21. Amortized Complexity

With:

* Path compression
* Union by rank

Time per operation:

Almost constant.

Technically:

O(α(N))

Where α is inverse Ackermann function.

Extremely slow-growing.
Practically ≤ 5.

---

# 🧠 22. Kruskal’s Algorithm (Integration)

To find Minimum Spanning Tree:

1. Sort edges by weight.
2. Pick smallest edge.
3. If endpoints not connected → union them.

Disjoint set prevents cycles.

---

# 🧠 23. Heap + Graph Integration

Used in:

* Dijkstra
* Prim’s algorithm

Heap manages frontier.
Graph defines structure.

---

# ⚠️ Common Beginner Mistakes

❌ Thinking heap is fully sorted
❌ Forgetting to restore invariant
❌ Using sorting when heap sufficient
❌ Not balancing heaps in median problem
❌ Forgetting path compression
❌ Forgetting union by rank
❌ Misunderstanding amortized complexity

---

# 📊 Complexity Summary

Heap:

Insert: O(log N)
Delete: O(log N)
Build Heap: O(N)

Top-K: O(N log K)

Union-Find:

Find: O(α(N))
Union: O(α(N))

---

# 🧠 Mental Shift After Day 6

Students must now understand:

* Not all ordering needs sorting.
* Partial order is powerful.
* Heap gives controlled priority access.
* Union-Find gives near constant-time connectivity.
* Amortized complexity matters.
* Combining structures gives optimization.

---

# 🚀 After Mastering Day 6

They can solve:

* Kth largest
* Top K frequent
* Merge K lists
* Median stream
* Network connectivity
* Kruskal MST
* Graph cycle detection
* Island merging
* Real-time scheduling

---
