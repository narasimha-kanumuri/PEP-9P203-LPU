# PART 1 — L4-D6-Q5  
## Inventory Match Report with Quantities

---

## Question (Story-based)

A warehouse maintains **two shipment logs** coming from different suppliers.  
Each log records **item IDs** as integers.  

The warehouse manager wants to generate a **match report** that lists **only the items that appear in both shipments**, **including how many times they appear in both**.

For every item:
- If it appears `x` times in shipment A
- And `y` times in shipment B  
→ It should appear **`min(x, y)` times** in the report.

The order of items in the final report **does not matter**.

---

## Input / Output

### Input
- Two arrays of integers:
  - `shipmentA`
  - `shipmentB`

### Output
- An array containing the **intersection of the two shipments**,  
  including duplicate counts.

---

## Constraints

- Time complexity must be **O(N + M)**.
- **Hashing is mandatory**.
- Sorting the arrays is **not allowed**.
- Output order is **irrelevant**.
- Each input array may contain duplicates.

---

## Sample Inputs & Outputs

### Sample Input 1
shipmentA = [1, 2, 2, 1]
shipmentB = [2, 2]

shell


### Output
[2, 2]

yaml


---

### Sample Input 2
shipmentA = [4, 9, 5]
shipmentB = [9, 4, 9, 8, 4]

shell


### Output
[4, 9]

yaml


*(Order may vary)*

---

## Notes

- The result should reflect **actual overlap quantity**, not just presence.
- Counting frequency efficiently is the core challenge.
- Avoid nested loops — they will violate time constraints.
- This problem tests **frequency-based hashing**, not set logic.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine you have two boxes of items.

- First, you **count how many of each item** is in Box A.
- Then, you open Box B **one item at a time**:
  - If Box A still has that item available → take one and record it
  - Reduce the count so it can’t be reused too many times

This way:
- You never double-count
- You only take what exists in **both** boxes

---

### Logical Breakdown

We must:
1. Count frequencies of items in one shipment
2. Traverse the second shipment
3. For each item:
   - If count > 0 → add to result
   - Decrease count

This ensures:
- Exact duplicate handling
- Linear time
- No sorting needed

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Frequency table | Track available counts | Hash Map |
| Second traversal | Decide actual intersection | Loop |
| Count decrement | Prevent overuse | Map update |
| Result list | Final output | Vector |

**Key Insight:**  
Each element is processed once → O(N + M).

---