# L4-Q5: Sort a Stack Using ONLY Recursion and Stack Operations

---

## Part 1: Problem + Constraints + Examples + ELI5 + Deep Implementation Narrative (English → Code)

---

### Problem Statement

Given a **stack of integers**, sort the stack such that the **smallest element is on the top** and the **largest element is at the bottom**.

You must sort the stack using:
- **ONLY recursion**
- **ONLY standard stack operations** (`push`, `pop`, `top`, `empty`)

You are **not allowed** to use:
- Any extra data structures (arrays, vectors, queues, additional stacks)
- Any loops
- Any form of iteration
- Any sorting library

The stack must be sorted **in-place**.

---

### Constraints (Strict)

- Stack contains **0 or more elements**
- **Recursion is mandatory**
- **No loops** (`for`, `while`, etc.)
- **No extra stack or container**
- **Only stack operations allowed**
- Time complexity: **O(N²)** (acceptable and expected)
- Space complexity: **O(N)** (recursion call stack)
- Stack order after sorting:
  - **Top → smallest**
  - **Bottom → largest**

Violating any constraint → solution is invalid.

---

### Examples

#### Example 1
```
Input Stack (top → bottom):
3
1
4
2

Output Stack (top → bottom):
1
2
3
4
```

---

#### Example 2
```
Input:
(empty stack)

Output:
(empty stack)
```

---

#### Example 3
```
Input:
5

Output:
5
```

---

### ELI5 (Explain Like I’m 5)

Imagine a pile of plates (stack).

You want them in order, smallest on top.

Rules:
- You can only take the **top plate**
- You can temporarily hold plates using **memory (recursion)**
- You’re not allowed another table (no extra stack)

So you:
1. Remove plates one by one
2. Put them back in the correct position
3. Keep repeating until sorted

---

### Why This Is a Level 4 Problem

At lower levels:
- Students use another stack or array
- Or apply iterative sorting logic

Here:
- **No iteration**
- **No extra storage**
- You must understand **how recursion simulates iteration + storage**
- Forces precise thinking about **call stack as implicit memory**

---

### Core Insight

The solution is based on **two recursive functions**:

1. `sortStack(stack&)`
   - Sorts the entire stack
2. `insertSorted(stack&, value)`
   - Inserts one element into an already sorted stack

Key idea:
> Remove the top, sort the rest, then insert the removed element back in the correct position.

---

### High-Level Strategy

#### Function 1: `sortStack`

- If stack is empty → return
- Pop top element
- Recursively sort the remaining stack
- Insert popped element back into sorted stack

---

#### Function 2: `insertSorted`

- If stack is empty **OR**
  top element ≤ value:
  - Push value
  - Return
- Else:
  - Pop top
  - Recursively call `insertSorted`
  - Push popped element back

This guarantees sorted order.

---

### Deep Implementation Narrative (English → Code Mapping)

---

#### Step 1: Base Case for Sorting

```
if stack is empty:
    return
```

This stops recursion.

---

#### Step 2: Remove Top Element

```
temp = stack.top()
stack.pop()
```

This element will be inserted later.

---

#### Step 3: Recursive Sort of Remaining Stack

```
sortStack(stack)
```

At this point:
- The stack below is guaranteed to be sorted

---

#### Step 4: Insert Element in Sorted Position

Call:
```
insertSorted(stack, temp)
```

This function:
- Finds the correct position using recursion
- Pushes elements back in correct order

---

### insertSorted Detailed Logic

#### Case 1: Correct Position Found

```
if stack is empty OR stack.top() <= value:
    stack.push(value)
    return
```

---

#### Case 2: Still Not Correct Position

```
temp = stack.top()
stack.pop()
insertSorted(stack, value)
stack.push(temp)
```

This ensures:
- Larger elements move up temporarily
- Value is placed correctly
- Stack order restored above it

---

### Invariants Maintained

- At every return of `sortStack`:
  - Stack is sorted
- At every return of `insertSorted`:
  - Stack remains sorted
- No element is lost or duplicated
- Stack operations strictly follow LIFO

---

### Common Wrong Approaches (Disallowed)

