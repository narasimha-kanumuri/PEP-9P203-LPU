# 📅 DAY 2 — Binary Search + Recursion

- Search Space Reduction Mindset

## 🧠 1. What is Binary Search? (ELI5)

---

- Imagine you’re guessing a number between 1 and 100.
- Instead of checking 1, 2, 3, 4…
- You jump to 50.

- Too big? Search left.
- Too small? Search right.
- Each time you cut the search space in half.
- That’s binary search.

## 🔥 Core Idea

---

- If something is sorted or monotonic,
- we can eliminate half the search space each step.

## 🧩 Required Concepts

---

### 1️⃣ Sorted Boundary Guarantee

- Binary search only works if the data has order.
- Example:

> ```text
> [1, 3, 5, 8, 12, 20]
> ```

- If sorted:

- Everything left of mid is smaller.
- Everything right of mid is larger.
- That guarantee is your weapon.

### 2️⃣ Monotonic Function

- Monotonic means:
- It changes in only one direction.
- Example:

> ```text
> false false false true true true
> ```

- Once true appears, it never goes back to false.
- This allows us to find the first true using binary search.
- Used in:

- Minimum speed problems
- Minimum days problems
- Threshold-based problems

### 3️⃣ Binary Search on Answer Space

- Sometimes we don’t search inside an array.
- We search over possible answers.
- Example:
- “What is minimum speed to finish work in H hours?”
- Speed is unknown.
- Try middle speed.
- Check if valid.
- Adjust left or right.
- You are searching the answer, not the array.

### 4️⃣ Mid Calculation

- Always compute safely:

```cpp {lineNumbers:true}
mid = left + (right - left) / 2
```

- Why?
- To prevent overflow when $left + right$ is very large.

---

## 5️⃣ When Binary Search Fails

- It fails when:
- Data not sorted
- Condition not monotonic
- Search space not shrinking
- If left and right don’t move → infinite loop.

---

## ⏱ Time Complexity Intuition

- Each step halves the problem.
- If $N = 1,000,000$
- Steps:
- 1,000,000
- 500,000
- 250,000
- 125,000
- ...
- Only about 20 steps.
- That is:
- $O(\log N)$
- Log means:
- “How many times can I divide by 2?”

---

## 🧠 2. What is Recursion? (ELI5)

- Recursion is when a function calls itself.
- Like:
- To climb 5 stairs,
- climb 4 stairs first,
- then take 1 more step.

---

## 🔥 Core Idea

- Solve a smaller version of the same problem.

---

## 🧩 Required Concepts

### 1️⃣ Base Case (MOST IMPORTANT)

- The stop condition.
- Without it → infinite recursion → crash.
- Example:
- C++

```cpp {lineNumbers:true}
if (n == 0) return 1;
```

## 2️⃣ Recursive Case

- Break problem into smaller piece.
- Example:

```cpp {lineNumbers:true}
power(x, n) = x * power(x, n-1)
```

- Each call reduces n.

---

## 3️⃣ Strict Shrinkage Rule

- The problem size MUST reduce every time.
- If size stays same → infinite recursion.

---

## 4️⃣ Call Stack

- Each recursive call waits for the next one to finish.
- They stack like plates:



#### Sample Input

> ```text
> power(2,3)
>   power(2,2)
>     power(2,1)
>       power(2,0)
> ```

- Then they resolve backwards.
- Memory is used for each call.
- That memory is called:
- Recursion Stack Space.

---

## 5️⃣ Divide & Conquer Recursion

- Instead of shrinking by 1,
- shrink by half.
- Example:



```cpp {lineNumbers:true}
power(x, n):
    half = power(x, n/2)
```
- Now time becomes:
- $$O(\log n)$$
- Instead of
- $$O(n)$$

---

## 🔄 3. Binary Search vs Recursion

- Binary search is often implemented recursively.
- But:
- Binary Search = eliminating half
- Recursion = method of implementation
- They are not the same thing.



---

## ⚠️ Common Beginner Mistakes

- ❌ No base case
- → infinite recursion
- ❌ Wrong mid calculation
- → overflow or wrong answer
- ❌ Not shrinking search space
- → infinite loop
- ❌ Not checking boundary carefully
- → off-by-one errors

---

## 🎯 Day 2 Invariants (Must Drill)

- From curriculum core
- LPU REVISED 9-DAY ACCELERATED D…
- Search space must shrink.
- Sorted guarantee must hold.
- Predicate must be monotonic.
- Recursive calls must strictly reduce state.
- Base case must terminate.

---

## 🧠 Mental Model Summary

- Binary Search asks:
- “Which half can I eliminate safely?”
- 
- Recursion asks:
- “How do I reduce this problem into a smaller version of itself?”

---

## 🚀 If They Understand Only This, They Can Start

- Sorted → binary search possible
- Monotonic → boundary finding possible
- Base case → recursion safe
- Shrink state → recursion valid
- Divide by 2 → logarithmic speed
- That’s enough to begin solving