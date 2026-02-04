<!--
marp: true
-->

# Program 4: Merge Two Sorted Singly Linked Lists (In-Place)

---

## Problem

You are given the heads of **two sorted singly linked lists**.

Your task is to **merge them into one sorted linked list** by **rearranging pointers only**.

❌ You must **not create new data nodes**  
✅ You may only change `next` pointers

Return the head of the merged sorted list.

---

## Constraints

- Each linked list is sorted in non-decreasing order
- Number of nodes in each list: `0 ≤ N ≤ 10^5`
- Node values are integers
- Only `O(1)` extra space allowed

---

## Examples

### Example 1
**Input**
List A: 1 → 3 → 5 List B: 2 → 4 → 6
Copy code

**Output**
1 → 2 → 3 → 4 → 5 → 6
Copy code

---

### Example 2
**Input**
List A: 1 → 2 → 4 List B: 1 → 3 → 4
Copy code

**Output**
1 → 1 → 2 → 3 → 4 → 4
Copy code

---

### Example 3
**Input**
List A: NULL List B: 0 → 5
Copy code

**Output**
0 → 5
Copy code

---

## ELI5 Explanation

Imagine you have **two sorted queues of cards** lying on a table.

- You always look at the **front card** of both queues
- You pick the **smaller card**
- You attach it to a new growing line
- Then you move forward only in the list you picked from

You keep doing this until one queue becomes empty.

Then you attach **all remaining cards** from the other queue.

No new cards are created — you only **relink them**.

---

## Key Observations

- Both lists are already sorted
- You only need to compare **current nodes**
- Pointer redirection is enough
- Order is preserved automatically

---

## Implementation Narrative (English → Code)

### Step 1: Handle Edge Cases

- If List A is empty → return List B
- If List B is empty → return List A

---

### Step 2: Dummy Node Technique

- Create a **dummy node**
- This node does NOT hold meaningful data
- It simplifies handling the head of the merged list

You maintain:
- `tail` → last node of the merged list

---

### Step 3: Initialize Pointers

- `p1` → head of List A
- `p2` → head of List B
- `tail` → dummy node

---

### Step 4: Merge While Both Lists Are Non-Empty

While both pointers are not NULL:

- Compare `p1->data` and `p2->data`
- Attach the smaller node to `tail->next`
- Move:
  - `tail` forward
  - The pointer (`p1` or `p2`) from which the node was taken

---

### Step 5: Attach Remaining Nodes

After the loop:
- One list may still have nodes left
- Attach the remaining nodes directly
- No comparisons needed

---

### Step 6: Return Result

- The merged list starts from `dummy->next`
- The dummy node itself is skipped

---

## Why This Works

- Each node is visited exactly once
- No new nodes are created
- Sorting is preserved
- Pointer manipulation is clean and safe

---

## Complexity Analysis

- **Time Complexity:** `O(N + M)`
- **Extra Space:** `O(1)`

---

## Conceptual Bridges

- This logic is the foundation for:
  - Merge Sort on Linked Lists
  - External sorting
  - Stable merges in algorithms
- Reinforces:
  - Pointer reassignment
  - Multiple traversal pointers
  - Dummy node pattern


# Program 4: Merge Two Sorted Singly Linked Lists  
## Part 2 — Solution Code and Test Cases

---

## Solution Code (C++)

```cpp

#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Merges two sorted linked lists in-place
// Returns head of merged sorted list
Node* mergeSortedLists(Node* head1, Node* head2) {

    // Edge cases
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    // Dummy node to simplify head handling
    Node dummy(0);
    Node* tail = &dummy;

    Node* p1 = head1;
    Node* p2 = head2;

    // Merge while both lists have nodes
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data <= p2->data) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (p1 != nullptr) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    return dummy.next;
}
```


## Test Cases(cpp)

```cpp

#include <iostream>
#include "merge_sorted_lists.cpp"

using namespace std;

// Helper function to create a linked list from initializer list
Node* createList(const initializer_list<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : values) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to run a test
void runTest(const initializer_list<int>& a,
             const initializer_list<int>& b) {

    Node* listA = createList(a);
    Node* listB = createList(b);

    cout << "List A: ";
    printList(listA);

    cout << "List B: ";
    printList(listB);

    Node* merged = mergeSortedLists(listA, listB);

    cout << "Merged: ";
    printList(merged);
    cout << "----------------------\n";
}

int main() {

    // 1. Both lists empty
    runTest({}, {});

    // 2. First list empty
    runTest({}, {1, 2, 3});

    // 3. Second list empty
    runTest({4, 5, 6}, {});

    // 4. Equal length lists
    runTest({1, 3, 5}, {2, 4, 6});

    // 5. Unequal lengths
    runTest({1, 2}, {3, 4, 5, 6});

    // 6. Lists with duplicate values
    runTest({1, 3, 5}, {1, 3, 5});

    // 7. Interleaved values
    runTest({1, 4, 7}, {2, 3, 5, 6});

    // 8. Negative and positive values
    runTest({-10, -5, 0}, {-6, -3, 2, 8});

    // 9. One list much larger
    runTest({1}, {2, 3, 4, 5, 6, 7});

    // 10. Already fully ordered
    runTest({1, 2, 3}, {4, 5, 6});

    return 0;
}

```

## Notes for Students

No new data nodes are created during merge
Only next pointers are reassigned
Observe how the dummy node simplifies logic
Try removing the dummy node and handling head manually