# PART 1 — L4-D6-Q1  
## First Honest Number in a Live Feed

---

## Question (Story-based)

A news channel is streaming **live vote counts** coming from remote polling booths.  
Each vote is represented as an integer ID.

The channel wants to display, **at every moment**, the *first vote ID that has appeared exactly once so far* in the stream.

If at any moment **no such ID exists**, the channel displays `-1`.

You are given the vote stream **one number at a time**.  
After each incoming number, output the current *first honest vote*.

This system must work **live** — you are not allowed to wait for the full stream before producing output.

---

## Input / Output

### Input
- A stream (sequence) of integers arriving one by one.

### Output
- After processing each integer, output the **first non-repeating element so far**.
- If none exists, output `-1`.

---

## Constraints

- Processing must be **online** (step-by-step).
- Each element must be handled in **O(1) amortized time**.
- Re-scanning the entire stream after each input is **not allowed**.
- Efficient tracking of frequency and order is required.

---

## Sample Input & Output

### Sample Input
Stream: 4, 5, 4, 5, 3

vbnet


### Step-by-step Output
After 4 → 4
After 5 → 4
After 4 → 5
After 5 → -1
After 3 → 3

shell


### Final Output Sequence
4 4 5 -1 3

yaml


---

## Notes

- The stream **never stops** — your logic should not depend on knowing the total size.
- Order matters: the *earliest* valid non-repeating element wins.
- Printing immediately after each input is mandatory.
- This problem hides **two data-structure requirements** — spotting both is key.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine you are standing in a line where people shout numbers.

- You write down **how many times** each number is shouted.
- You also keep a **line (queue)** of numbers that *might* still be honest.
- Whenever a number becomes dishonest (appears more than once), you quietly remove it from the front of the line.

At every step:
- Look at the **front of the line**
- If it’s still honest → print it
- Otherwise, remove it and check again
- If the line is empty → print `-1`

---

### Logical Breakdown

We need to answer **three questions efficiently**:
1. How many times has a number appeared?
2. What is the order in which numbers arrived?
3. How do we quickly discard numbers that became repeating?

To do this:
- We **count occurrences** using a fast lookup structure.
- We **preserve arrival order** using a structure that supports removal from the front.
- Each number enters and exits this order structure **at most once**, ensuring speed.

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|-------------|---------------|
| Frequency tracking | Know if a number is repeating | Hash Map |
| Arrival order | Preserve first-come rule | Queue |
| Cleanup loop | Remove invalid candidates | While front is repeating |
| Online output | Immediate visibility | Print after each step |

**Important Insight:**  
A number is **pushed once** and **popped once** → total operations stay linear.

---


## Test Case

# First Honest Number: Test Cases & Analysis

This document contains the sample and variety test cases for the **First Honest Number** problem, including dry runs and logical explanations.

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `1, 2, 1` | `1 1 2` | The first unique number is 1 until it repeats at the third step, leaving 2 as the new first unique. |
| `8, 8, 8` | `-1 -1 -1` | Since 8 repeats immediately and no other numbers arrive, no unique ID ever exists. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Perfect Alternator" (Toggling States)
**Input:** `10, 20, 10, 20`  
**Output:** `10 10 20 -1`

* **In 10:** Freq `{10:1}`, Queue `[10]`. Front is 10. Output: **10**
* **In 20:** Freq `{10:1, 20:1}`, Queue `[10, 20]`. Front is 10. Output: **10**
* **In 10:** Freq `{10:2, 20:1}`, Queue `[10, 20]`. Pop 10 (freq > 1). Front is 20. Output: **20**
* **In 20:** Freq `{10:2, 20:2}`, Queue `[20]`. Pop 20 (freq > 1). Queue empty. Output: **-1**

> **Explanation:** This tests the system's ability to "move the pointer" to the next candidate when the current leader becomes dishonest.

### 2. The "Fresh Blood" (Late Unique Entry)
**Input:** `5, 5, 5, 9`  
**Output:** `-1 -1 -1 9`

* **Steps 1-3:** `5` arrives repeatedly. Queue is cleared every time because `freq[5] > 1`. Output: **-1, -1, -1**
* **In 9:** Freq `{5:3, 9:1}`, Queue `[9]`. Front is 9. Output: **9**

> **Explanation:** Validates that the system recovers from a "no unique" state (-1) as soon as a new unique number arrives.

### 3. The "Unique Streak" (No Repetitions)
**Input:** `1, 2, 3`  
**Output:** `1 1 1`

* **In 1:** Queue `[1]`. Front: **1**
* **In 2:** Queue `[1, 2]`. Front: **1**
* **In 3:** Queue `[1, 2, 3]`. Front: **1**

> **Explanation:** Tests if the "First" rule is respected. Even though 2 and 3 are unique, 1 arrived first and stays the leader.

### 4. The "Deep Cleanup" (Mass Invalidation)
**Input:** `1, 2, 3, 1, 2`  
**Output:** `1 1 1 2 3`

* **Steps 1-3:** Output is `1`. Queue is `[1, 2, 3]`.
* **In 1:** `freq[1]` becomes 2. Pop 1. New front is 2. Output: **2**
* **In 2:** `freq[2]` becomes 2. Pop 2. New front is 3. Output: **3**

> **Explanation:** Shows the `while` loop logic in action, where multiple elements are popped in a single step to find the next valid "Honest Number."

### 5. The "Recurrent Distraction" (Repeating an already repeated number)
**Input:** `4, 6, 4, 4`  
**Output:** `4 4 6 6`

* **In 4:** Queue `[4]`. Output: **4**
* **In 6:** Queue `[4, 6]`. Output: **4**
* **In 4:** `freq[4]=2`. Pop 4. Front is 6. Output: **6**
* **In 4:** `freq[4]=3`. Queue is `[6]`. Front is 6. Output: **6**

> **Explanation:** Ensures that further appearances of an already "dishonest" number do not affect the current valid leader.

