# L4-Q4: Delete Every Node Which Has a Greater Value on Its Right Side (Stack-Based Reasoning)

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given the head of a **singly linked list**, delete every node that has a **node with a greater value anywhere to its right**.

Return the head of the modified list.

---

### Constraints (Strict)

- The list is **singly linked**
- **Stack-based reasoning is mandatory**
- **No nested loops** (no O(N²))
- **O(N)** time complexity required
- **O(N)** auxiliary space allowed (stack)
- **No recursion**
- **No array/vector**
- **Pointer rewiring only** (do not modify node values)
- Must preserve **relative order** of remaining nodes
- Pointer safety and termination correctness are mandatory

---

### Examples

#### Example 1
```
Input:
12 → 15 → 10 → 11 → 5 → 6 → 2 → 3

Output:
15 → 11 → 6 → 3
```

**Explanation**
- 12 is removed because 15 exists on its right
- 10 is removed because 11 exists on its right
- 5 is removed because 6 exists on its right
- 2 is removed because 3 exists on its right

---

#### Example 2
```
Input:
1 → 2 → 3 → 4

Output:
4
```

---

#### Example 3
```
Input:
4 → 3 → 2 → 1

Output:
4 → 3 → 2 → 1
```

---

### ELI5 (Explain Like I’m 5)

Look at each number and ask:

> “Is there **any bigger number** somewhere after me?”

If yes → remove it.  
If no → keep it.

But you can only walk **left to right**, and you are not allowed to look ahead repeatedly.

So instead:
- You **remember important numbers** using a stack
- Smaller numbers get kicked out when a bigger one shows up

---

### Why This Is a Level 4 Problem

At lower levels:
- Students solve this with nested loops or reverse traversal

Here:
- Singly linked list → no backward traversal
- O(N²) forbidden
- Forces **monotonic stack thinking**, usually seen with arrays
- Must adapt that logic to **linked list pointers**

---

### Core Insight

If we traverse from **right to left**, the problem becomes trivial:
- Keep nodes that are **greater than all seen so far**

But singly linked lists cannot traverse backward.

So we simulate **right-to-left reasoning** by:
1. Traversing left-to-right
2. Using a **stack to maintain a decreasing sequence**
3. Rebuilding the list from the stack

---

### High-Level Strategy

We break the solution into **three phases**:

1. Traverse the list and push nodes into a stack while maintaining a **monotonic decreasing invariant**
2. Pop nodes from the stack to reconstruct the filtered list
3. Reverse the reconstructed list to restore original order

---

### Deep Implementation Narrative (English → Code Mapping)

---

#### Phase 1: Monotonic Stack Construction

Traverse the list from left to right.

For each node `curr`:
- While stack is not empty **and**
  ```
  stack.top()->data < curr->data
  ```
  pop the stack

Then:
- Push `curr` onto the stack

**Invariant**
- Stack always contains nodes in **strictly decreasing order**
- Any node popped has found a greater value to its right → must be deleted

---

#### Phase 2: Stack Represents Survivors (But Reversed)

At the end of traversal:
- Stack contains only nodes that **do not have a greater value on their right**
- However, stack order is **reverse of original order**

---

#### Phase 3: Rebuild the List from Stack

Pop nodes from the stack and rebuild the list:
- Each popped node becomes the new head
- Set `node->next` accordingly

This automatically reverses the reversed order → restoring original left-to-right order.

---

### Pointer Discipline (Critical)

While rebuilding:
- Explicitly reset `next` pointers
- Ensure the final node’s `next` is `nullptr`
- Do not leave dangling links from old list

---

### Invariants Maintained

- Each node pushed once, popped at most once → O(N)
- No node value modification
- No extra traversal loops
- Relative order of remaining nodes preserved
- List remains singly linked and cycle-free

---

### Common Wrong Approaches (Disallowed)

- Nested loops (O(N²))
- Reversing list first without stack logic
- Using arrays or vectors
- Modifying node values instead of pointers
- Forgetting to terminate the rebuilt list

---

### Complexity Analysis

- Time: **O(N)**
- Space: **O(N)** (stack of node pointers)

---

### What Will Be Done in Part 2

- Full C++ implementation:
  - `deleteNodesWithGreaterRight(Node* head)`
- Separate test file
- **10 test cases**, including:
  - strictly increasing list
  - strictly decreasing list
  - mixed values
  - duplicates
  - single node
  - large list
  - pointer integrity checks

---


## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`delete_nodes_with_greater_right.cpp`)

```cpp
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

/*
Deletes every node that has a greater value on its right.
Uses monotonic stack reasoning.
Constraints honored:
- Singly linked list
- O(N) time
- O(N) auxiliary space (stack)
- No recursion
- No arrays/vectors
- Pointer rewiring only (no data modification)
*/
Node* deleteNodesWithGreaterRight(Node* head) {
    if (!head || !head->next) return head;

    stack<Node*> st;
    Node* curr = head;

    // Phase 1: Build monotonic decreasing stack
    while (curr) {
        while (!st.empty() && st.top()->data < curr->data) {
            st.pop(); // node must be deleted
        }
        st.push(curr);
        curr = curr->next;
    }

    // Phase 2: Rebuild list from stack (restores correct order)
    Node* newHead = nullptr;
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        node->next = newHead;
        newHead = node;
    }

    return newHead;
}
```

---

### Test File (`test_delete_nodes_with_greater_right.cpp`)

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
Node* deleteNodesWithGreaterRight(Node* head);

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

    // 1. Given example
    printList(deleteNodesWithGreaterRight(
        buildList({12,15,10,11,5,6,2,3})
    ));
    // Expected: 15 -> 11 -> 6 -> 3

    // 2. Strictly increasing
    printList(deleteNodesWithGreaterRight(
        buildList({1,2,3,4})
    ));
    // Expected: 4

    // 3. Strictly decreasing
    printList(deleteNodesWithGreaterRight(
        buildList({4,3,2,1})
    ));
    // Expected: 4 -> 3 -> 2 -> 1

    // 4. Single node
    printList(deleteNodesWithGreaterRight(
        buildList({7})
    ));
    // Expected: 7

    // 5. Two nodes increasing
    printList(deleteNodesWithGreaterRight(
        buildList({5,10})
    ));
    // Expected: 10

    // 6. Two nodes decreasing
    printList(deleteNodesWithGreaterRight(
        buildList({10,5})
    ));
    // Expected: 10 -> 5

    // 7. Repeated values
    printList(deleteNodesWithGreaterRight(
        buildList({5,5,5,5})
    ));
    // Expected: 5 -> 5 -> 5 -> 5

    // 8. Mixed with duplicates
    printList(deleteNodesWithGreaterRight(
        buildList({3,3,2,4,4,1})
    ));
    // Expected: 4 -> 4 -> 1

    // 9. Large list
    printList(deleteNodesWithGreaterRight(
        buildList({9,1,8,2,7,3,6,4,5})
    ));
    // Expected: 9 -> 8 -> 7 -> 6 -> 5

    // 10. Empty list
    printList(deleteNodesWithGreaterRight(nullptr));
    // Expected: (prints nothing)

    return 0;
}
```
