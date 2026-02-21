
# 📅 DAY 5 — TREES II

## 🌲 BST Invariant Mastery + Advanced Tree Patterns

> Core Invariant:
> [
> Left < Node < Right
> ]
> But interpreted as **range-based reasoning**, not local comparison only.

---

# 🔥 IN-CLASS SET (7 Medium + 3 Hard)

---

## 🟡 MEDIUM (7)

---

### 1️⃣ Validate BST with Duplicate-on-Right Rule

Validate BST,
but duplicates are allowed only in the right subtree.
*(Twist: modified range invariant)*

---

### 2️⃣ Kth Smallest Without Inorder Storage

Return kth smallest element,
but you cannot store full inorder traversal.
*(Twist: early stopping DFS)*

---

### 3️⃣ Lowest Common Ancestor with Missing Node Case

Find LCA of two nodes,
but return null if either node is absent.
*(Twist: presence validation integrated)*

---

### 4️⃣ BST Insert with Height Constraint

Insert value into BST,
but reject insertion if tree height would exceed H.
*(Twist: structural constraint enforcement)*

---

### 5️⃣ Convert BST to Greater Sum Tree

Each node becomes sum of all greater nodes,
but original tree structure must remain unchanged.
*(Reverse inorder + accumulation invariant)*

---

### 6️⃣ Validate BST Using Iterative Approach Only

Validate BST,
but recursion is not allowed.
*(Stack simulation twist)*

---

### 7️⃣ Two Sum in BST Without Extra HashMap

Return true if two nodes sum to K,
but do not use extra memory like hash sets.
*(Dual iterator traversal twist)*

---

## 🔴 HARD (3)

---

### 8️⃣ Recover Swapped BST

Two nodes are swapped by mistake.
Restore BST without changing structure.
*(Inorder anomaly detection + constant space allowed)*

---

### 9️⃣ Serialize & Deserialize BST with Compact Encoding

Design serializer/deserializer,
but output string must not contain null markers.
*(BST property leveraged — triple pattern: DFS + bounds + parsing)*

---

### 🔟 Largest BST Subtree

Given binary tree (not guaranteed BST),
return size of largest subtree that is a valid BST.
*(Postorder + range tracking + structural validation)*

---

# 🏠DAY 5 -  HOMEWORK SET (7 Medium + 3 Hard)

---

## 🟡 MEDIUM

---

### 1️⃣ Floor and Ceil in BST

Return floor and ceil for given key,
but must do it in single traversal.
*(Range narrowing twist)*

---

### 2️⃣ BST Deletion with Height Rebalancing Check

Delete a node,
but return whether height difference exceeded 1 anywhere.
*(Deletion + balance detection combo)*

---

### 3️⃣ Kth Largest Using Morris Traversal

Return kth largest element,
but recursion and stack are not allowed.
*(Threaded traversal twist — O(1) space)*

---

### 4️⃣ Range Sum in BST with Pruning

Return sum of nodes in range [L, R],
but prune subtrees aggressively.
*(Range invariant exploitation)*

---

### 5️⃣ Count Pairs from Two BSTs Equal to K

Given two BSTs,
count pairs (one from each) summing to K.
*(Dual traversal + sorted merge logic)*

---

### 6️⃣ Construct BST from Preorder Only

Given preorder traversal,
reconstruct BST in O(N).
*(Range bounding during construction)*

---

### 7️⃣ Check If Two BSTs Are Identical Without Full Traversal Storage

Return true if identical,
but you may not store full traversals.
*(Synchronized DFS twist)*

---

## 🔴 HARD

---

### 8️⃣ Maximum Sum BST in Binary Tree

Return maximum sum of any subtree that is a valid BST.
*(Postorder + validity flag + range + sum — triple pattern)*

---

### 9️⃣ Inorder Successor Without Parent Pointer

Find inorder successor of node,
but tree does not provide parent pointer.
*(Iterative search + candidate tracking twist)*

---

### 🔟 Merge Two BSTs into Balanced BST

Merge two BSTs,
but final tree must be height-balanced.
*(Inorder merge + rebuild balanced tree)*

---

# 📊 Pattern Coverage Matrix

| Pattern                       | Problems       |
| ----------------------------- | -------------- |
| Range Passing Invariant       | 1, 4, HW4, HW6 |
| Inorder Exploitation          | 2, 5, 8, HW3   |
| Reverse Inorder               | 5              |
| Iterative Stack Simulation    | 6              |
| Dual Pointer Technique on BST | 7, HW5         |
| Postorder Structural Return   | 10, HW8        |
| Triple Pattern                | 9, HW8         |
| Construction via Bounds       | HW6            |

---

# 🧠 Skill Upgrade After Day 5

Students must now:

* Think in **ranges**, not just parent-child comparison
* Use inorder traversal as sorted generator
* Merge two BST iterators
* Detect structural violations
* Combine tree + recursion + greedy decisions
* Construct trees from traversal constraints
* Distinguish local BST check vs global validity 
