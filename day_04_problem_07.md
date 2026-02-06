# Q7: Remove N-th Node from End of Linked List (Edge-Strict)
## Part 1 — Problem, ELI5, and Implementation Narrative

---

## Problem

Given the **head of a singly linked list**, remove the **N-th node from the end** of the list and return the head.

### Twist / Constraint
- You must remove the node in **one pass**
- You are **not allowed to use a dummy node**
- You must correctly handle **head removal**
- Only `O(1)` extra space allowed

---

## Constraints

- `1 ≤ N ≤ length of the list`
- Number of nodes: `1 ≤ length ≤ 10^5`
- Singly linked list
- No extra data structures allowed

---

## Examples

### Example 1
Input:  1 → 2 → 3 → 4 → 5 , N = 2 Output: 1 → 2 → 3 → 5
Copy code

---

### Example 2
Input:  1 → 2 , N = 2 Output: 2
Copy code

---

### Example 3
Input:  1 , N = 1 Output: NULL
Copy code

---

## ELI5 Explanation

Imagine people standing in a line.

- One person (`fast`) starts walking first
- After `N` steps, another person (`slow`) starts walking
- Both walk **together**, one step at a time

When the first person reaches the end:
- The second person is standing **just before** the person who must be removed

Special case:
- If the first person reaches the end **before** the second person starts,
  the first person in line must be removed

---

## Key Observations

- Linked lists cannot be indexed
- Removing a node requires access to the **previous node**
- Since dummy nodes are not allowed:
  - Head removal must be handled manually
- One-pass constraint forbids counting first

---

## Implementation Narrative (English → Code)

### Step 1: Initialize Two Pointers

- `fast` pointer → starts at `head`
- `slow` pointer → starts at `head`

Both pointers point to the **same node initially**.

---

### Step 2: Advance Fast Pointer by N Steps

Move `fast` forward `N` times.

Two cases arise:

#### Case A: `fast` becomes `NULL`
- This means `N` equals the length of the list
- The node to be removed is the **head**
- Return `head->next`

#### Case B: `fast` is not `NULL`
- Continue with both pointers

---

### Step 3: Move Both Pointers Together

Move `fast` and `slow` one step at a time until:
fast->next == NULL
Copy code

At this point:
- `slow` is pointing to the **node before the target**
- `slow->next` is the node to be removed

---

### Step 4: Remove the Target Node

- Store `slow->next` temporarily
- Redirect:
slow->next = slow->next->next
Copy code

- The list remains connected
- Return the original `head`

---

## Why This Is Harder Than the Classic Version

- Dummy node usually absorbs edge cases — here it is forbidden
- Head removal must be reasoned explicitly
- Off-by-one pointer errors are common
- Requires precise loop conditions

---

## Edge Case Handling Summary

- Single node list → always return `NULL`
- N equals list length → remove head
- N equals 1 → remove last node
- Two-node list → must still work correctly

---

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Extra Space:** `O(1)`

---

## Conceptual Bridges

- Same fast/slow spacing idea used in:
  - Cycle start detection
  - K-th node from end
  - Sliding window on linked lists
- Strengthens:
  - Boundary reasoning
  - Pointer offset logic
  - Head-safe operations


## Test Cases

```cpp

#include <iostream>
#include "remove_nth_from_end.cpp"

using namespace std;

// Helper: create linked list from initializer list
Node* createList(const initializer_list<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int v : values) {
        Node* node = new Node(v);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Helper: print linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "NULL\n";
        return;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper: run a test
void runTest(const initializer_list<int>& values, int n) {
    Node* head = createList(values);

    cout << "Original: ";
    printList(head);

    cout << "N = " << n << endl;

    Node* updated = removeNthFromEnd(head, n);

    cout << "After Removal: ";
    printList(updated);

    cout << "------------------------\n";
}

int main() {

    // 1. Single node, remove head
    runTest({1}, 1);

    // 2. Two nodes, remove head
    runTest({1, 2}, 2);

    // 3. Two nodes, remove last
    runTest({1, 2}, 1);

    // 4. Odd length list
    runTest({1, 2, 3, 4, 5}, 2);

    // 5. Remove last node
    runTest({10, 20, 30, 40}, 1);

    // 6. Remove head in longer list
    runTest({10, 20, 30, 40}, 4);

    // 7. Remove middle node
    runTest({5, 10, 15, 20, 25}, 3);

    // 8. Repeated values
    runTest({7, 7, 7, 7}, 2);

    // 9. Large N (equals length)
    runTest({100, 200, 300}, 3);

    // 10. Longer list
    runTest({1,2,3,4,5,6,7,8,9,10}, 5);

    return 0;
}


```


# Q3: Remove N-th Node from End of Linked List (Edge-Strict)
## Part 2 — Solution Code and Test Cases

---

## Solution Code (C++)

```cpp
#include <iostream>
using namespace std;

// Definition of singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Removes the N-th node from the end of the list
// Constraint: one pass, no dummy node
Node* removeNthFromEnd(Node* head, int n) {

    if (head == nullptr) return nullptr;

    Node* fast = head;
    Node* slow = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) return head; // safety (should not happen per constraints)
        fast = fast->next;
    }

    // If fast is NULL, head must be removed
    if (fast == nullptr) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers until fast reaches last node
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to remove
    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return head;
}

```

## Complexity

Time _ O(N)

Space - O(1)