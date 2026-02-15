# Q4: Check if a Linked List is a Palindrome (Restore Required)

## Part 1 — Problem, ELI5, and Implementation Narrative

---
## Problem

Given the **head of a singly linked list**, determine whether the list is a **palindrome**.
A linked list is a palindrome if it reads the same **from left to right** and **from right to left**.
### Twist / Constraint

- You must use **O(1) extra space**
- You are **not allowed to use recursion**
- If you modify the list during the process, you **must restore it to its original form** before returning the result
Return `true` if the list is a palindrome, otherwise return `false`.

---

## Constraints

- Number of nodes: `0 ≤ N ≤ 10^5`
- Singly linked list
- Node values are integers
- List structure must be identical after the function finishes

---

## Examples

### Example 1

Input:  1 → 2 → 2 → 1 Output: true


---

### Example 2

Input:  1 → 2 → 3 Output: false


---

## ELI5 Explanation

Imagine writing numbers on a strip of paper.
To check if it reads the same forwards and backwards:

- You look at the **first** number
- Then the **last** number
- Then move inward
But in a linked list:
- You can’t move backward
- You’re only allowed to walk forward

So the trick is:

1. Find the middle of the list
2. Temporarily reverse the second half
3. Compare both halves
4. Reverse the second half again to restore the list

---

## Key Observations

- Linked lists do not support backward traversal
- Extra memory (like stacks or arrays) is forbidden
- Temporary modification is allowed **only if restored**
- Middle-finding logic is reused from earlier problems

---

## Implementation Narrative (English → Code)

### Step 1: Handle Small Lists

- Empty list or single node → always a palindrome
- Return `true` immediately

---

### Step 2: Find the Middle of the List

Use the **slow and fast pointer** technique:

- `slow` moves one node at a time
- `fast` moves two nodes at a time
When `fast` reaches the end:


## Test Cases

```cpp

#include <iostream>
#include "palindrome_list.cpp"

using namespace std;

// Helper: create linked list
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

// Helper: run test
void runTest(const initializer_list<int>& values) {
    Node* head = createList(values);

    cout << "List: ";
    printList(head);

    bool result = isPalindrome(head);
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;

    cout << "List After Check (Restored): ";
    printList(head);

    cout << "---------------------------\n";
}

int main() {

    // 1. Empty list
    runTest({});

    // 2. Single node
    runTest({1});

    // 3. Two nodes palindrome
    runTest({1, 1});

    // 4. Two nodes not palindrome
    runTest({1, 2});

    // 5. Odd length palindrome
    runTest({1, 2, 3, 2, 1});

    // 6. Even length palindrome
    runTest({1, 2, 2, 1});

    // 7. Odd length not palindrome
    runTest({1, 2, 3, 4, 1});

    // 8. Repeated values
    runTest({7, 7, 7, 7});

    // 9. Negative values palindrome
    runTest({-1, -2, -2, -1});

    // 10. Longer list palindrome
    runTest({1,2,3,4,5,4,3,2,1});

    return 0;
}

```

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

// Helper: reverse a linked list and return new head
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Checks if the linked list is a palindrome
// Constraint: O(1) extra space and list must be restored
bool isPalindrome(Node* head) {

    if (head == nullptr || head->next == nullptr)
        return true;

    // Step 1: Find middle using slow & fast pointers
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    // Step 3: Compare both halves
    Node* tempSecond = secondHalf;
    bool palindrome = true;

    while (tempSecond != nullptr) {
        if (firstHalf->data != tempSecond->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // Step 4: Restore the list
    slow->next = reverseList(secondHalf);

    return palindrome;
}