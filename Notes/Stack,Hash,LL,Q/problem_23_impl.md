- [First Honest Number in a Live Feed](#first-honest-number-in-a-live-feed)
  - [Implementation Narrative (English → Code Thinking)](#implementation-narrative-english--code-thinking)
- [1️⃣ What Is This Problem REALLY Asking?](#1️⃣-what-is-this-problem-really-asking)
- [2️⃣ Why One Structure Is Not Enough](#2️⃣-why-one-structure-is-not-enough)
- [3️⃣ The Core Programmer Insight](#3️⃣-the-core-programmer-insight)
- [4️⃣ Exact Logical Rule](#4️⃣-exact-logical-rule)
- [5️⃣ Step-by-Step Mental Algorithm (Before Code)](#5️⃣-step-by-step-mental-algorithm-before-code)
- [6️⃣ English → Code Mapping (Language Neutral)](#6️⃣-english--code-mapping-language-neutral)
- [7️⃣ Deep Test Case Thinking (Trace-Based Reasoning)](#7️⃣-deep-test-case-thinking-trace-based-reasoning)
  - [Example: 4, 5, 4, 5, 3](#example-4-5-4-5-3)
- [8️⃣ Programmer Thinking Questions (Make Students Think)](#8️⃣-programmer-thinking-questions-make-students-think)
- [9️⃣ Edge Case Reasoning](#9️⃣-edge-case-reasoning)
- [🔟 Why This Works (Amortized Thinking)](#-why-this-works-amortized-thinking)
- [Final Mental Model](#final-mental-model)


# First Honest Number in a Live Feed  

## Implementation Narrative (English → Code Thinking)

---

# 1️⃣ What Is This Problem REALLY Asking?

After every new number arrives:

Find the earliest number that:

- Has appeared exactly once
- Has not been repeated later

If none exists → return -1.

Important:

- We must answer immediately.
- We cannot wait for full input.
- Order matters.
- Frequency matters.

This is not just counting.
This is counting + preserving arrival order.

---

# 2️⃣ Why One Structure Is Not Enough

Ask yourself:

If I only store frequency:
→ I don’t know which unique number came first.

If I only store order:
→ I don’t know if number repeated.

Therefore:

We need TWO separate responsibilities.

Think in responsibilities, not syntax.

---

# 3️⃣ The Core Programmer Insight

We are solving two problems at the same time:

1. Track how many times each number appeared.
2. Track the order in which numbers arrived.

And we must constantly clean invalid candidates.

This is a state-management problem.

---

# 4️⃣ Exact Logical Rule

At any moment:

First Honest Number =

The first number in arrival order such that:

frequency[number] == 1

If no such number exists → output -1.

---

# 5️⃣ Step-by-Step Mental Algorithm (Before Code)

For every incoming number:

Step 1:
Increase its frequency count.

Step 2:
Add it to the “candidate line”.

Step 3:
Check the front of the line.
If its frequency is greater than 1:
Remove it.

Keep removing until:
- Front has frequency == 1
OR
- Line becomes empty.

Step 4:
If line empty → answer = -1  
Else → answer = front of line

That is the entire engine.

---

# 6️⃣ English → Code Mapping (Language Neutral)

| English Idea | What Code Must Do |
|--------------|------------------|
| Track count of numbers | Use key-value frequency storage |
| Preserve arrival order | Use FIFO structure |
| Add new number | Insert into both structures |
| Remove invalid candidate | Loop while front is repeating |
| Return current answer | Check if structure empty |

Notice:

We never scan entire history.
We only touch each element twice:
- Once when it arrives
- Once when it gets removed

That is why this is efficient.

---

# 7️⃣ Deep Test Case Thinking (Trace-Based Reasoning)

For stream problems:
Always think in table format.

Columns:

Incoming | Frequency | Candidate Line | Output

---

## Example: 4, 5, 4, 5, 3

Step 1:
Incoming 4  
Frequency: {4:1}  
Line: [4]  
Output: 4  

Step 2:
Incoming 5  
Frequency: {4:1,5:1}  
Line: [4,5]  
Output: 4  

Step 3:
Incoming 4  
Frequency: {4:2,5:1}  
Front = 4 → invalid  
Remove 4  
Line becomes [5]  
Output: 5  

Step 4:
Incoming 5  
Frequency: {4:2,5:2}  
Front = 5 → invalid  
Remove 5  
Line empty  
Output: -1  

Step 5:
Incoming 3  
Frequency: {4:2,5:2,3:1}  
Line: [3]  
Output: 3  

---

# 8️⃣ Programmer Thinking Questions (Make Students Think)

After teaching, ask:

- Why is the removal step inside a loop and not an if?
- What happens if we never remove from the line?
- What happens if we remove only once?
- Can an element become honest again later?

(Answer: No. Once frequency > 1, it can never return to 1.)

This builds reasoning.

---

# 9️⃣ Edge Case Reasoning

All numbers repeating:
Line always empty → always -1

All numbers unique:
First element always stays front

Large stream:
Safe, because each element is processed constant times

---

# 🔟 Why This Works (Amortized Thinking)

Each number:

- Enters line once
- Leaves line once

No element is reprocessed multiple times.

So total operations proportional to N.

---

# Final Mental Model

This problem is:

Frequency Tracking  
+ Order Preservation  
+ Continuous Cleanup  

Not just counting.

Think in systems, not values.
