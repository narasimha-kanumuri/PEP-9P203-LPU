# LEVEL 4 — DAY 5  


## L4-D5-Q2: Next Warmer Day Forecast (Linked Sensors)  

### PART 2 — Code, Validation, and Complexity
---

## 1️⃣ solution.cpp

> This file contains:

> - Singly linked list definition
> - Core logic to compute next greater values
> - A `main()` function that runs **two sample examples** and prints results
>
> ⚠️ Note:
> The function returns the head of a **new linked list**.
> This return is required for testing and validation.

```cpp

# include <bits/stdc++.h>
using namespace std;
// Definition of singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
/*
  Function: nextGreaterLinkedList
  --------------------------------
  Given the head of a singly linked list,
  returns the head of a new linked list where:
  each node contains the next greater value
  to the right, or 0 if none exists.
  NOTE:
  Return value is REQUIRED for test validation.
*/
Node* nextGreaterLinkedList(Node* head) {
    if (!head) return nullptr;
    // Step 1: Convert linked list values into a vector
    // (Used only for tracking output positions, not logic)
    vector<Node*> nodes;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        nodes.push_back(curr);
    }
    int n = nodes.size();
    vector<int> result(n, 0);  // Default output is 0
    // Step 2: Stack to store indices of unresolved nodes
    stack<int> st;
    // Step 3: Traverse nodes linearly
    for (int i = 0; i < n; i++) {
        int currentValue = nodes[i]->data;
        // Resolve waiting nodes
        while (!st.empty() && nodes[st.top()]->data < currentValue) {
            result[st.top()] = currentValue;
            st.pop();
        }
        // Mark current node as unresolved
        st.push(i);
    }
    // Step 4: Construct output linked list
    Node* dummy = new Node(0);
    Node* tail = dummy;
    for (int i = 0; i < n; i++) {
        tail->next = new Node(result[i]);
        tail = tail->next;

```

## Test case

```cpp

# include <bits/stdc++.h>
using namespace std;
// Must match student definitions
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Import student function
Node* nextGreaterLinkedList(Node* head);
// Helper: convert linked list to vector
vector<int> toVector(Node* head) {
    vector<int> v;
    while (head) {
        v.push_back(head->data);
        head = head->next;
    }
    return v;
}
void runTest(
    const vector<int>& input,
    const vector<int>& expected,
    const string& testName
) {
    // Build input linked list
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int x : input) {
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    Node* resultHead = nextGreaterLinkedList(head);
    vector<int> result = toVector(resultHead);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
        cout << "  Expected: ";
        for (int x : expected) cout << x << " ";
        cout << endl << "  Got     : ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }
}
int main() {
    runTest(
        {2, 1, 5},
        {5, 5, 0},
        "Basic example"
    );
    runTest(
        {2, 7, 4, 3, 5},
        {7, 0, 5, 5, 0},
        "Mixed values"
    );
    runTest(
        {5, 4, 3, 2, 1},
        {0, 0, 0, 0, 0},
        "Strictly decreasing"
    );
    runTest(
        {},
        {},
        "Empty list"
    );
    return 0;
}

```


3️⃣ Complexity Analysis (Formal + Intuitive)
Let N be the number of nodes.
⏱ Time Complexity
Worst Case (Big-O):
O(N)
Each node is pushed to and popped from the stack at most once.
Best Case (Ω):
Ω(N)
Even in increasing order, every node must be processed.
Average Case (Θ):
Θ(N)
Small-o (o):
o(N²)
💾 Space Complexity
Auxiliary Space:
O(N)
Stack + result vector.
Total Space:
O(N)
🔒 Correctness Invariant
At any point in traversal:
Copy code
Values stored in stack are in strictly decreasing order
(from bottom to top)
This guarantees:
Each unresolved node waits only until a greater value appears
No redundant comparisons occur
❗ Why This Is Optimal
Any algorithm must inspect every node → Ω(N)
Nested traversal is forbidden
Stack-based monotonic resolution achieves minimal comparisons