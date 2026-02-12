# LEVEL 4 — DAY 7  

## L4-D7-Q1 — *The Museum Guard’s Logbook*

---

## PART 1

### 🧩 Question (Story-Based)

A museum uses an **automated night-guard system** to monitor activity inside a restricted gallery.

Every night, the system records a **string of symbols** representing events as they occurred over time:

- Each character is a **symbol code** for an event.
- Most events occur **multiple times** (routine checks, repeated sensor triggers).
- Occasionally, a **rare event** happens only **once** — this is what the chief guard wants to investigate.

The logbook records events **in order**, and the chief guard wants to know:

> **Which event symbol is the first one that never repeats, and at what position did it occur?**

If *every* event repeats, the system should clearly report that **no unique event exists**.

⚠️ The system processes logs in real time, so efficiency matters.

---

### 📥 Input

- A single string `log` consisting of visible ASCII characters  
  (letters, digits, symbols — treat all as valid event codes)

---

### 📤 Output

- An integer representing the **0-based index** of the **first non-repeating character**
- If no such character exists, return `-1`

---

### 📌 Constraints

- `1 ≤ length(log) ≤ 10^5`
- **Hashing is mandatory**
- **Single pass is allowed**
- **Early termination is preferred**
- No sorting allowed
- No nested scanning of the string

---

### 🧪 Sample Inputs & Outputs

| Input String | Output | Explanation |
|--------------|--------|-------------|
| `"museum"`   | `0`    | `'m'` appears only once and is first |
| `"aabbcc"`   | `-1`   | All characters repeat |
| `"swiss"`    | `1`    | `'w'` is the first non-repeating event |

---

### 📝 Notes

- You are **not told** which data structure to use.
- You must **infer the need** for an auxiliary structure to track repetitions.
- Think about:
  - How to remember counts efficiently
  - How to still respect the *original order*
- This problem is designed to test **design intuition**, not brute force.

---

### 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

#### 🧒 ELI5 Explanation

Imagine you’re reading the logbook **letter by letter**.

- You keep a small notebook where:
  - You write down **how many times** you’ve seen each symbol.
- When a symbol shows up:
  - If it’s the **first time**, mark it as “seen once”
  - If it shows up again, update it as “repeated”

After processing the log:
- You scan the log again from the start
- The **first symbol** whose count is exactly **1** is your answer

If you finish and find none — report `-1`.

---

#### 🧠 Logical Reasoning

- We need **fast lookup** to count symbols → constant time access
- We must **preserve order** → original string traversal matters
- Brute-force (checking every character against all others) is too slow

So the solution naturally splits into:
1. **Counting phase**
2. **Detection phase**

---

#### 🔗 Mapping to Code (Conceptual)

- Use a structure that maps:
  - `character → frequency`
- Traverse the string:
  - Update frequency
- Traverse again:
  - Return index of first character with frequency = 1

This respects:
- Time efficiency
- Order preservation
- Clean separation of concerns

---