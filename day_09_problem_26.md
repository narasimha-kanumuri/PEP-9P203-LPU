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