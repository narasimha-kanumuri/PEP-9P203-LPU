# 📅 Day 2: Binary Search & The Recursion Leap

> **Focus:** Search Space Reduction $O(\log N)$ and trusting The Call Stack.  
> **Key Concepts:** Divide & Conquer, Loop Invariants, Base Cases, Stack Overflow.

---

## 👨‍🏫 Class Session (Instructor Led)

*These problems demonstrate how to discard half of the search space at every step.*

### 1. The Version Control Bisect

**Logic:** Binary Search on Answer

* **The Scenario:** You are a lead engineer. The latest build (version $n$) has a critical bug. Version 1 was fine. You have an API `isBadVersion(version)` that returns true/false. Find the **first** version where the bug was introduced.
* **Constraint:** Calls to `isBadVersion` are expensive. Minimize them.
* **Core Concept:** If `mid` is bad, the first bad version is to the left (including `mid`). If `mid` is good, the answer is strictly to the right.

[Image of binary search algorithm flowchart]

### 2. The Shifted Server Log

**Logic:** Search in Rotated Sorted Array

* **The Scenario:** A server log stores timestamps in sorted order, but a restart caused a rotation (e.g., `[4, 5, 6, 7, 0, 1, 2]`). Find the index of a specific `target` timestamp.
* **Constraint:** You must do this in $O(\log N)$. No linear scanning.
* **Core Concept:** **Partial Sorting**. In a rotated array, at least one half (left or right of `mid`) is always sorted. Use the sorted half to determine your next move.

### 3. The Signal Plateau

**Logic:** Find First and Last Position of Element

* **The Scenario:** A sensor sends a sorted stream. A stable signal (e.g., `8`) appears multiple times consecutively: `[5, 7, 7, 8, 8, 8, 10]`. Find the start and end indices of this "plateau."
* **Constraint:** Must be $O(\log N)$.
* **Core Concept:** **Dual Binary Search**. Run BS once to find the leftmost boundary, and a modified BS again for the rightmost boundary.

### 4. The Viral Replication

**Logic:** $Pow(x, n)$ / Modular Exponentiation

* **The Scenario:** A virus replicates by a factor of $x$ every hour. Calculate the population $x^n$ where $n$ can be up to 2 billion.
* **Constraint:** A simple loop $O(N)$ will time out. You need $O(\log N)$.
* **Core Concept:** **Recursive Divide & Conquer**. $x^{10} = x^5 \times x^5$. Calculate the sub-problem once and reuse it to reach the result exponentially faster.

---

## 💻 In-Class Practice Lab (Student Hands-On)

*Exercises to build muscle memory with pointers and recursive base cases.*

| Task | Logic Pattern | Focus Area |
| :--- | :--- | :--- |
| **1. Square Field Fencing** | `Sqrt(x)` | BS range `[0, x]`. If $mid^2 > x$, search lower. |
| **2. The Mountain Hiker** | Find Peak Element | Greedy BS: If `nums[i] < nums[i+1]`, peak is right. |
| **3. Nested Doll Capacity** | Recursive Sum | Base Case (`n=0`) vs. Recursive Step (`n + f(n-1)`). |
| **4. Perfect Formation** | Valid Perfect Square | Exact match BS logic without using `sqrt()` libraries. |

---

## 🏠 Homework Assignment

*Applying search optimization and recursion to data structures and real-world limits.*

### 1. The Smallest Batch ID

* **Logic:** Find Minimum in Rotated Sorted Array
* **Problem:** Find the "pivot point" (the minimum element) in a rotated sorted array.
* **Hint:** Compare `mid` against `right`. If `nums[mid] > nums[right]`, the minimum is definitely in the right half.

### 2. The Cloud Upload Speed

* **Logic:** Koko Eating Bananas (BS on Answer Space)
* **Problem:** You have $N$ files and $H$ hours. Find the **minimum** speed $K$ (MB/sec) to finish all files on time.
* **Hint:** The possible speeds range from $1$ to $Max(File Size)$. Test a speed `mid`; if it works, try to go slower; if not, go faster.

### 3. The Robot Jump Logic

* **Logic:** Climbing Stairs (Recursion)
* **Problem:** A robot can jump 1 or 2 steps. How many ways can it reach step $n$?
* **Hint:** This is the Fibonacci sequence. Solve recursively first, then notice the overlapping sub-problems.

### 4. The Sorted Seat Locator

* **Logic:** Search a 2D Matrix
* **Problem:** An $m \times n$ matrix is sorted such that the first int of a row is greater than the last int of the previous row. Find a target.
* **Hint:** Treat the 2D matrix as a flattened 1D array of size $m \times n$. Map index to coordinates: `row = index / n`, `col = index % n`.

---
*End of Day 2 Curriculum*
