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