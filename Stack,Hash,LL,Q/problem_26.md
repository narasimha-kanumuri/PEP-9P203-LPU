# PART 1 — L4-D6-Q4  
## Secure Command Script Validator

---

## Question (Story-based)

A space station runs **automation scripts** written using symbols to group commands.

Each script uses the following **control symbols**:
- Parentheses: `(` `)`
- Braces: `{` `}`
- Brackets: `[` `]`

For safety reasons, the station enforces **strict validation rules** before executing any script.

Your task is to validate whether a given script is **structurally correct** according to the rules below.

---

## Validation Rules

1. Every opening symbol must be closed by the **correct matching type**.
2. Symbols must be **properly nested**.
3. **Empty pairs are NOT allowed**  
   - `()` ❌  
   - `{}` ❌  
   - `[]` ❌  
4. Only a **single left-to-right scan** of the script is allowed.

If the script violates **any** rule, it is considered **INVALID**.

---

## Input / Output

### Input
- A string consisting only of the characters: `(){}[]`

### Output
- Return `true` if the script is **valid**
- Return `false` otherwise

---

## Constraints

- The solution must use **one traversal only**.
- **Stack-based validation** is required.
- Symbol matching rules must be defined explicitly.
- Time complexity must be **O(N)**.
- No recursion allowed.

---

## Sample Inputs & Outputs

### Sample Input 1
Script = "{[()()]}"

shell


### Output
false

yaml


**Reason:**  
The inner `()` is an empty pair → violates Rule 3.

---

### Sample Input 2
Script = "{[(a+b)*(c-d)]}"

shell


### Output
true

yaml


*(Assume non-symbol characters are ignored)*

---

### Sample Input 3
Script = "([{}])"

shell


### Output
false

yaml


**Reason:**  
`{}` is an empty pair.

---

### Sample Input 4
Script = "{[()x]}"

shell


### Output
true

yaml


---

## Notes

- A pair is considered **empty** if **no character exists between matching symbols**.
- Characters other than symbols may appear and should be **ignored**.
- Detecting emptiness requires remembering **positions**, not just symbols.
- This problem intentionally hides **extra state tracking** inside a classic problem.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Think of reading the script one character at a time.

- When you see an **opening symbol**, you put it on a pile.
- When you see a **closing symbol**:
  - You check the top of the pile
  - If it doesn’t match → invalid
  - If it matches but nothing was written between them → invalid
- At the end:
  - If the pile is empty → valid
  - Otherwise → invalid

So you are not just matching symbols —  
you are also checking whether they **actually wrapped something meaningful**.

---

### Logical Breakdown

We must track:
1. The **type of opening symbol**
2. The **position (index)** where it appeared
3. The **current index** when closing happens

Using this:
- If `closing_index = opening_index + 1`  
  → empty pair → invalid

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Opening symbols | Start of a group | Stack push |
| Closing symbols | End of a group | Stack pop |
| Matching rule | Type correctness | Hash Map |
| Position check | Detect empty pairs | Index tracking |
| Single scan | Performance guarantee | One loop |

**Key Insight:**  
The stack stores **more than characters** — it stores **context**.

---


# Secure Command Script Validator: Test Cases & Analysis

This validator ensures that all brackets (`()`, `[]`, `{}`) are correctly balanced and nested, and that no pair of brackets is "empty" (i.e., they must contain at least one character or nested command between them).

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `{[1]}` | `true` | All symbols match correctly. The pair `[]` contains `1`, so it is not empty. |
| `( )` | `false` | If the logic treats symbols as strictly adjacent ($i$ and $i+1$), the empty space fails the non-empty check. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Nested Emptiness" (Deep Violation)
**Input:** `{[()]}` (Assuming indices: 012345)  
**Output:** `false`

* **Stack:** Push `{` (idx 0), Push `[` (idx 1), Push `(` (idx 2).
* **Process `)` (idx 3):** Top of stack is `(` at idx 2. 
* **Check:** $3 - 2 = 1$. This indicates an "immediate neighbor" (empty).
* **Result:** `false`

> **Explanation:** Even if outer brackets are valid, a single empty pair anywhere in the hierarchy invalidates the script.

### 2. The "Lone Opener" (Incomplete Script)
**Input:** `{ [ a ] `  
**Output:** `false`

* **Step 1:** Push `{` to stack.
* **Step 2:** Push `[` to stack.
* **Step 3:** `a` is a non-symbol character (ignored).
* **Step 4:** `]` matches `[`. Stack now contains only `{`.
* **End:** Loop ends. Stack is **not empty**.
* **Result:** `false`

> **Explanation:** Tests the requirement that every opened command must eventually be closed.

### 3. The "Prefix Closer" (Underflow)
**Input:** `) (a)`  
**Output:** `false`

* **Step 1:** `)` encountered. Stack is empty.
* **Check:** No opener exists to match the closer.
* **Result:** `false` (Immediate Exit)

> **Explanation:** Validates the early-exit condition when a closing symbol appears without a preceding opener.

### 4. The "Content Heavy" (Complex Valid)
**Input:** `(a{b[c]d}e)`  
**Output:** `true`

* **`(` (idx 0):** Pushed.
* **`{` (idx 2):** Pushed.
* **`[` (idx 4):** Pushed.
* **`]` (idx 6):** Matches `[` (idx 4). Distance $6-4 \neq 1$. **OK**.
* **`}` (idx 8):** Matches `{` (idx 2). Distance $8-2 \neq 1$. **OK**.
* **`)` (idx 10):** Matches `(` (idx 0). Distance $10-0 \neq 1$. **OK**.

> **Explanation:** Confirms that as long as characters exist between symbols, nesting can be indefinitely deep.

### 5. The "Symbol Sandwich" (Adjacent Valid Pairs)
**Input:** `[x][y]`  
**Output:** `true`

* **Group 1:** `[` pushed (idx 0), `]` at idx 2 matches. Stack becomes empty.
* **Group 2:** `[` pushed (idx 3), `]` at idx 5 matches. Stack becomes empty.
* **End:** Stack is empty, all checks passed.
* **Result:** `true`

> **Explanation:** Tests if the logic handles multiple separate valid groups in a single sequence.