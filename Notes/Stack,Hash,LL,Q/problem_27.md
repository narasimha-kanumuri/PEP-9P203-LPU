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


# Shipment Intersection: Test Cases & Analysis

This problem identifies the common items between two shipment logs. If an item appears multiple times in both logs, it should appear in the intersection as many times as it does in the smaller of the two logs.

---

## Additional Sample Test Cases

| Sample Input | Output | Explanation |
| :--- | :--- | :--- |
| `A = [1, 1, 1], B = [1, 1]` | `[1, 1]` | Item `1` appears three times in A and twice in B. The minimum overlap is 2. |
| `A = [10, 20], B = [30, 40]` | `[]` | No items overlap between the two shipments, resulting in an empty report. |

---

## 5 Variety Test Cases (with Dry Runs)

### 1. The "Uneven Duplicates" Case
**Input:** `A = [7, 7, 8, 8, 8], B = [7, 8, 8]`  
**Output:** `[7, 8, 8]`

* **Map A:** `{7: 2, 8: 3}`
* **Process B:**
    * `7`: Found in map (count 2). Add to result, Map becomes `{7: 1, 8: 3}`.
    * `8`: Found in map (count 3). Add to result, Map becomes `{7: 1, 8: 2}`.
    * `8`: Found in map (count 2). Add to result, Map becomes `{7: 1, 8: 1}`.

> **Explanation:** Tests if the algorithm correctly picks the minimum count when both sides have duplicates but in different quantities.

### 2. The "Single Match in Chaos" Case
**Input:** `A = [1, 5, 10, 20, 25], B = [99, 88, 77, 10, 66]`  
**Output:** `[10]`

* **Map A:** `{1: 1, 5: 1, 10: 1, 20: 1, 25: 1}`
* **Process B:**
    * `99, 88, 77`: Not in map.
    * `10`: Found (count 1). Add to result, Map becomes `{..., 10: 0, ...}`.
    * `66`: Not in map.

> **Explanation:** Ensures the logic works when only a single element matches amidst many unique ones.

### 3. The "Exhausted Supply" Case
**Input:** `A = [3, 3], B = [3, 3, 3, 3, 3]`  
**Output:** `[3, 3]`

* **Map A:** `{3: 2}`
* **Process B:**
    * `3`: Found (count 2). Add to result, Map `{3: 1}`.
    * `3`: Found (count 1). Add to result, Map `{3: 0}`.
    * `3, 3, 3`: Found in map but count is 0. Ignore.

> **Explanation:** Validates that the "consumer" logic (decrementing the count) prevents the second shipment from claiming more items than the first shipment actually provides.

### 4. The "Empty Shipment" Case
**Input:** `A = [], B = [1, 2, 3]`  
**Output:** `[]`

* **Map A:** `{}` (Empty)
* **Process B:** `1, 2, 3` are not found in the empty map.

> **Explanation:** Confirms that the code handles edge cases where one shipment log is entirely missing or empty without crashing.

### 5. The "Interleaved Items" Case
**Input:** `A = [1, 2, 1, 2], B = [2, 1, 2, 1]`  
**Output:** `[2, 1, 2, 1]` (Order may vary)

* **Map A:** `{1: 2, 2: 2}`
* **Process B:**
    * `2`: Found (count 2). Add to result. Map `{1: 2, 2: 1}`.
    * `1`: Found (count 2). Add to result. Map `{1: 1, 2: 1}`.
    * `2`: Found (count 1). Add to result. Map `{1: 1, 2: 0}`.
    * `1`: Found (count 1). Add to result. Map `{1: 0, 2: 0}`.

> **Explanation:** Tests the robustness of the frequency map when items are scattered throughout the arrays rather than grouped.