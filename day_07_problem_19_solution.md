# LEVEL 4 — DAY 5  

## L4-D5-Q3: Recursive Cargo Reordering (with a Twist)  

### PART 2 — Code, Validation, and Complexity

---

## Test_solution.cpp

This test file:

Imports student’s recursive solution

Validates correctness without re-implementing logic

Can be reused for any student submission

```cpp

# include <bits/stdc++.h>
using namespace std;

// Import student functions
void sortStack(stack<int>& s);

// Helper to convert stack to vector (top to bottom)
vector<int> stackToVector(stack<int> s) {
    vector<int> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

void runTest(
    const vector<int>& input,
    const vector<int>& expected,
    const string& testName
) {
    stack<int> s;
    // Push in reverse so first element is on top
    for (int i = input.size() - 1; i >= 0; i--) {
        s.push(input[i]);
    }

    sortStack(s);

    vector<int> result = stackToVector(s);

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
        {3, 1, 4, 2},
        {1, 2, 3, 4},
        "Basic unsorted stack"
    );

    runTest(
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        "Reverse sorted stack"
    );

    runTest(
        {1, 2, 3},
        {1, 2, 3},
        "Already sorted stack"
    );

    runTest(
        {},
        {},
        "Empty stack"
    );

    return 0;
}



```

---

## 1️⃣ solution.cpp

> This file contains:
>
> - Pure recursive stack sorting (no loops, no extra containers)
> - Clear separation of responsibilities:
>   - `sortStack()` → removes elements recursively
>   - `insertSorted()` → inserts one element into a sorted stack
> - A `main()` that runs **two sample examples** and prints outputs
>
> ⚠️ Notes:
>
> - No loops are used anywhere in the sorting logic.
> - Return values are included **only to help test validation** and are clearly commented.

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  insertSorted
  ------------
  Inserts element x into stack s such that
  the smallest element remains on top.

  Uses recursion only.
*/
void insertSorted(stack<int>& s, int x) {
    // Base case: stack empty or correct position found
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }

    // Remove top and recurse
    int temp = s.top();
    s.pop();

    insertSorted(s, x);

    // Restore removed element
    s.push(temp);
}

/*
  sortStack
  ---------
  Sorts the stack in-place so that
  the smallest element is on top.

  Uses recursion only.
*/
void sortStack(stack<int>& s) {
    // Base case: empty stack
    if (s.empty()) return;

    // Remove top element
    int x = s.top();
    s.pop();

    // Recursively sort remaining stack
    sortStack(s);

    // Insert removed element in sorted order
    insertSorted(s, x);
}

/*
  Utility function to print stack contents
  without modifying logical structure.
*/
void printStack(stack<int> s) {
    cout << "Top -> ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Example 1
    stack<int> s1;
    s1.push(3);
    s1.push(1);
    s1.push(4);
    s1.push(2);

    sortStack(s1);
    cout << "Output (Example 1): ";
    printStack(s1);

    // Example 2
    stack<int> s2;
    s2.push(5);
    s2.push(2);
    s2.push(9);
    s2.push(1);

    sortStack(s2);
    cout << "Output (Example 2): ";
    printStack(s2);

    return 0;
}
```


## Complexity Analysis (Formal + Intuitive)

Let N be the number of elements in the stack.

⏱ Time Complexity

Worst Case (Big-O):
O(N²)
For each element, insertion may traverse the entire stack recursively.

Best Case (Ω):
Ω(N)
If stack is already sorted, each insertion is O(1).

Average Case (Θ):
Θ(N²)

Small-o (o):
o(N³)

💾 Space Complexity

Auxiliary Space (Call Stack):
O(N)
Due to recursive depth.

Extra Data Structures:
O(1)
No arrays, vectors, or helper stacks used.

Total Space:
O(N) (dominated by recursion)

🔒 Correctness Invariant

After each call to sortStack(s):

Stack s is sorted such that
smallest element is always on top


During insertSorted:

All elements below insertion point are ≤ x

All elements above insertion point are ≥ x

This invariant is preserved recursively.