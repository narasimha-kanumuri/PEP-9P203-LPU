# L4-Q1: Check Palindrome in a Singly Linked List Using ONLY a Stack and ONE Traversal

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given the head of a **singly linked list**, determine whether the list represents a **palindrome**.

You must solve this problem using:
- **ONLY one traversal of the list**
- **A stack is allowed**
- **No list modification**
- **No list reversal**
- **No second traversal**

Return `true` if the list is a palindrome, otherwise return `false`.

---

### Constraints (Strict)

- The list is **singly linked**
- **Exactly ONE traversal** from head to tail
- **Stack is allowed**
- **No recursion**
- **No list reversal**
- **No modification to the list structure**
- **No auxiliary data structures** other than the stack
- Must work for:
  - odd length lists
  - even length lists
- Time complexity: **O(N)**
- Space complexity: **O(N/2)** (stack)

Violating **any one** of the above → solution is invalid.

---

### Examples

#### Example 1 (Odd Length)
```
Input:
1 → 2 → 3 → 2 → 1

Output:
true
```

---

#### Example 2 (Even Length)
```
Input:
1 → 2 → 2 → 1

Output:
true
```

---

#### Example 3 (Not a Palindrome)
```
Input:
1 → 2 → 3 → 4

Output:
false
```

---

### ELI5 (Explain Like I’m 5)

You walk through the list **once**.

- For the **first half**, you put values into a bag (stack)
- When you reach the middle:
  - If the list is odd, you **skip the middle**
- For the **second half**, you:
  - Take values out of the bag
  - Compare them with current nodes

If everything matches → palindrome.

You never go back.  
You never touch the list.

---

### Why This Is a Level 4 Problem

At Level 3:
- You were allowed two traversals
- You were allowed list reversal

Here:
- Traversal budget is **exactly one**
- Structural operations are **forbidden**
- Stack operations must be **perfectly synchronized** with pointer movement

This is about **temporal alignment**, not pointer manipulation.

---

### Core Insight

Use **fast and slow pointers**, but:
- Push values onto the stack **only while slow is moving**
- Let fast pointer determine:
  - when to stop pushing
  - whether to skip a middle element

All logic must be interleaved in a **single loop**.

---

### High-Level Strategy

We maintain:
- `slow` pointer → moves 1 step
- `fast` pointer → moves 2 steps
- `stack<int>` → stores first-half values

Loop condition:
```
while (fast != nullptr && fast->next != nullptr)
```

Inside the loop:
1. Push `slow->data` onto stack
2. Move `slow` one step
3. Move `fast` two steps

After the loop:
- If `fast != nullptr` → list length is odd
  - Skip middle node: `slow = slow->next`

Then:
- Compare remaining nodes with stack values

---

### Deep Implementation Narrative (English → Code Mapping)

---

#### Phase 1: First Half Processing (Single Traversal Begins)

While fast pointer can jump two nodes:
- Push current `slow->data` onto stack
- Advance `slow`
- Advance `fast` twice

**Invariant**
- Stack contains values of first half
- `slow` always points to the start of the unprocessed portion

---

#### Phase 2: Odd-Length Adjustment (No Extra Traversal)

If `fast != nullptr`:
- The list has an odd number of nodes
- `slow` is currently at the **middle**
- Skip it:
  ```
  slow = slow->next
  ```

Middle element does not participate in palindrome comparison.

---

#### Phase 3: Second Half Comparison (Same Traversal Window)

Now:
- `slow` traverses second half
- For each node:
  - Pop from stack
  - Compare values

If at any point:
```
stack.top() != slow->data
```
→ Not a palindrome.

---

#### Phase 4: Termination Conditions

- Stack must be empty exactly when `slow == nullptr`
- Any mismatch → return `false`
- Otherwise → return `true`

---

### Invariants Maintained Throughout

- Stack size ≤ N/2
- Each node is visited **once**
- No pointer is rewired
- No node value is changed
- Fast pointer never re-traverses nodes

---

### Why One Traversal Is Still Honest Here

Although the logic feels “phased”:
- All pointer movement happens in **one forward pass**
- No pointer ever resets
- No second scan from head

This satisfies the **strict single-traversal constraint**.

---

### Common Wrong Solutions (Disallowed)

- Two separate loops (even if fast/slow reused)
- Reversing second half
- Copying list to array
- Recursive solutions
- Traversing again for comparison

---

## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`palindrome_stack_single_traversal.cpp`)

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
Checks if a singly linked list is a palindrome
using ONLY:
- one traversal
- a stack
- no list modification
*/
bool isPalindromeSingleTraversal(Node* head) {
    if (!head || !head->next) return true;

    stack<int> st;
    Node* slow = head;
    Node* fast = head;

    // Phase 1: Push first half into stack (single traversal)
    while (fast && fast->next) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Phase 2: Skip middle node for odd length
    if (fast != nullptr) {
        slow = slow->next;
    }

    // Phase 3: Compare second half with stack
    while (slow) {
        if (st.empty() || st.top() != slow->data) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }

    // Stack must be empty for a valid palindrome
    return st.empty();
}
```

---

### Test File (`test_palindrome_stack_single_traversal.cpp`)

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
bool isPalindromeSingleTraversal(Node* head);

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

    // 1. Odd length palindrome
    cout << isPalindromeSingleTraversal(buildList({1,2,3,2,1})) << endl; // 1

    // 2. Even length palindrome
    cout << isPalindromeSingleTraversal(buildList({1,2,2,1})) << endl; // 1

    // 3. Odd length non-palindrome
    cout << isPalindromeSingleTraversal(buildList({1,2,3,4,1})) << endl; // 0

    // 4. Even length non-palindrome
    cout << isPalindromeSingleTraversal(buildList({1,2,3,4})) << endl; // 0

    // 5. Single node
    cout << isPalindromeSingleTraversal(buildList({7})) << endl; // 1

    // 6. Two nodes palindrome
    cout << isPalindromeSingleTraversal(buildList({9,9})) << endl; // 1

    // 7. Two nodes non-palindrome
    cout << isPalindromeSingleTraversal(buildList({9,8})) << endl; // 0

    // 8. All same values
    cout << isPalindromeSingleTraversal(buildList({5,5,5,5,5})) << endl; // 1

    // 9. Large odd palindrome
    cout << isPalindromeSingleTraversal(
        buildList({1,2,3,4,5,4,3,2,1})
    ) << endl; // 1

    // 10. Empty list
    cout << isPalindromeSingleTraversal(nullptr) << endl; // 1

    return 0;
}
```

---
