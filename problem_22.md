# LEVEL 4 — DAY 5  

## L4-D5-Q6: Compiler Expression Health Check (Combined Problem)  

### PART 1 — Question, Explanation & Notes

---

## 1. Problem Statement (Story Form)

A compiler performs a **pre-flight check** on arithmetic expressions before evaluation.

The compiler must ensure that:

1. The expression is **structurally valid**
2. All brackets are **balanced**
3. There are **no unnecessary (redundant) brackets**

An expression that passes all checks is marked **HEALTHY**.  
Otherwise, it is marked **UNHEALTHY**, with the reason clearly identifiable.

---

## 2. The Twist (Very Important)

You are **not allowed** to use:

- Regular expressions
- Parsing libraries
- Grammar generators

You must analyze the expression in **one left-to-right scan** using **manual logic only**.

---

## 3. Clarified Task

Given a string expression consisting of:

- Lowercase letters (`a`–`z`)
- Operators: `+ - * /`
- Parentheses: `(` and `)`

Determine whether the expression:

- ❌ Has **unbalanced brackets**
- ❌ Contains **redundant brackets**
- ❌ Has **invalid operator placement**
- ✅ Or is **valid and minimal**

---

## 4. Output Expectations

Return one of the following results:

- `"UNBALANCED"`
- `"REDUNDANT"`
- `"INVALID"`
- `"VALID"`

Only **one** status should be returned for an expression.

---

## 5. Constraints (Strict)

- Single pass only
- Stack usage is **mandatory**
- Operator awareness required
- No regex / parsing libraries
- Expression length ≤ 10⁵
- Early termination allowed on error detection

---

## 6. Implementation Narrative  

### (ELI5 → English-to-Code)

Think like a compiler, not like a calculator.

You are **not evaluating** the expression.  
You are only checking its **shape and structure**.

---

### What Needs to Be Tracked

As you scan characters from left to right, you must remember:
- Open brackets waiting to be closed
- Whether each pair of brackets actually **does something useful**
- Whether operators are placed **between valid operands**

---

### Step-by-Step Logic

#### 1. Use a stack to track expression components

The stack will store:
- `'('` → opening brackets
- Operators (`+ - * /`)
- Operands (letters)

---

#### 2. When you see `'('`
- Push it onto the stack
- It marks the start of a sub-expression

---

#### 3. When you see an operand (`a`–`z`)
- Push it onto the stack
- Operand is always valid by itself

---

#### 4. When you see an operator
- It must satisfy:
  - There is a valid operand **before** it
  - There must be a valid operand **after** it (implicitly checked later)
- Push operator onto stack

If operator appears:
- At the beginning
- After `'('`
- After another operator  

→ Expression is **INVALID**

---

#### 5. When you see `')'`

This is the most important step.

You now check the **contents inside the brackets**:

1. Pop elements until `'('` is found
2. Track whether you saw **at least one operator**

Cases:
- If `'('` is never found → **UNBALANCED**
- If **no operator** was found inside → **REDUNDANT**
- Otherwise:
  - The brackets are useful
  - Pop `'('`
  - Push a placeholder operand (because `(a+b)` becomes an operand)

---

#### 6. After Full Scan

- If stack still contains `'('` → **UNBALANCED**
- If no errors found → **VALID**

---

## 7. Priority of Errors (Important)

If multiple issues exist, return **first applicable** in this order:

1. `UNBALANCED`
2. `INVALID`
3. `REDUNDANT`
4. `VALID`

This makes the result deterministic and testable.

---

## 8. Notes

### Why One Pass Is Enough
- Stack captures all unresolved context
- Each character is processed once

### Why Redundancy Detection Works
- Redundant brackets contain **no operator**
- Example:
  - `(a)` → REDUNDANT
  - `((a+b))` → inner useful, outer redundant

### Common Student Mistakes
- Checking redundancy after full parse ❌
- Not tracking operator presence ❌
- Using regex ❌
- Confusing invalid syntax with redundancy ❌

---

### Hidden Data Structure Insight (for instructors)

This problem **combines**:

- Balanced parentheses
- Operator validation
- Redundant bracket detection

All enforced through:

- **Single stack**
- **Single traversal**
- **Strict invariants**

---

## End of PART 1