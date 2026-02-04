<!--
marp: true
-->

---

## Problem

---
Given the **head of a singly linked list**, reverse the list **iteratively**.

### Twist / Constraint

- You are **not allowed to use more than one auxiliary pointer variable**  
  (besides the pointer used to traverse the list).

- No new nodes may be created.
- The reversal must be done **in-place**.
Return the new head of the reversed list.
---
## Constraints
- Number of nodes: `0 ≤ N ≤ 10^5`
- Singly linked list
- Only `O(1)` extra space allowed
- Iterative solution only (no recursion)
---
## Examples
### Example 1
Input:  1 → 2 → 3 → 4 → 5 Output: 5 → 4 → 3 → 2 → 1
Copy code
### Example 2
Input:  10 → 20 Output: 20 → 10
Copy code
---
## ELI5 Explanation
Imagine a chain of paper clips linked in one direction.
You want to reverse the chain, but:
- You are allowed to **hold only one extra clip at a time**
- If you let go incorrectly, the rest of the chain is lost forever
So before you flip a link:
- You must **remember where the next clip is**
- Then safely reverse the direction
- Then move forward
Reversing a linked list is about **not losing access** while changing directions.
---
## Key Difficulty Introduced by the Twist
Normally, people use **three pointers**:
- `prev`
- `current`
- `next`
But here:
- You are allowed **only one auxiliary pointer**
- This forces careful sequencing of operations
- You must reuse pointers intelligently
This tests **pointer discipline**, not memorization.
---
## Implementation Narrative (English → Code)
### Step 1: Understand the Danger Zone
Each node looks like:
[data | next]
Copy code
When you reverse a link:
current->next = previous
Copy code
If you do this **without saving the original `next`**,  
you permanently lose access to the rest of the list.
That is the core danger.
---
### Step 2: Pointer Roles (Minimal Set)
You will use:
- `current` → traverse


## Test Cases File

```cpp

#include <iostream>
#include "reverse_list.cpp"

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
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper: run one test
void runTest(const initializer_list<int>& values) {
    Node* head = createList(values);

    cout << "Original: ";
    printList(head);

    Node* reversed = reverseList(head);

    cout << "Reversed: ";
    printList(reversed);

    cout << "------------------------\n";
}

int main() {

    // 1. Empty list
    runTest({});

    // 2. Single node
    runTest({10});

    // 3. Two nodes
    runTest({1, 2});

    // 4. Odd number of nodes
    runTest({1, 2, 3, 4, 5});

    // 5. Even number of nodes
    runTest({10, 20, 30, 40});

    // 6. Repeated values
    runTest({5, 5, 5, 5});

    // 7. Negative values
    runTest({-1, -2, -3, -4});

    // 8. Mixed positive and negative
    runTest({-10, 0, 10, 20});

    // 9. Large gap values
    runTest({100, 1000, 10000});

    // 10. Longer list
    runTest({1,2,3,4,5,6,7,8,9,10});

    return 0;
}


```


# Q1: Reverse a Singly Linked List (Pointer-Minimal Version)
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

// Reverse a singly linked list iteratively
// Constraint: only one auxiliary pointer variable (prev) besides traversal pointer
Node* reverseList(Node* head) {
    Node* prev = nullptr;      // only auxiliary pointer
    Node* current = head;      // traversal pointer

    while (current != nullptr) {
        Node* nextNode = current->next; // temporary read (not a stored state)
        current->next = prev;           // reverse link
        prev = current;                 // move prev forward
        current = nextNode;             // move current forward
    }

    return prev; // new head
}
```

## Complexity Recap

Time Complexity: O(N)

Extra Space Complexity: O(1)