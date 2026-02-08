# L4-Q3: Reverse a Singly Linked List Using a Stack — Restore Original List After Printing Reversed Output

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given the head of a **singly linked list**, print the elements of the list in **reverse order** using a **stack**, but after the operation finishes, the linked list must be **exactly the same** as it was before the function call.

Important:

- You are **not allowed** to permanently reverse the list.
- You are **not allowed** to create a new linked list.
- The operation must leave the list **structurally unchanged**.

---

### Constraints (Strict)

- The list is **singly linked**
- **Stack is allowed**
- **No recursion**
- **No list reversal**
- **No new node creation**
- **No modification of node values**
- **List must be restored perfectly**
- Time complexity: **O(N)**
- Space complexity: **O(N)** (stack)
- Pointer safety is mandatory

---

### Examples

#### Example 1

```md
Input:
1 → 2 → 3 → 4

Printed Output:
4 3 2 1

Final List (unchanged):
1 → 2 → 3 → 4
```

---

#### Example 2

```md
Input:
10 → 20

Printed Output:
20 10

Final List:
10 → 20
```

---

### ELI5 (Explain Like I’m 5)

Think of the list as a train.

- You walk through the train once
- You **write down** each wagon number into a stack
- Then you read your notes **backward** and print them
- You never move or detach any wagon

At the end, the train looks exactly the same.

---

### Why This Is a Level 4 Problem

At lower levels:

- Students reverse the list or use recursion

Here:

- Reversal is forbidden
- Recursion is forbidden
- The stack is used **only for observation**, not modification

This tests:

- Understanding of **representation vs structure**
- Discipline in not touching pointers unnecessarily

---

### Core Insight

You do **not** need to modify pointers to print in reverse.

A stack can be used as a **temporary mirror**:

- Push values during traversal
- Pop and print afterward

Since no pointer is changed, restoration is implicit.

---

### High-Level Strategy

1. Traverse the list once
2. Push each node’s data into a stack
3. Pop from stack and print
4. Exit without modifying the list

---

### Deep Implementation Narrative (English → Code Mapping)

---

#### Step 1: Traverse and Push

```md
curr = head
while curr:
    stack.push(curr->data)
    curr = curr->next
```

##### **Invariant**

- Stack contains list values in original order
- List structure untouched

---

#### Step 2: Print in Reverse

```md
while stack not empty:
    print stack.top()
    stack.pop()
```

Values are printed from last to first.

---

#### Step 3: Restoration Guarantee

Because:

- No pointer was changed
- No node was removed or inserted

The list is **automatically restored**.

---

### Invariants Maintained

- Each node visited exactly once
- No `next` pointer modified
- No memory leaks
- Stack emptied cleanly

---

### Common Wrong Approaches (Disallowed)

- Reversing the list and reversing back
- Recursive print
- Modifying `next` pointers
- Creating a new list

---

### Edge Cases Covered

- Empty list → print nothing
- Single node → print one value
- Large list → stack grows, list remains intact

---

### What Will Be Done in Part 2

- Full C++ implementation:
  - `printReverseUsingStack(Node* head)`
- Separate test file
- **10 test cases**, including:
  - empty list
  - single node
  - multi-node lists
  - verification that list remains unchanged

---

## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`print_reverse_using_stack.cpp`)

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
Prints the linked list in reverse order using a stack.
Guarantees:
- List structure remains unchanged
- No pointer modification
- No recursion
*/
void printReverseUsingStack(Node* head) {
    stack<int> st;
    Node* curr = head;

    // Step 1: Traverse and push values
    while (curr) {
        st.push(curr->data);
        curr = curr->next;
    }

    // Step 2: Pop and print
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
    cout << endl;
}
```

---

### Test File (`test_print_reverse_using_stack.cpp`)

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
void printReverseUsingStack(Node* head);

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

    // 1. Empty list
    {
        Node* head = nullptr;
        printReverseUsingStack(head); // Expected: (prints nothing)
    }

    // 2. Single node
    {
        Node* head = buildList({1});
        printReverseUsingStack(head); // Expected: 1
        printList(head);              // Verify unchanged
    }

    // 3. Two nodes
    {
        Node* head = buildList({1, 2});
        printReverseUsingStack(head); // Expected: 2 1
        printList(head);              // Verify unchanged
    }

    // 4. Three nodes
    {
        Node* head = buildList({1, 2, 3});
        printReverseUsingStack(head); // Expected: 3 2 1
        printList(head);
    }

    // 5. Even length list
    {
        Node* head = buildList({10, 20, 30, 40});
        printReverseUsingStack(head); // Expected: 40 30 20 10
        printList(head);
    }

    // 6. Odd length list
    {
        Node* head = buildList({5, 15, 25, 35, 45});
        printReverseUsingStack(head); // Expected: 45 35 25 15 5
        printList(head);
    }

    // 7. Repeated values
    {
        Node* head = buildList({7, 7, 7, 7});
        printReverseUsingStack(head); // Expected: 7 7 7 7
        printList(head);
    }

    // 8. Large list
    {
        Node* head = buildList({1,2,3,4,5,6,7,8,9,10});
        printReverseUsingStack(head); // Expected: 10 9 8 7 6 5 4 3 2 1
        printList(head);
    }

    // 9. List with zero
    {
        Node* head = buildList({0, 1, 0});
        printReverseUsingStack(head); // Expected: 0 1 0
        printList(head);
    }

    // 10. Mixed values
    {
        Node* head = buildList({3, 1, 4, 1, 5});
        printReverseUsingStack(head); // Expected: 5 1 4 1 3
        printList(head);
    }

    return 0;
}
```

---
