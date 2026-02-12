# LEVEL 4 — DAY 5  

## L4-D5-Q1: Live Server Rollback Monitor  

---

## 1. Problem Statement (Story Form)

A production server manages application versions during deployment.

- When a new version is deployed, it is **recorded**.
- When a rollback happens, the **most recent deployed version** is reverted.

You are given a **live stream of operations** coming from the server control system.

However, the system has a strict rule:

> ❗ A rollback can happen **only if there is at least one deployed version available**.

If this rule is violated at any point, the system is considered **corrupted**, and processing must stop immediately.

---

## 2. Clarified Task

Process the operations **one by one, in the order given**, and determine:

- The **1-based index** of the **first invalid operation**
- If all operations are valid, return **-1**

You must detect the error **as soon as it happens**, not after reading all operations.

---

## 3. Input / Output Specification

### Input

- A sequence of operations, each being one of:
  - `"DEPLOY x"` → deploy version `x` (x is an integer)
  - `"ROLLBACK"` → revert the most recent deployment

### Output

- An integer:
  - Index (1-based) of the first invalid operation
  - `-1` if no invalid operation occurs

---

## 4. Constraints (Very Important)

- Operations must be processed **online**
  - You cannot analyze future operations
- Processing must **stop immediately** at first failure
- The number of rollbacks must **never exceed** deployments
- No post-processing or second pass allowed
- Memory usage should scale only with valid history

---

## Example Test Cases

✅ Example 1: All operations valid

### Input

```md
6
DEPLOY 10
DEPLOY 20
ROLLBACK
DEPLOY 30
ROLLBACK
ROLLBACK
```

### Output

```md
-1
```

### Explanation (short, student-facing)

Every rollback happens after a deploy.
The system never tries to rollback an empty history.

## Example 2: First invalid rollback detected

### Input

```md
4
DEPLOY 5
ROLLBACK
ROLLBACK
DEPLOY 10
```

### Output

```md
3
```

### Explanation (short, student-facing)

Operation 1: DEPLOY → OK
Operation 2: ROLLBACK → OK
Operation 3: ROLLBACK → ❌ invalid (no deployment left)

So the first invalid operation is at index 3.

## Instructor Note (not for students)

These examples intentionally test:
Proper online processing
Correct 1-based indexing
Immediate termination on failure

---

## 5. Implementation Narrative (ELI5 → English to Code)

Let’s understand the logic step by step, **without writing code yet**.

### Core Observation

Every `"DEPLOY x"` adds **one new version** on top of the existing versions.

Every `"ROLLBACK"` removes **the most recent version**.

So at any moment, the system is tracking:
> “How many versions are currently active?”

---

### Step-by-Step Logic

1. Start with **no deployed versions**
   - The system begins empty.

2. Process operations **one by one**, from left to right.

3. For each operation:

   #### Case 1: `"DEPLOY x"`

   - A new version is added.
   - This increases the number of active versions by 1.
   - No validity issue can occur here.

   #### Case 2: `"ROLLBACK"`

   - This attempts to remove the **most recent version**.
   - Before removing, check:
     > Is there at least one active version?
   - If **yes**:
     - Remove it.
   - If **no**:
     - This rollback is invalid.
     - Immediately report the **current operation index**.
     - Stop processing further operations.

4. If all operations finish without error:
   - Return `-1`.

---

### Key Invariant (Must Always Hold)

> At every step:  
> **Number of rollbacks ≤ number of deployments so far**

If this invariant breaks even once, the system is invalid.

---

## 6. Notes

### Why Online Processing Matters

- You cannot wait until the end to count deploys and rollbacks.
- A rollback might be invalid **even if later deploys exist**.

### Why Immediate Stop Is Required

- Once system state becomes invalid, future operations are meaningless.
- Continuing would hide the real error location.

### Common Student Mistakes

- Counting total deploys and rollbacks at the end ❌
- Allowing negative version count ❌
- Using unnecessary complex logic when a simple invariant suffices ❌

### Hidden Data Structure Insight (for instructors)

- This problem enforces **Last-In-First-Out behavior**
- The invariant mirrors a **restricted-access structure**
- Students who truly understand stacks will naturally model it correctly

---

## End of PART 1
