# L3-Q7: Delete a Given Node in O(1) Time in a Doubly Linked List

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

You are given:
- A **pointer to a node** in a **doubly linked list**
- The list has **at least two nodes**

Delete the given node in **O(1) time**.

You are **not given the head pointer** of the list.

---

### Constraints

- The node to be deleted is **guaranteed not to be NULL**
- The node to be deleted is **not the last node**
- You are given **direct access only to the node**, not the head
- The list is a **doubly linked list**
- Time complexity must be **O(1)**
- No traversal from head is allowed
- Pointer safety is mandatory
- The list must remain **structurally correct** after deletion

---

### Examples

#### Example 1
```
Before:
10 <-> 20 <-> 30 <-> 40

Given node: 30

After:
10 <-> 20 <-> 40
```

---

#### Example 2
```
Before:
5 <-> 15

Given node: 5

After:
15
```

---

### ELI5 (Explain Like I’m 5)

You are standing **on the node to be deleted**, but you **don’t know where the list starts**.

Instead of walking to the front:
- You **copy the next node’s value into this node**
- Then you **remove the next node**

It’s like:
> Erasing a word in the middle of a sentence by copying the next word over it.

---

### Key Insight (Why This Works)

In a **doubly linked list**, each node has:
- A `prev` pointer
- A `next` pointer

If the given node is **not the last node**, then:
- Its `next` node exists
- We can safely **steal its data and bypass it**

---

### High-Level Strategy

1. Let `curr` be the given node
2. Let `nextNode = curr->next`
3. Copy `nextNode->data` into `curr->data`
4. Redirect pointers:
   - `curr->next = nextNode->next`
   - If `nextNode->next` exists:
     - Update its `prev` pointer
5. Free `nextNode`

All steps take **constant time**.

---

### Deep Implementation Narrative (English → Code Mapping)

#### Step 1: Preconditions Check

- Given node must:
  - Not be `NULL`
  - Not be the last node (`node->next != NULL`)

These are assumed true as per constraints.

---

#### Step 2: Identify the Next Node

- Store `node->next` in a temporary pointer
- This is the node that will actually be removed

**Code Mapping**
- `Node* temp = node->next;`

---

#### Step 3: Copy Data Forward

- Assign:
  ```
  node->data = temp->data
  ```
- This logically deletes the original node’s value

---

#### Step 4: Rewire `next` Pointer

- Point current node’s `next` to:
  ```
  temp->next
  ```

---

#### Step 5: Fix Backward Link (Critical Invariant)

If `temp->next` exists:
- Update:
  ```
  temp->next->prev = node
  ```

This maintains **bidirectional integrity**.

---

#### Step 6: Delete the Extra Node

- Free `temp`
- No dangling pointers remain
- The list is still valid

---

### Invariants Maintained

- List remains fully doubly linked
- No memory leaks
- No traversal performed
- Exactly one node removed
- Operation completes in **O(1)** time

---

### Why Singly Linked List Cannot Do This

Without a `prev` pointer:
- You cannot safely update the previous node
- Hence O(1) deletion without head is impossible

This is **exactly why doubly linked lists are introduced before trees**.

---

### What Will Be Done in Part 2

- C++ implementation of:
  - Doubly linked list node
  - `deleteGivenNode(Node* node)` function
- Separate test file
- **10 test cases**, including:
  - Deleting middle node
  - Deleting first logical node
  - Minimal list
  - Pointer integrity checks

---

## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`delete_given_node_dll.cpp`)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

/*
Deletes a given node from a doubly linked list in O(1) time.
Preconditions (guaranteed by problem constraints):
- node != nullptr
- node->next != nullptr (node is not the last node)
*/
void deleteGivenNode(Node* node) {
    Node* temp = node->next;

    // Copy next node's data into current node
    node->data = temp->data;

    // Bypass the next node
    node->next = temp->next;

    // Fix backward link if needed
    if (temp->next != nullptr) {
        temp->next->prev = node;
    }

    // Delete the bypassed node
    delete temp;
}
```

---

### Test File (`test_delete_given_node_dll.cpp`)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

/* --- Declaration from solution file --- */
void deleteGivenNode(Node* node);

/* ---------- Test Utilities ---------- */

Node* buildDLL(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    Node* head = new Node(vals[0]);
    Node* curr = head;

    for (size_t i = 1; i < vals.size(); i++) {
        Node* n = new Node(vals[i]);
        curr->next = n;
        n->prev = curr;
        curr = n;
    }
    return head;
}

void printDLL(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}

Node* getNodeAt(Node* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}

/* ---------- Test Cases ---------- */

int main() {

    // 1. Delete middle node
    {
        Node* head = buildDLL({10, 20, 30, 40});
        deleteGivenNode(getNodeAt(head, 2)); // delete logical 30
        printDLL(head); // expected: 10 <-> 20 <-> 40
    }

    // 2. Delete first node (head pointer not updated, logical delete)
    {
        Node* head = buildDLL({5, 15, 25});
        deleteGivenNode(head); // delete logical 5
        printDLL(head); // expected: 15 <-> 25
    }

    // 3. Delete node in 2-element list (delete first)
    {
        Node* head = buildDLL({1, 2});
        deleteGivenNode(head);
        printDLL(head); // expected: 2
    }

    // 4. Delete node just before last
    {
        Node* head = buildDLL({7, 8, 9, 10});
        deleteGivenNode(getNodeAt(head, 2)); // delete logical 9
        printDLL(head); // expected: 7 <-> 8 <-> 10
    }

    // 5. Delete second node
    {
        Node* head = buildDLL({100, 200, 300});
        deleteGivenNode(getNodeAt(head, 1)); // delete logical 200
        printDLL(head); // expected: 100 <-> 300
    }

    // 6. Multiple deletions sequentially
    {
        Node* head = buildDLL({1, 2, 3, 4, 5});
        deleteGivenNode(getNodeAt(head, 1)); // delete 2
        deleteGivenNode(getNodeAt(head, 2)); // delete logical 4
        printDLL(head); // expected: 1 <-> 3 <-> 5
    }

    // 7. Check backward pointer integrity
    {
        Node* head = buildDLL({9, 8, 7});
        deleteGivenNode(getNodeAt(head, 1)); // delete 8
        printDLL(head); // expected: 9 <-> 7
        if (head->next && head->next->prev == head)
            cout << "Backward link OK\n";
    }

    // 8. Large values
    {
        Node* head = buildDLL({1000, 2000, 3000, 4000});
        deleteGivenNode(getNodeAt(head, 1)); // delete 2000
        printDLL(head); // expected: 1000 <-> 3000 <-> 4000
    }

    // 9. Repeated value nodes
    {
        Node* head = buildDLL({5, 5, 5, 5});
        deleteGivenNode(getNodeAt(head, 1));
        printDLL(head); // expected: 5 <-> 5 <-> 5
    }

    // 10. Minimal valid list (2 nodes)
    {
        Node* head = buildDLL({42, 99});
        deleteGivenNode(head);
        printDLL(head); // expected: 99
    }

    return 0;
}
```

---
