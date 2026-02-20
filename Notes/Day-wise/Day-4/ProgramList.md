# 📅 DAY 4 — TREES I
- 🌳 Traversal + Structural Computation + Hash Integration

---

## 🔥 IN-CLASS SET (7 Medium + 3 Hard)

### 🟡 MEDIUM (7)

- 1️⃣ **Height with Early Cutoff**
- Return height of tree,
- but stop recursion immediately if height exceeds K.
- (Twist: pruning condition inside DFS)

- 2️⃣ **Level Order with Zig-Zag Constraint**
- Return level order traversal,
- but alternate direction every level (L→R then R→L).
- (BFS + direction control logic)


- 3️⃣ **Count Good Nodes (Path Constraint)**
- A node is “good” if its value is ≥ all values from root to that node.
- Return total count.
- (DFS + path-based invariant)

- 4️⃣ **Diameter with Node Value Constraint**
- Find diameter considering only nodes whose value ≥ X.
- (Diameter logic + filtering twist)

- 5️⃣ **Left View of Tree Without BFS**
- Return leftmost node at each level
- but you are NOT allowed to use queue.
- (DFS depth tracking twist)


- 6️⃣ **Vertical Order Without Sorting Keys**
- Return vertical traversal
- but do not sort horizontal distances afterward.
- (HashMap + min/max tracking twist)

- 7️⃣ **Sum of Nodes at Alternate Levels**
- Return sum of nodes at even depth minus sum at odd depth.
- (DFS + depth parity tracking)

---

### 🔴 HARD (3)

- 8️⃣ **Longest Univalue Path**
- Return length of longest path where all nodes have same value.
- Path may or may not pass through root.
- (DFS return logic + diameter-style merge)

- 9️⃣ **Tree Burning Time**
- Given target node,
- each second fire spreads to parent and children.
- Return total time to burn entire tree.
- (DFS + parent mapping + BFS combination — triple pattern)


- 🔟 **Maximum Path Sum (Not Root-Based)**
- Return maximum path sum in tree.
- Path can start and end anywhere.
- (Postorder DFS + global tracking + negative handling)

---

## 🏠 HOMEWORK SET (7 Medium + 3 Hard)

### 🟡 MEDIUM

- 1️⃣ **Invert Tree with Depth Limit**
- Invert tree only up to depth D.
- (DFS + depth guard)

- 2️⃣ **Check Symmetry Without Mirroring**
- Determine if tree is symmetric
- but without creating mirror copy.
- (Dual DFS comparison logic)

- 3️⃣ **Bottom View of Binary Tree**
- Return bottom-most node at each horizontal distance.
- (BFS + HashMap overwrite logic)

- 4️⃣ **Count Nodes with Exactly One Child**
- Return count of nodes
- having exactly one non-null child.
- (Simple DFS + structural check)

- 5️⃣ **Replace Node with Subtree Sum**
- Modify tree so each node stores sum of its subtree.
- (Postorder DFS modification twist)

- 6️⃣ **Kth Node in Level Order**
- Return Kth node in BFS traversal
- without storing full traversal array.
- (Queue + incremental counter)

- 7️⃣ **Check If Tree Is Height-Balanced**
- Return true if balanced
- but compute height only once per node.
- (Optimized DFS returning pair/struct)

---

### 🔴 HARD

- 8️⃣ **Nodes at Distance K from Target**
- Return all nodes at distance K from given node.
- Tree is not necessarily BST.
- (DFS + parent mapping + BFS/DFS hybrid)

- 9️⃣ **Maximum Width of Binary Tree**
- Width defined using conceptual complete binary tree indexing.
- Return maximum width.
- (Level order + index simulation)

- 🔟 **Serialize and Deserialize (Basic Version)**
- Design serialize and deserialize functions
- for general binary tree (not BST).
- (DFS + string encoding + null markers — hash-integration ready)

---

## 📊 Pattern Combination Summary

| Pattern | Problems |
| :--- | :--- |
| DFS structural return | 1, 3, 7, 8, 10 |
| BFS level processing | 2, 6, HW6, HW9 |
| DFS + Depth tracking | 1, 5 |
| DFS + Global variable merge | 8, 10 |
| DFS + HashMap | 6, HW3 |
| DFS + BFS hybrid | 9, HW8 |
| Triple pattern | 9 (DFS + BFS + mapping) |

---

## 🧠 Skill Upgrade After Day 4

- Student must be able to:
- Recognize subtree-return pattern
- Compute height safely
- Distinguish path-based vs subtree-based problems
- Merge left/right results correctly
- Handle global variable updates properly
- Combine DFS + BFS when required
- Understand recursion stack cost $$O(H)$$