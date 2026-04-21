# 1️⃣ Diagonal Rainwater Trapping

---

## Concepts

- 2D arrays + directional DP.

---

## Problem

- You are given an N × M grid representing heights.
- Rainwater can only flow diagonally down-left or down-right.
- Compute how much water is trapped after rain.

---

## Example

- **Input:**

> ```text
> 3 3
> 3 1 3
> 2 1 2
> 3 2 3
> ```

- **Output:**

> ```text
> 2
> ```

---

## Twist

- Normal water trapping considers 4 directions.
- Here only:
- ↙
- ↘
- Students must rethink boundary flow.

---

## 2️⃣ Largest Alternating Square

---

## Concepts

- DP + 2D arrays.

---

## Problem

- Given a binary matrix, find the largest square where adjacent cells alternate between 0 and 1.
- **Example valid square:**

> ```text
> 0 1
> 1 0
> ```

---

## Example

- **Input:**

> ```text
> 1 0 1
> 0 1 0
> 1 0 1
> ```

- **Output:**

> ```text
> 3
> ```

---

## Twist

- Instead of same values (classic maximal square), values must alternate like chessboard.

---

## 3️⃣ Row-Column Flip Puzzle

---

## Concepts

- Matrix operations + parity logic.

---

## Problem

- You are given a binary matrix.
- You may flip any entire row or any entire column.
- After flips, maximize the number of rows that become identical.

---

## Example

- **Input:**

> ```text
> 1 0 1
> 0 1 0
> 1 0 1
> ```

- **Output:**

> ```text
> 3
> ```

---

## Twist

- Flipping row/column toggles all bits.
- Students must realize rows with complement patterns are equivalent.

---

## 4️⃣ Maximum Increasing Path with One Teleport

---

## Concepts

- DP + grid traversal.

---

## Problem

- **You can move:**
- right
- down
- Cells must strictly increase.
- But exactly once, you may teleport to any cell with greater value.
- Return maximum path length.
- **Example:**

> ```text
> 1 2 3
> 2 3 4
> 3 4 5
> ```

- **Without teleport:**
- length = 5
- Teleport allows skipping.

---

## Twist

- Teleport allowed only once.
- **Students must track two states:**
- used teleport
- not used teleport

---

## 5️⃣ Diamond Sum Matrix

---

## Concepts

- 2D prefix sums.

---

## Problem

- Find the maximum diamond-shaped sum of size K.
- **Example diamond (K=2):**

> ```text
>   a
>  b c d
>   e
> ```

- **Matrix example:**

> ```text
> 1 2 3
> 4 5 6
> 7 8 9
> ```

- **Largest diamond sum:**
- 2 + 4 + 5 + 6 + 8 = 25

---

## Twist

- Cells containing -1 act as blocked cells and break the diamond.
- Students must handle invalid shapes.

---

## Difficulty (Classroom)

| Problem | Difficulty |
| :--- | :--- |
| Diagonal rainwater | Hard |
| Alternating square | Medium |
| Row-column flip | Medium |
| Increasing path teleport | Hard |
| Diamond sum | Medium |

---

## Teaching Tip

- **Tell students:**
- “These are grid DP problems disguised as matrix puzzles.”
- **The key mental model becomes:**
- cell state depends on neighbors