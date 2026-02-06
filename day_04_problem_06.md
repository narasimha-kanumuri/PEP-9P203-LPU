
# Q6: Detect Cycle Length in a Singly Linked List
## Part 1 — Problem, ELI5, and Implementation Narrative

---

## Problem

Given the **head of a singly linked list**, determine whether the list contains a **cycle**.

### Twist / Constraint
- If a cycle exists, **return the length of the cycle**
- If no cycle exists, return `0`
- You must use:
  - `O(1)` extra space
  - No modification of the list
  - No hash tables or visited markers

---

## Constraints

- Number of nodes: `0 ≤ N ≤ 10^5`
- Singly linked list
- Node values are irrelevant for cycle detection
- List structure must remain unchanged

---

## Examples

### Example 1 (Cycle Exists)
1 → 2 → 3 → 4 → 5 ↑       ↓ ← ← ← ← Output: 3
Copy code

(The cycle contains nodes: 3 → 4 → 5)

---

### Example 2 (No Cycle)
1 → 2 → 3 → 4 → NULL Output: 0
Copy code

---

## ELI5 Explanation

Imagine runners on a circular or straight track.

- One runner walks **slowly**
- Another runner runs **twice as fast**

If the track is straight:
- The fast runner eventually reaches the end

If the track is circular:
- The fast runner will eventually **lap** the slow runner

Once they meet:
- You know a cycle exists
- You can then **measure the size of the loop**

---

## Key Observations

- Linked lists cannot be indexed
- Cycles cannot be detected by value comparison
- Pointer movement speed is the only reliable tool
- Floyd’s Cycle Detection Algorithm is ideal here

---

## Implementation Narrative (English → Code)

### Step 1: Two Pointers with Different Speeds

Use:
- `slow` pointer → moves one node at a time
- `fast` pointer → moves two nodes at a time

Both start at the **head** of the list.

---

### Step 2: Detect Whether a Cycle Exists

Traverse the list while:
- `fast` is not `NULL`
- `fast->next` is not `NULL`

At each step:
- Move `slow` by one node
- Move `fast` by two nodes

If at any point:
slow == fast
Copy code

A cycle is confirmed.

If the loop ends without meeting:
- No cycle exists
- Return `0`

---

### Step 3: Why Meeting Implies a Cycle

- In a non-cyclic list, `fast` always moves ahead and exits
- In a cyclic list, `fast` loops around and eventually catches `slow`
- This is guaranteed due to relative speed difference

---

### Step 4: Finding the Cycle Length (Core Twist)

Once `slow` and `fast` meet:

- Keep one pointer fixed at the meeting point
- Move the other pointer **one step at a time**
- Count the number of steps until it comes back to the same node

That count equals the **cycle length**.

---

### Step 5: Why This Works

- The meeting point is guaranteed to be **inside the cycle**
- Traversing until you return to the same node covers:
  - Exactly one full loop
- No extra memory is required

---

## Edge Case Handling

- Empty list → no cycle → return `0`
- Single node pointing to itself → cycle length = `1`
- Two-node cycle → handled naturally

---

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Extra Space:** `O(1)`

---

## Conceptual Bridges

- Same foundation used in:
  - Finding start of cycle
  - Linked list palindrome (via middle detection)
  - Circular buffer reasoning
- Strengthens:
  - Relative pointer speed thinking
  - Mathematical reasoning on traversal loops


## Test Cases

```cpp

#include <iostream>
#include "cycle_length.cpp"

using namespace std;

// Helper function to create a linked list from array
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

// Helper function to create a cycle
// pos = index where tail connects (0-based), -1 means no cycle
void createCycle(Node* head, int pos) {
    if (pos < 0) return;

    Node* tail = head;
    Node* cycleNode = nullptr;
    int index = 0;

    while (tail->next != nullptr) {
        if (index == pos) cycleNode = tail;
        tail = tail->next;
        index++;
    }

    if (index == pos) cycleNode = tail;

    if (cycleNode != nullptr) {
        tail->next = cycleNode;
    }
}

// Helper to run a test
void runTest(const initializer_list<int>& values, int cyclePos) {
    Node* head = createList(values);
    createCycle(head, cyclePos);

    int len = cycleLength(head);

    cout << "List: ";
    for (int v : values) cout << v << " ";
    cout << "\nCycle Position: " << cyclePos;
    cout << "\nCycle Length: " << len << "\n";
    cout << "--------------------------\n";
}

int main() {

    // 1. Empty list
    runTest({}, -1);

    // 2. Single node, no cycle
    runTest({1}, -1);

    // 3. Single node, self-cycle
    runTest({1}, 0);

    // 4. Two nodes, no cycle
    runTest({1, 2}, -1);

    // 5. Two-node cycle
    runTest({1, 2}, 0);

    // 6. Cycle in the middle
    runTest({1, 2, 3, 4, 5}, 2);

    // 7. Cycle starting at head
    runTest({10, 20, 30, 40}, 0);

    // 8. Long list, small cycle
    runTest({1,2,3,4,5,6,7,8,9,10}, 7);

    // 9. Long list, large cycle
    runTest({5,10,15,20,25,30,35}, 1);

    // 10. Repeated values with cycle
    runTest({7,7,7,7,7}, 2);

    return 0;
}

```




# Q2: Detect Cycle Length in a Singly Linked List  
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

// Returns length of cycle if exists, otherwise returns 0
int cycleLength(Node* head) {
    if (head == nullptr) return 0;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle using Floyd's algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Count cycle length
            int length = 1;
            Node* temp = slow->next;

            while (temp != slow) {
                length++;
                temp = temp->next;
            }
            return length;
        }
    }

    // No cycle
    return 0;
}

```


## Time COmplexity

Time - O(N)
Space - O(1)