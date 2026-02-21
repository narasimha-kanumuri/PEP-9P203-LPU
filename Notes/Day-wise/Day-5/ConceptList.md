
# 📅 DAY 5 — TREES II

## 🌲 BST Invariant Mastery + Advanced Tree Patterns

- 🎯 **DAY 5 OBJECTIVE**
- Move from: “This looks like a BST.”
- To: “I can formally reason using range invariants.”
- **Focus Areas:**
  - Range-based correctness
  - Sorted-order exploitation
  - Structural validation
  - Tree construction from constraints
  - Space-optimized traversal

---

## 🧠 1. What Is a BST? (Zero Knowledge Entry)

- A **Binary Search Tree (BST)** is a binary tree where:
  - Left subtree values $<$ Node value
  - Right subtree values $>$ Node value

- **Correct version:** Every node must lie within a valid range defined by all its ancestors. This is called the **range propagation invariant**.

---

## 🧠 2. Local Check vs Global Validity

- ❌ **Wrong thinking:** Checking only `node.left < node < node.right`.
- **Example of Failure:**

```text
       10
      /  \
     5   15
         /
        6   ❌ (6 < 15 is true, but 6 < 10 is false)

```

- **Correct Rule:** Each node must satisfy $lower\_bound < node.val < upper\_bound$.
- 🔥 **Core Day 5 Invariant:**
- For every recursive call: `validate(node, low, high)`
- **Guarantee:** $low < node.val < high$

---

## 🧠 4. Inorder Traversal = Sorted Generator

- In a BST, **Inorder traversal** (Left → Node → Right) produces a **sorted sequence**.
- [Image showing the inorder traversal path of a BST resulting in a sorted array]
- **This enables:**
  - Kth smallest / largest
  - Two sum in BST
  - Recover swapped BST
  - **Validate BST** (monotonic check)
- **Insight:** You don’t need to store the full traversal; you can **stop early (pruning)**.

---

## 🧠 7. Dual Iterator Technique (Two-Sum)

- **Goal:** Find two values summing to $K$.
- Since BST is sorted via inorder, we simulate two pointers:
  1. **Smallest iterator** (Inorder)
  2. **Largest iterator** (Reverse Inorder)
- **Invariant:** Left pointer always $\le$ Right pointer.
- **Complexity:** Time: $O(N)$, Space: $O(H)$. **No HashMap required.**

---

## 🧠 8. Structural Return Pattern (Postorder)

- **Used in:** Largest BST subtree, Maximum Sum BST.
- Each recursive call returns a structure:

```cpp {lineNumbers:true}
struct BSTInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sizeOrSum;
};

```

# 🌲 BST INVARIANT MASTERY

- The parent decides validity based on children’s info (**Structural aggregation**).

---

## 🧠 10. Serialize / Deserialize BST

- Unlike general trees, a BST can be rebuilt using **only** Preorder traversal + range bounds.
- **BST property** uniquely constrains placement.
- **Algorithm:**
  1. Read preorder array.
  2. Insert using `build(lower, upper)`.
  3. Consume only values within the valid range.

---

## 🧠 12. Range Pruning (Massive Optimization)

- **Example: Range Sum [L, R]**
  - If `node.val < L`: Skip left subtree entirely.
  - If `node.val > R`: Skip right subtree entirely.
- BST property eliminates **half the search space** at each relevant node.

---

## 🧠 13. Morris Traversal (O(1) Space)

- **Idea:** Temporarily modify the tree to create "threads" (pointers from predecessor to current).
- Traverse **without stack or recursion**.
- **Key invariant:** Restore tree structure (remove threads) before moving on.

---

## 📊 Complexity Intuition (BST)

| Operation | Balanced BST | Skewed BST |
| :--- | :--- | :--- |
| Search / Insert / Delete | $O(\log N)$ | $O(N)$ |
| Traversal (Time) | $O(N)$ | $O(N)$ |
| Space (Recursion Stack) | $O(H) = O(\log N)$ | $O(H) = O(N)$ |

---

## 🏁 Mental Upgrade After Day 5

- **BST is not a parent-child rule;** it is range constraint propagation.
- **Inorder is not a traversal;** it is a sorted generator.
- **Postorder is a structural information merger.**
- **Bounds define correctness;** Pruning reduces search space.
