# L3-Q1: Reverse a Singly Linked List in Groups of K (O(K) Extra Space)

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given the head of a **singly linked list**, reverse the list **in groups of size K** and return the modified list.

- Nodes in each group of size `K` must be reversed.
- If the number of nodes remaining is **less than K**, they must remain **as-is**.

---

### Constraints

- The list is **singly linked**.
- `K >= 1`.
- You may use **only O(K) extra space**.
- You must **not modify node values**, only pointers.
- Time complexity must be **O(N)**.
- Pointer safety is mandatory.
- No creation of auxiliary linked lists.
- Groups must be reversed **independently** and then reconnected correctly.

---

### Examples

#### Example 1
```
Input:
List: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
K = 3

Output:
3 → 2 → 1 → 6 → 5 → 4 → 7 → 8
```

---

#### Example 2
```
Input:
List: 1 → 2 → 3 → 4 → 5
K = 2

Output:
2 → 1 → 4 → 3 → 5
```

---

#### Example 3
```
Input:
List: 1 → 2 → 3
K = 4

Output:
1 → 2 → 3
```

---

### ELI5 (Explain Like I’m 5)

Imagine kids standing in a line.

- You take **K kids at a time**
- You ask that group to **turn around**
- Then you move to the next K kids
- If fewer than K kids remain, you **leave them alone**

You never mix groups, and you don’t change who the kids are — only **who points to whom**.

---

### Why This Is a Level 3 Problem

This problem forces you to manage:
- Multiple pointer updates per group
- Group boundaries
- Safe reconnection between reversed and unreversed segments

A single pointer mistake breaks the list.

---

### High-Level Strategy

We process the list **group by group**:

1. Check whether **K nodes exist** ahead
2. Reverse exactly those K nodes
3. Connect:
   - Previous group’s tail → current group’s new head
   - Current group’s tail → next group’s head
4. Repeat until the list ends

---

### Deep Implementation Narrative (English → Code Mapping)

#### Step 1: Count Availability of K Nodes

Before reversing a group:

- Traverse `K` nodes ahead using a temporary pointer
- If fewer than `K` nodes exist:
  - Stop processing
  - Attach the remaining list unchanged

**Why this is critical**  
Prevents partial reversal, which violates the problem constraint.

---

#### Step 2: Reverse Exactly K Nodes

Once confirmed that K nodes exist:

- Use three pointers:
  - `prev` (initially `nullptr`)
  - `curr` (start of the group)
  - `next` (to preserve forward link)

Repeat exactly `K` times:

```cpp

next = curr->next
curr->next = prev
prev = curr
curr = next
```

After this:

- `prev` → new head of the group
- original group head → becomes the group tail

---

#### Step 3: Reconnect the Group

Maintain:

- `prevGroupTail` → tail of previously processed group
- `newGroupHead` → `prev` from reversal
- `newGroupTail` → original head before reversal

Connections:

- If this is the **first group**:
  - Update global `head`
- Else:
  - `prevGroupTail->next = newGroupHead`
- Always:
  - `newGroupTail->next = curr` (start of next segment)

---

#### Step 4: Move to Next Group

- Update `prevGroupTail = newGroupTail`
- Continue from `curr`

---

### Invariants Maintained

- Each node is visited **once**
- Each pointer is reassigned **at most once**
- Groups smaller than K are untouched
- No cycles are introduced
- List integrity is preserved throughout

---

### Space Justification (Why O(K))

- Reversal uses a **constant number of pointers**
- Temporary traversal to verify group size uses at most `K` steps
- No recursion, no arrays, no extra lists

Hence **O(K) auxiliary space**, compliant with constraints.

---

### Common Pitfalls (That This Design Avoids)

- Reversing last partial group
- Losing head reference
- Breaking list between groups
- Incorrect tail reconnection
- Infinite loops due to bad `next` handling

---

### What Will Be Done in Part 2

- Full C++ implementation:
  - `Node` structure
  - `reverseKGroup(Node* head, int k)`
- Separate **test file**
- **10 test cases**, covering:
  - `k = 1`
  - `k > length`
  - exact multiples of `k`
  - remainder groups
  - minimal lists
  - large lists

---


## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`reverse_k_group.cpp`)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

/*
Reverses the linked list in groups of size k.
Constraints honored:
- Singly linked list
- Pointer-only manipulation (no data swap)
- O(N) time, O(K) auxiliary space
*/
Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* prevGroupTail = nullptr;
    Node* newHead = nullptr;

    while (curr) {
        // Step 1: Check if there are at least k nodes ahead
        Node* check = curr;
        int count = 0;
        while (count < k && check) {
            check = check->next;
            count++;
        }
        if (count < k) {
            // Not enough nodes to reverse; attach remainder as-is
            if (prevGroupTail) {
                prevGroupTail->next = curr;
            }
            break;
        }

        // Step 2: Reverse exactly k nodes
        Node* prev = nullptr;
        Node* groupHead = curr; // will become tail after reversal
        count = 0;
        while (count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Reconnect groups
        if (!newHead) {
            newHead = prev; // first group's new head
        }
        if (prevGroupTail) {
            prevGroupTail->next = prev;
        }
        prevGroupTail = groupHead; // tail of current reversed group
    }

    return newHead ? newHead : head;
}
```

---

### Test File (`test_reverse_k_group.cpp`)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

/* --- Declaration from solution file --- */
Node* reverseKGroup(Node* head, int k);

/* ---------- Test Utilities ---------- */

Node* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* ---------- Test Cases ---------- */

int main() {

    // 1. Exact multiple of k
    printList(reverseKGroup(buildList({1,2,3,4,5,6}), 3));
    // Expected: 3 -> 2 -> 1 -> 6 -> 5 -> 4

    // 2. Remainder less than k
    printList(reverseKGroup(buildList({1,2,3,4,5}), 2));
    // Expected: 2 -> 1 -> 4 -> 3 -> 5

    // 3. k = 1 (no change)
    printList(reverseKGroup(buildList({1,2,3,4}), 1));
    // Expected: 1 -> 2 -> 3 -> 4

    // 4. k greater than length
    printList(reverseKGroup(buildList({1,2,3}), 5));
    // Expected: 1 -> 2 -> 3

    // 5. Single node list
    printList(reverseKGroup(buildList({9}), 3));
    // Expected: 9

    // 6. Two nodes, k = 2
    printList(reverseKGroup(buildList({7,8}), 2));
    // Expected: 8 -> 7

    // 7. Two nodes, k = 3
    printList(reverseKGroup(buildList({7,8}), 3));
    // Expected: 7 -> 8

    // 8. Long list with multiple groups
    printList(reverseKGroup(buildList({1,2,3,4,5,6,7,8,9}), 4));
    // Expected: 4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 9

    // 9. k equals list length
    printList(reverseKGroup(buildList({1,2,3,4}), 4));
    // Expected: 4 -> 3 -> 2 -> 1

    // 10. Alternating pattern
    printList(reverseKGroup(buildList({10,20,30,40,50,60,70}), 3));
    // Expected: 30 -> 20 -> 10 -> 60 -> 50 -> 40 -> 70

    return 0;
}
```

---