- Using an auxiliary stack
- Using loops
- Sorting via array conversion
- Pushing values back incorrectly (breaking order)
- Forgetting to restore popped elements

---

### Complexity Analysis

- Time: **O(N²)**
  - Each insert may traverse entire stack
- Space: **O(N)**
  - Recursion depth

This is expected and accepted.

---

### What Will Be Done in Part 2

- Full C++ implementation:
  - `sortStack(stack<int>& st)`
  - `insertSorted(stack<int>& st, int value)`
- Separate test file
- **10 test cases**, including:
  - empty stack
  - single element
  - already sorted
  - reverse sorted
  - duplicates
  - negative values
  - large stack

---

## Part 2: Solution Code + 10 Test Cases

---

### Solution Code (`sort_stack_using_recursion.cpp`)

```cpp
#include <iostream>
#include <stack>
using namespace std;

/*
Inserts an element into a sorted stack such that
smallest element remains on top.
Uses ONLY recursion and stack operations.
*/
void insertSorted(stack<int>& st, int value) {
    // Base case: correct position found
    if (st.empty() || st.top() <= value) {
        st.push(value);
        return;
    }

    // Remove top and recurse
    int temp = st.top();
    st.pop();
    insertSorted(st, value);

    // Restore removed element
    st.push(temp);
}

/*
Sorts a stack using ONLY recursion.
No loops, no extra data structures.
*/
void sortStack(stack<int>& st) {
    // Base case
    if (st.empty()) {
        return;
    }

    // Remove top element
    int temp = st.top();
    st.pop();

    // Sort remaining stack
    sortStack(st);

    // Insert removed element in sorted order
    insertSorted(st, temp);
}
```

---

### Test File (`test_sort_stack_using_recursion.cpp`)

```cpp
#include <iostream>
#include <stack>
using namespace std;

/* --- Declarations from solution file --- */
void sortStack(stack<int>& st);

/* ---------- Test Utilities ---------- */

void printStack(stack<int> st) {
    // Print without modifying original stack
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
    cout << endl;
}

/* ---------- Test Cases ---------- */

int main() {

    // 1. Empty stack
    {
        stack<int> st;
        sortStack(st);
        printStack(st); // Expected: (prints nothing)
    }

    // 2. Single element
    {
        stack<int> st;
        st.push(5);
        sortStack(st);
        printStack(st); // Expected: 5
    }

    // 3. Already sorted stack
    {
        stack<int> st;
        st.push(4);
        st.push(3);
        st.push(2);
        st.push(1); // top = 1
        sortStack(st);
        printStack(st); // Expected: 1 2 3 4
    }

    // 4. Reverse sorted stack
    {
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4); // top = 4
        sortStack(st);
        printStack(st); // Expected: 1 2 3 4
    }

    // 5. Random order
    {
        stack<int> st;
        st.push(2);
        st.push(4);
        st.push(1);
        st.push(3);
        sortStack(st);
        printStack(st); // Expected: 1 2 3 4
    }

    // 6. With duplicates
    {
        stack<int> st;
        st.push(3);
        st.push(1);
        st.push(2);
        st.push(2);
        sortStack(st);
        printStack(st); // Expected: 1 2 2 3
    }

    // 7. Negative numbers
    {
        stack<int> st;
        st.push(-1);
        st.push(3);
        st.push(-5);
        st.push(2);
        sortStack(st);
        printStack(st); // Expected: -5 -1 2 3
    }

    // 8. All elements same
    {
        stack<int> st;
        st.push(7);
        st.push(7);
        st.push(7);
        sortStack(st);
        printStack(st); // Expected: 7 7 7
    }

    // 9. Large stack
    {
        stack<int> st;
        for (int i = 10; i >= 1; i--) {
            st.push(i);
        }
        sortStack(st);
        printStack(st); // Expected: 1 2 3 4 5 6 7 8 9 10
    }

    // 10. Mixed values
    {
        stack<int> st;
        st.push(0);
        st.push(5);
        st.push(-2);
        st.push(8);
        st.push(1);
        sortStack(st);
        printStack(st); // Expected: -2 0 1 5 8
    }

    return 0;
}
```

---
