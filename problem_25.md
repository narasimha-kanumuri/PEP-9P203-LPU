# PART 1 — L4-D6-Q3  
## Longest Streak Without Repeated Visitors

---

## Question (Story-based)

A museum tracks visitors using **wristband IDs** as they walk through a long exhibition hallway.

The museum curator wants to know the **longest continuous stretch of visitors** such that **no wristband ID repeats within that stretch**.

You are given the sequence of wristband IDs in the exact order they were detected.

Your task is to find the **length of the longest contiguous segment** where **all IDs are unique**.

---

## Input / Output

### Input
- An array of integers representing wristband IDs.

### Output
- An integer representing the **maximum length** of a contiguous subarray with all distinct elements.

---

## Constraints

- The solution must run in **O(N) time**.
- Only **one pass** through the array is allowed.
- **Nested loops are not permitted**.
- Efficient tracking of seen elements is required.

---

## Sample Inputs & Outputs

### Sample Input 1
IDs = [1, 2, 3, 1, 2, 3, 4]

shell


### Output
4

yaml


**Explanation:**  
The longest unique stretch is `[1, 2, 3, 4]`.

---

### Sample Input 2
IDs = [5, 5, 5, 5]

shell


### Output
1

yaml


---

### Sample Input 3
IDs = []

shell


### Output
0

yaml


---

## Notes

- The subarray must be **contiguous**.
- Removing or reordering elements is not allowed.
- The problem hides a **sliding window with memory** approach.
- Forgetting old elements correctly is crucial.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine walking along the hallway and writing down visitor IDs on a board.

- You want the board to always show **only unique IDs**.
- When a repeated ID appears:
  - You start erasing from the left until that ID becomes unique again.
- At every step:
  - You measure how long the board currently is.
  - You remember the **longest length** seen so far.

You never walk backward — only forward.

---

### Logical Breakdown

We need to:
1. Keep track of **where each ID was last seen**
2. Maintain a window `[left … right]` that contains only unique IDs
3. Move the left boundary forward when duplicates appear
4. Update the maximum window size during traversal

This ensures:
- Each index is visited once
- The window only expands or contracts forward

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Window start | Marks valid unique range | `left` pointer |
| Current index | Expands the window | `right` pointer |
| Last seen position | Detects duplicates | Hash Map |
| Max length | Final answer | Integer tracker |

**Key Insight:**  
The left pointer never moves backward → linear time guarantee.

---