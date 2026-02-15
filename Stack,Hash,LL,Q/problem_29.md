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

# First Unique Event: Test Cases & Analysis

The goal is to find the index of the first character in a sequence that does not repeat anywhere else in that sequence. If every character repeats, we return -1.

---

## Additional Sample Test Cases

| Sample Input | Output | Explanation |
| :--- | :--- | :--- |
| `"racecar"` | `3` | 'r', 'a', and 'c' all repeat. 'e' at index 3 is the first and only unique character. |
| `"1122334"` | `6` | Numerical codes follow the same logic; '4' at the final index is the first unique event. |

---

## 5 Variety Test Cases (with Dry Runs)

### 1. The "Immediate Success" Case
**Input:** `"abcdef"`  
**Output:** `0`

* **Phase 1 (Counting):** All characters `a` through `f` are mapped to frequency 1.
* **Phase 2 (Detection):** Start at index 0. The character is `a`.
* **Check:** `freq['a']` is 1.
* **Result:** `0`

> **Explanation:** When the very first character is unique, the algorithm terminates at the first possible step of the detection phase.

### 2. The "Deceptive Start" Case
**Input:** `"aabbccdde"`  
**Output:** `8`

* **Phase 1 (Counting):** `a:2, b:2, c:2, d:2, e:1`.
* **Phase 2 (Detection):**
    * Indices 0-7: All characters have `freq > 1`.
    * Index 8: Character is `e`. `freq['e']` is 1.
* **Result:** `8`

> **Explanation:** Tests the algorithm's ability to skip over multiple different pairs of repeating characters to find a unique one at the very end.

### 3. The "Mixed Symbol" Case
**Input:** `"!@#$!@#"`  
**Output:** `3`

* **Phase 1 (Counting):** `!:2, @:2, #:2, $:1`.
* **Phase 2 (Detection):**
    * `log[0]` ('!'): freq 2
    * `log[1]` ('@'): freq 2
    * `log[2]` ('#'): freq 2
    * `log[3]` ('$'): freq 1.
* **Result:** `3`

> **Explanation:** Confirms the system treats non-alphanumeric ASCII symbols (like sensor codes) correctly using the hash map.

### 4. The "Long Distance Repeat" Case
**Input:** `"zabcdefgzh"`  
**Output:** `1`

* **Phase 1 (Counting):** `z:2, a:1, b:1, c:1, d:1, e:1, f:1, g:1, h:1`.
* **Phase 2 (Detection):**
    * `log[0]` ('z'): freq 2 (Skip)
    * `log[1]` ('a'): freq 1.
* **Result:** `1`

> **Explanation:** Even though `z` was the first character seen, it repeats much later. The algorithm correctly identifies `a` as the first character that never repeats throughout the entire string.

### 5. The "Complete Saturation" Case
**Input:** `"nxnxnx"`  
**Output:** `-1`

* **Phase 1 (Counting):** `n:3, x:3`.
* **Phase 2 (Detection):**
    * `log[0]` ('n'): freq 3
    * `log[1]` ('x'): freq 3
    * ... (No unique character found).
* **Result:** `-1`

> **Explanation:** Validates the requirement to return -1 when the log contains only repeating events, regardless of how many times they repeat (odd or even).
