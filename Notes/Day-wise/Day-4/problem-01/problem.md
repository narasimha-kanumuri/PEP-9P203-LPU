# Concepts Involved: Tree, DFS, Recursion, Pruning, Height Computation

---

Title: Height with Early Cutoff

Problem Story / Context:
A binary tree's height is a fundamental structural property used across many tree algorithms. In some applications you only need to know whether the tree is shallow (≤ K) or to compute its exact height when it is small, and you can gain efficiency by stopping the traversal early when the height already exceeds a given threshold K. This problem formalizes that requirement: compute the tree height, but abort deeper exploration once you can determine the height exceeds K.


Inputs / Outputs / Constraints
- Input:
  - `root` — root node of a binary tree (node values are integers, but values are irrelevant to height).
  - `K` — non-negative integer cutoff threshold.
- Output:
  - An integer `H` which equals the tree height if `height ≤ K`, otherwise a value indicating the height exceeds `K` (see "Representation Notes" below).
- Constraints:
  - Number of nodes `N`: 0 ≤ N ≤ 10^6 (practical limits depend on environment).
  - Cutoff: 0 ≤ K ≤ 10^6.
  - Memory: recursion stack up to `O(H)` unless an explicit stack is used.

Representation Notes (input/output formats for testing):
- Tree may be provided as a level-order array with `null` markers for missing children, or via pointer-based `Node*` in code tests.
- For this problem set we expect testcases to accept either:
  - Exact height when `height ≤ K`, and
  - Any integer strictly greater than `K` when `height > K` (e.g., `K+1`) to indicate the cutoff was exceeded. (Test harness will treat any value > K as "exceeds cutoff".)


Edge-Case Thinking Prompts
- What should the function return for an empty tree (`root == null`)?
- If `K == 0`, how does that change early termination checks?
- How should skewed trees (all nodes one side) affect recursion depth and stack safety?
- How do you detect and handle extremely large `K` that practically never causes early exit?
- How should the solution signal "exceeded K" vs exact height in a stable, testable way?


Sample Inputs & Outputs (min 2)

1) Small balanced tree
- Input (level-order): `[1,2,3,4,5,6,7]`, `K = 3`
- Actual height = 3 → Output: `3`

2) Tall skewed tree
- Input (level-order): `[1,null,2,null,3,null,4]` (chain of 4 nodes), `K = 2`
- Actual height = 4 → Output: any value > `2` (e.g., `3`) indicating cutoff exceeded

3) Empty tree
- Input: `[]`, `K = 5`
- Actual height = 0 → Output: `0`

(Tests may use `K+1` to indicate "exceeded" for deterministic checking.)


Thinking Like a Programmer — Guided Questions
- What must be tracked?
  - Current subtree height during recursion; whether any branch already exceeded `K`.
- What can change and what must never change?
  - Node pointers change as we traverse (temporary), but the cutoff `K` is immutable input.
- What invariants ensure correctness?
  - Height(node) = max(height(left), height(right)) + 1 for non-null nodes; if either subtree reports > K, propagate "exceeded" upward without exploring remaining branches unnecessarily.
- What would brute force do?
  - Compute full heights of left and right recursively for every node, taking `O(N)` time and exploring entire tree.
- Where can we gain efficiency?
  - Stop exploring a subtree when its height is known to exceed `K`; do not visit its remaining nodes.


Required Deliverables for this file (per DSA_CONTRACT)
- This `problem.md` contains only the problem definition, inputs/outputs, edge cases, and programmer-thinking prompts.
- No algorithm steps, code snippets, complexity analysis, or solution hints are included here.

---

End of `problem.md` for "Height with Early Cutoff" (Day 4 — Problem 1)
