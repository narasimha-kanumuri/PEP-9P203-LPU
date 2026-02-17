# 📅 Day 1: Hashing & Lookup Logic

> **Focus:** Moving from Nested Loops $O(N^2)$ to Hash Maps $O(N)$.  
> **Key Concepts:** Frequency Maps, Complements, Invariants, Space-Time Tradeoff.

---

## 👨‍🏫 Class Session (Instructor Led)

*These problems introduce the "Big 4" Hashing Patterns: Complements, Canonical Keys, HashSets, and Prefix Sums.*

### 1. The Bio-Lab Centrifuge

**Logic:** Two Sum

* **The Scenario:** A centrifuge machine requires perfect balance. You have a target weight `W` and a rack of test tubes with various weights. Find the indices of exactly two tubes that sum up to `W`.
* **Constraint:** You cannot check every pair $O(N^2)$ is too slow. You must solve this in one pass.
* **Core Concept:** The **Complement** $(Target - Current)$ and Hash Map lookups.

### 2. The Warehouse Inventory Scramble

**Logic:** Group Anagrams

* **The Scenario:** A label printer malfunctioned. Product IDs like "partA" might print as "trapA" or "Atrap". Group them so all scrambled versions of the same product ID are stored in the same list.
* **Constraint:** Grouping must happen without comparing every string to every other string.
* **Core Concept:** **Canonical Representation** (Sorting a string or frequency counting to use as a Map Key).

### 3. The Streaming Packet Stitcher

**Logic:** Longest Consecutive Sequence

* **The Scenario:** Data packets arrive out of order (e.g., 100, 4, 200, 1, 3, 2). Determine the length of the longest contiguous block (e.g., 1, 2, 3, 4 is length 4).
* **Constraint:** You cannot sort the packet list $O(N \log N)$ is too slow. It must be $O(N)$.
* **Core Concept:** Using a **HashSet** for $O(1)$ existence checks to find the "start" of a sequence.

### 4. The Power Surge Windows

**Logic:** Subarray Sum Equals K

* **The Scenario:** A log of energy usage per minute (integers, can be negative). Calculate the total number of continuous time windows where the total energy consumed is exactly `K`.
* **Constraint:** Finding all subarrays is $O(N^2)$. We need $O(N)$.
* **Core Concept:** **Prefix Sums + Hash Map**. Storing `(CurrentSum - K)` history.

---

## 💻 In-Class Practice Lab (Student Hands-On)

*Quick-fire exercises to build muscle memory with HashSets and Maps.*

| Task | Logic Pattern | Focus Area |
| :--- | :--- | :--- |
| **1. Duplicate Sensor** | Contains Duplicate | Basic `HashSet.add()` and exit conditions. |
| **2. Shared User Session** | Intersection of Arrays | Converting Array A to a Set; filtering Array B. |
| **3. Password Permutation** | Valid Anagram | Frequency Counters (Array of 26 or HashMap). |
| **4. Election Consensus** | Majority Element | Frequency Map counting or Moore’s Voting. |

---

## 🏠 Homework Assignment

*Apply class concepts to different constraints and logic puzzles.*

### 1. The Glitched Telemetry

* **Logic:** First Unique Character
* **Problem:** Find the index of the first character in a string that appears exactly once.
* **Hint:** Use a **Frequency Map** in two passes. Pass 1: Count. Pass 2: Check counts.

### 2. The Alien Cipher Validator

* **Logic:** Isomorphic Strings
* **Problem:** Verify if an encrypted message uses a consistent 1-to-1 symbol substitution.
* **Hint:** You need **two Maps** (Map A→B and Map B→A) to ensure a complete bijection.

### 3. The Ransom Letter Construction

* **Logic:** Ransom Note
* **Problem:** Can `string note` be built using letters from `string magazine`? (No reusing letters).
* **Hint:** **Frequency Map subtraction**. Ensure `count(magazine) ≥ count(note)` for every char.

### 4. The Loop Detection System

* **Logic:** Happy Number
* **Problem:** Determine if a number is "happy" (replaces digits with sum of squares until it hits 1 or loops).
* **Hint:** Use a **HashSet** to store numbers seen in the chain. If you see a number again, you've hit a loop.

---

*End of Day 1 Curriculum*
