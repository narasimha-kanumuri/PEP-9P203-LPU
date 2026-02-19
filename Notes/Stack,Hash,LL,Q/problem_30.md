# LEVEL 4 — DAY 7  
## L4-D7-Q2 — *The Alien Language Translator*

---

## PART 1

### 🧩 Question (Story-Based)

A space research lab has intercepted two **alien communication logs**.

Each log is a string of symbols. Scientists believe:

- The **structure** of the message matters more than the symbols themselves.
- One alien symbol may consistently translate to **exactly one** human symbol.
- However:
  - A symbol **cannot map to two different symbols**
  - Two symbols **cannot map to the same symbol**

The chief linguist asks:

> **Can the first alien message be translated into the second one using a consistent, one-to-one symbol mapping?**

Your task is to determine whether such a translation is possible.

If the structure matches perfectly, return `true`.  
Otherwise, return `false`.

---

### 📥 Input

- Two strings `alien` and `human`
- Both strings contain visible ASCII characters only

---

### 📤 Output

- `true` → if the alien string can be translated into the human string
- `false` → otherwise

---

### 📌 Constraints

- `1 ≤ length(alien), length(human) ≤ 10^5`
- Both strings must be of **equal length**
- **Hash Map usage is mandatory**
- **One-to-one mapping is required**
- **Bidirectional constraint must be enforced**
- No sorting
- No pattern replacement tricks
- Single left-to-right scan preferred

---

### 🧪 Sample Inputs & Outputs

| Alien | Human | Output | Explanation |
|------|-------|--------|-------------|
| `"egg"` | `"add"` | `true` | e → a, g → d |
| `"foo"` | `"bar"` | `false` | o maps to both a and r |
| `"paper"` | `"title"` | `true` | Valid bidirectional mapping |
| `"ab"` | `"aa"` | `false` | a and b map to same symbol |

---

### 📝 Notes

- You are **not told** how to store mappings.
- You must **infer** that:
  - One mapping direction is insufficient
  - Consistency must be checked **both ways**
- This problem is about **design correctness**, not brute force.

---

### 🧠 Deep Implementation Narrative  
*(ELI5 → Logic → Code Mapping)*

#### 🧒 ELI5 Explanation

Imagine you are creating a **translation notebook**.

- For every alien symbol:
  - You write down what human symbol it translates to
- At the same time:
  - You also ensure that no two alien symbols try to claim the same human symbol

As you read the message **character by character**:
- If you’ve seen this alien symbol before:
  - Check if it translates to the same human symbol
- If you haven’t:
  - Make sure the human symbol isn’t already taken
  - Then record the mapping

If you ever see a conflict — translation fails immediately.

---

#### 🧠 Logical Reasoning

We must enforce **two rules simultaneously**:

1. Alien → Human consistency  
2. Human → Alien uniqueness  

This means:
- A **single map is insufficient**
- We must validate the relationship from **both sides**

Early failure is preferred — the moment inconsistency appears, stop.

---

#### 🔗 Mapping to Code (Conceptual)

- Maintain:
  - Map 1: `alienChar → humanChar`
  - Map 2: `humanChar → alienChar`
- Traverse both strings together:
  - Check existing mappings
  - Insert new ones if safe
- If traversal completes without conflict → `true`

---

# Alien Language Translator: Test Cases & Analysis

The goal is to determine if two strings are "isomorphic"—meaning a consistent, one-to-one character substitution exists that can transform the alien string into the human string.

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `alien: "bad", human: "dog"` | `true` | Every character has a unique, consistent partner (`b→d`, `a→o`, `d→g`). |
| `alien: "aab", human: "xyz"` | `false` | The character `a` attempts to map to both `x` and `y`, violating consistency. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Many-to-One" Trap (Reverse Mapping)
**Input:** `alien: "abc", human: "ddd"`  
**Output:** `false`

* **Index 0:** `a → d`. `alienToHuman` is `{a:d}`, `humanToAlien` is `{d:a}`.
* **Index 1:** `b` is new, but `d` is already taken by `a` in `humanToAlien`.
* **Conflict:** Return `false`.

> **Explanation:** This tests the bidirectional constraint. Even if the alien characters are unique, they cannot all point to the same human character.

### 2. The "Self-Mirror" (Identity Mapping)
**Input:** `alien: "apple", human: "apple"`  
**Output:** `true`

* **Dry Run:** Every character maps to itself (`a→a`, `p→p`, etc.).
* **Result:** No conflicts found in either map during the full scan.

> **Explanation:** Validates that characters mapping to themselves is a perfectly legal isomorphic relationship.

### 3. The "Long Distance Conflict"
**Input:** `alien: "turtle", human: "tsetse"`  
**Output:** `false`

* **Index 0-2:** `t→t`, `u→s`, `r→e`.
* **Index 3:** `t` is encountered again. `alienToHuman[t]` is `t`. Current human char is `s`.
* **Conflict:** `t` cannot map to both `t` and `s`. 
* **Result:** `false`.

> **Explanation:** Tests the system's memory over longer strings where a character repeats after several other unique entries.

### 4. The "Symbol Stress Test" (Non-Alphabetic)
**Input:** `alien: "12#12", human: "$%@$%" `  
**Output:** `true`

* **Index 0-2:** `1 → $`, `2 → %`, `# → @`.
* **Index 3:** `1` repeats, matches current human char `$`.
* **Index 4:** `2` repeats, matches current human char `%`.

> **Explanation:** Ensures the algorithm works for all ASCII characters (numbers and symbols), not just the standard alphabet.

### 5. The "Circular Mapping" (Swap Pattern)
**Input:** `alien: "ab", human: "ba"`  
**Output:** `true`

* **Index 0:** `a → b`. `humanToAlien` records `b → a`.
* **Index 1:** `b → a`. `humanToAlien` records `a → b`.
* **Result:** No overlaps or conflicts in the definitions.

> **Explanation:** Checks if the system handles "swapped" definitions where the alien character exists in the human language but represents a different letter.