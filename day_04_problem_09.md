# L3-Q6: Add Two Numbers Represented by Singly Linked Lists (Forward Order)

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

You are given two **non-empty singly linked lists** representing two **non-negative integers**.  

- Each node contains a **single digit (0–9)**.
- The digits are stored in **forward order**.

Add the two numbers and return the sum as a **new singly linked list**, also in **forward order**.

---

### Constraints

- Digits are stored **most significant digit first**.
- **Input lists must NOT be modified** (no reversing, no mutation).
- Lengths of the two lists **may differ**.
- Result may have an **extra carry digit** at the front.
- Only **singly linked list operations** are allowed.
- **No array-based digit reconstruction** of the full number.
- Time complexity must be **O(N)**.
- Extra space allowed only if **logically justified** (e.g., recursion stack or explicit stack).
- Pointer safety and correctness are mandatory.

---

### Examples

#### Example 1

```

Input:
L1: 7 → 2 → 4 → 3
L2: 5 → 6 → 4

Output:
7 → 8 → 0 → 7
```

Explanation:
```
7243 + 564 = 7807
```

---

#### Example 2
```
Input:
L1: 9 → 9 → 9
L2: 1

Output:
1 → 0 → 0 → 0
```

---

#### Example 3
```
Input:
L1: 0
L2: 0

Output:
0
```

---

### ELI5 (Explain Like I’m 5)

You are adding two numbers **from left to right**, but addition normally happens **from right to left** (units place first).

Since you are **not allowed to turn the lists around**, you must find a clever way to:
- Reach the **last digits first**
- Add them
- Carry the result back toward the front

Think of it like:
> You can’t walk backward on a bridge, but you can **climb up**, look down, and come back with answers.

---

### Key Insight (Why This Is a Level 3 Problem)

- You **cannot reverse** the input lists.
- You **cannot add directly** from the head.
- Carry propagation goes **backward**, but pointers only go **forward**.

So the core challenge is:
> How do we simulate backward addition on a forward-only structure?

---

### High-Level Strategy

We solve this in **three logical phases**:

1. **Align the lists by length**
2. **Add digits recursively from the tail**
3. **Handle leftover carry at the head**

---

### Deep Implementation Narrative (English → Code Mapping)

#### Step 1: Compute Lengths

- Traverse `L1` and `L2` separately.
- Count the number of nodes in each list.
- Let lengths be `len1` and `len2`.

**Why?**  
To know which list reaches the “units place” later.


**Code Mapping**


- Function: `int getLength(Node* head)`
- Loop until `nullptr`, increment counter.

---

#### Step 2: Recursive Addition Core

We define a recursive function that:

- Moves forward until both lists are aligned at the **same distance from the end**

- Then adds digits **while returning back up the recursion stack

## Part 2: Solution Code + 10 Test Cases

---



### Solution Code (`add_two_numbers_forward.cpp`)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

/* ---------- Utility Functions ---------- */

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

/*
Recursive helper that:
- Processes nodes from most-significant side
- Returns the partial result list
- Updates carry by reference
*/
Node* addSameLength(Node* l1, Node* l2, int& carry) {
    if (!l1 && !l2) {
        carry = 0;
        return nullptr;
    }

    Node* nextNode = addSameLength(l1->next, l2->next, carry);

    int sum = l1->data + l2->data + carry;
    Node* curr = new Node(sum % 10);
    curr->next = nextNode;
    carry = sum / 10;

    return curr;
}

/*
Handles extra leading nodes in the longer list
*/
Node* addRemaining(Node* head, Node* stop, int& carry, Node* result) {
    if (head == stop) {
        return result;
    }

    Node* nextNode = addRemaining(head->next, stop, carry, result);

    int sum = head->data + carry;
    Node* curr = new Node(sum % 10);
    curr->next = nextNode;
    carry = sum / 10;

    return curr;
}

/* ---------- Main API ---------- */

Node* addTwoNumbersForward(Node* l1, Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    if (len2 > len1) {
        swap(l1, l2);
        swap(len1, len2);
    }

    int diff = len1 - len2;
    Node* curr = l1;
    while (diff--) {
        curr = curr->next;
    }

    int carry = 0;
    Node* result = addSameLength(curr, l2, carry);
    result = addRemaining(l1, curr, carry, result);

    if (carry > 0) {
        Node* newHead = new Node(carry);
        newHead->next = result;
        result = newHead;
    }

    return result;
}
```

---

### Test File (`test_add_two_numbers_forward.cpp`)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

/* --- Declarations from solution file --- */
Node* addTwoNumbersForward(Node* l1, Node* l2);

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
    // 1. Equal length, no carry
    printList(addTwoNumbersForward(
        buildList({1,2,3}),
        buildList({4,5,6})
    ));

    // 2. Equal length, full carry propagation
    printList(addTwoNumbersForward(
        buildList({9,9,9}),
        buildList({1,0,1})
    ));

    // 3. Different lengths, no carry
    printList(addTwoNumbersForward(
        buildList({7,2,4,3}),
        buildList({5,6,4})
    ));

    // 4. Different lengths, carry crosses alignment
    printList(addTwoNumbersForward(
        buildList({9,9,9,9}),
        buildList({1})
    ));

    // 5. Single node, no carry
    printList(addTwoNumbersForward(
        buildList({5}),
        buildList({4})
    ));

    // 6. Single node, with carry
    printList(addTwoNumbersForward(
        buildList({9}),
        buildList({9})
    ));

    // 7. One list is zero
    printList(addTwoNumbersForward(
        buildList({0}),
        buildList({7,3,2})
    ));

    // 8. Both lists zero
    printList(addTwoNumbersForward(
        buildList({0}),
        buildList({0})
    ));

    // 9. Long lists with intermittent carries
    printList(addTwoNumbersForward(
        buildList({1,9,2,9,3}),
        buildList({8,0,7,0,6})
    ));

    // 10. Carry creates new head
    printList(addTwoNumbersForward(
        buildList({9,8,7}),
        buildList({2,3,4})
    ));

    return 0;
}
```