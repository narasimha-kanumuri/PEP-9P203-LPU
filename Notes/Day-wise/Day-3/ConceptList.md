# 📅 DAY 3 — Sorting as a TOOL + Greedy + Structural DS Thinking

- **Day Goal:** Not “learn sorting.” Understand partition invariants, merge invariants, why greedy works, and revise Stack/Linked List/Queue weaponization.

---

## 🧠 1. Partition Invariant (QuickSort Brain)

- **ELI5:** Imagine you pick one number (pivot). You want: Left (<), Middle (==), Right (>).
- **Core Partition Invariant:** At any moment:
  - `[ < pivot | == pivot | unknown | > pivot ]`
  - The unknown region shrinks every step. If this breaks, the sort breaks.



- **Twist:** This isn't "swapping randomly"; it is maintaining a structural promise.
- **Used in:** Dutch National Flag, 3-way QuickSort, Stable Partition.

---

## 🧠 2. Merge Invariant (Merge Sort Brain)

- **ELI5:** When merging two sorted lists like `[1 4 7]` and `[2 3 8]`, the merged prefix must be sorted at every single step.
- **Merge Invariant:** - Left and right pointers only move forward.
  - Output remains sorted at all times.
- **Power:** Guarantees stability, counts inversions, and handles Linked Lists efficiently.

---

## 🧠 3. Stability (Deep Concept)

- **ELI5:** If two values are equal, do they stay in their same relative order?
- **Stability Matters:** In stable partition problems or inversion counting with conditions, you cannot freely swap. That changes your entire strategy.

---

## 🧠 4. Greedy Thinking

- **ELI5:** Make the best choice **NOW** hoping it leads to the global best.
- **Correctness Condition:** Greedy works if:
  1. Problem has optimal substructure.
  2. Local best choice never blocks the global optimum.
- **Failure Case:** If a choice now blocks a better arrangement later, you need **DP**, not Greedy.



---

## 🧠 5. Comparator Logic (Custom Sorting)

- Sorting is not just for numbers. Sometimes you sort by:
  - Frequency, Pair rules, or Combined string values.
- **Example:** To form the largest number, compare `a + b` vs `b + a`. The comparator **is** the algorithm.

---

## 🧠 6. Linked List Sorting Logic

- **Arrays:** Random access, easy swapping.
- **Linked Lists:** No index, must redirect pointers.
- **Inference:** Merge Sort is natural for Linked Lists; QuickSort is painful.

---

## 🧠 7. Stack & Queue Structural Invariants

- **Stack Invariant:** The top of the stack must represent the most recent unresolved element (e.g., the last opened bracket).
- **Queue Invariant:** First in, first out. Used in reconstruction and circular scheduling.

---

## 🧠 8. K-Sorted & Inversion Counting

- **K-Sorted Insight:** If every element is at most $K$ away, use a **Min-Heap of size K**. The correct element must appear within that window.
- **Inversion Counting:** During Merge Sort, if a right element is chosen before a left element, all remaining left elements are inversions.



---

## ⚡ Complexity Intuition

| Algorithm | Time | Why |
| :--- | :--- | :--- |
| QuickSort (avg) | $O(N \log N)$ | Divide in half each time |
| QuickSort (worst) | $O(N^2)$ | Bad pivot selection |
| Merge Sort | $O(N \log N)$ | Two halves + linear merge |
| Partition | $O(N)$ | Single pass |
| Heap (size K) | $O(N \log K)$ | Local ordering only |

---

## 🎯 DAY 3 INVARIANTS TO DRILL

- Partition invariant must never break.
- Merge prefix must remain sorted.
- Stability must be preserved if required.
- Greedy must be locally safe and globally optimal.
- Stack top = most recent unresolved constraint.
- Heap top = smallest/largest frontier element.

---

## 🧠 Mental Model Summary

Sorting problems are about:
- Maintaining structure while scanning.
- Proving greedy correctness.
- Choosing the correct invariant.
- Deciding stability requirements.

**Would you like me to walk through the proof of why the "Largest Number" string comparator ($a+b > b+a$) works?**