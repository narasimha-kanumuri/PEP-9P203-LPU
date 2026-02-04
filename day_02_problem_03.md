<!--
---
marp: true
---

-->


# Program 3: Find the Middle of a Singly Linked List

---

## Problem

Given the **head of a singly linked list**, find and return the **middle node** of the list.

If the list has:
- **Odd number of nodes** → return the exact middle
- **Even number of nodes** → return the **second middle node**

You must solve this using **only pointer traversal**, without counting nodes beforehand.

---

## Constraints

- Number of nodes: `1 ≤ N ≤ 10^5`
- Node values are integers
- Singly linked list
- Only `O(1)` extra space allowed

---

## Examples

### Example 1 (Odd length)
**Input**
10 → 20 → 30 → 40 → 50
Copy code

**Output**
30
Copy code

---

### Example 2 (Even length)
**Input**
1 → 2 → 3 → 4
Copy code

**Output**
3
Copy code

---

## ELI5 Explanation

Imagine people standing in a straight line.

- One person walks **one step at a time**
- Another person walks **two steps at a time**

When the faster person reaches the **end of the line**:
- The slower person will be standing **in the middle**

This works no matter how long the line is.

---

## Key Observations

- Linked lists do **not** allow direct indexing
- You cannot jump to the middle
- Traversal must be **sequential**
- Counting nodes first would require **two passes**

We want to do it in **one pass**.

---

## Implementation Narrative (English → Code)

### Step 1: Node Structure Assumption

Each node contains:
- A data value
- A pointer/reference to the next node
[data | next] → [data | next] → ...
Copy code

---

### Step 2: Initialize Two Pointers

- `slow` pointer:
  - Moves **one node at a time**
  - Starts at `head`

- `fast` pointer:
  - Moves **two nodes at a time**
  - Starts at `head`

Both pointers begin at the **same node**.

---

### Step 3: Traverse the List

While:
- `fast` is not `NULL`
- AND `fast->next` is not `NULL`

Do:
- Move `slow` by **one step**
- Move `fast` by **two steps**

This keeps `fast` moving twice as fast as `slow`.

---

### Step 4: Why This Finds the Middle

- For every 2 nodes `fast` moves,
  `slow` moves 1 node
- When `fast` reaches the end:
  - `slow` has covered **half the list**
- If the list length is even:
  - `slow` ends at the **second middle**

---

### Step 5: Termination

- Loop stops when `fast` can no longer move two steps
- At that moment:
  - `slow` points to the required middle node
- Return `slow`

---

## Why This Works

- Only **one traversal**
- No extra memory
- No need to know list size
- Guaranteed correctness due to relative speed difference

---

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Extra Space:** `O(1)`

---

## Conceptual Bridges

- Same logic used in:
  - Cycle detection (Floyd’s algorithm)
  - Palindrome check on linked list
  - Finding kth node from end
- Reinforces:
  - Pointer movement
  - Relative speed reasoning
  - Non-contiguous memory traversal


# Program 3: Find the Middle of a Singly Linked List  
## Part 2 — Solution Code and Test Cases

---

## Solution Code (C++)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // second middle for even-length lists
}

```

## Test Cases(cpp)

```cpp

#include <iostream>
#include "middle_linked_list.cpp"

using namespace std;

// Helper: create linked list from array
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: free memory
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void runTest(int arr[], int n, int expected) {
    Node* head = createList(arr, n);
    Node* mid = findMiddle(head);

    cout << "Expected Middle: " << expected << " | Got: ";
    if (mid) cout << mid->data << endl;
    else cout << "NULL" << endl;

    deleteList(head);
}

int main() {

    // 1. Single node
    int t1[] = {10};
    runTest(t1, 1, 10);

    // 2. Two nodes (even → second middle)
    int t2[] = {1, 2};
    runTest(t2, 2, 2);

    // 3. Three nodes
    int t3[] = {1, 2, 3};
    runTest(t3, 3, 2);

    // 4. Four nodes (even → second middle)
    int t4[] = {10, 20, 30, 40};
    runTest(t4, 4, 30);

    // 5. Five nodes
    int t5[] = {5, 10, 15, 20, 25};
    runTest(t5, 5, 15);

    // 6. All same values
    int t6[] = {7, 7, 7, 7, 7};
    runTest(t6, 5, 7);

    // 7. Negative values
    int t7[] = {-5, -3, -1, 0, 2};
    runTest(t7, 5, -1);

    // 8. Large even-sized list
    int t8[] = {1,2,3,4,5,6,7,8};
    runTest(t8, 8, 5);

    // 9. Large odd-sized list
    int t9[] = {1,2,3,4,5,6,7};
    runTest(t9, 7, 4);

    // 10. Empty list
    Node* empty = nullptr;
    Node* mid = findMiddle(empty);
    cout << "Expected Middle: NULL | Got: "
         << (mid == nullptr ? "NULL" : "NOT NULL") << endl;

    return 0;
}


```
