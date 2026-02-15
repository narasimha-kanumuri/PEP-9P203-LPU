# LEVEL 4 — DAY 5  

## L4-D5-Q4: Elevator Emergency Display (with a Twist)  

### PART 2 — Code, Validation, and Complexity

---

## test_solution.cpp

This test file:

Imports the student’s MinStack

Validates behavior, not internal implementation

Can be reused for any student submission

You can replace solution.cpp with student code and re-run.

```cpp

#include <bits/stdc++.h>
using namespace std;

// Import student MinStack
class MinStack {
public:
    void enter(long long x);
    void exit();
    long long getMinimumWeight() const;
    bool empty() const;
};

void runTest(const string& testName, function<void()> testFn) {
    try {
        testFn();
        cout << "[PASS] " << testName << endl;
    } catch (const exception& e) {
        cout << "[FAIL] " << testName << " -> " << e.what() << endl;
    }
}

int main() {
    runTest("Basic minimum tracking", []() {
        MinStack ms;
        ms.enter(5);
        ms.enter(3);
        ms.enter(7);
        if (ms.getMinimumWeight() != 3) throw runtime_error("Wrong min");
        ms.exit();
        if (ms.getMinimumWeight() != 3) throw runtime_error("Wrong min after pop");
        ms.exit();
        if (ms.getMinimumWeight() != 5) throw runtime_error("Wrong restored min");
    });

    runTest("Negative values", []() {
        MinStack ms;
        ms.enter(-2);
        ms.enter(0);
        ms.enter(-3);
        if (ms.getMinimumWeight() != -3) throw runtime_error("Wrong min");
        ms.exit();
        if (ms.getMinimumWeight() != -2) throw runtime_error("Wrong min after restore");
    });

    runTest("Duplicate minimums", []() {
        MinStack ms;
        ms.enter(2);
        ms.enter(2);
        ms.enter(1);
        ms.enter(1);
        if (ms.getMinimumWeight() != 1) throw runtime_error("Wrong min");
        ms.exit();
        if (ms.getMinimumWeight() != 1) throw runtime_error("Wrong min with duplicate");
        ms.exit();
        if (ms.getMinimumWeight() != 2) throw runtime_error("Wrong restored min");
    });

    return 0;
}


```

---

## 1️⃣ solution.cpp

> This file contains:
> - A **single-stack** implementation with **encoded values**
> - O(1) `enter`, `exit`, and `getMinimumWeight`
> - A `main()` that runs **two sample scenarios** and prints outputs
>
> ⚠️ Notes:
> - No auxiliary stack or array is used.
> - Encoding/decoding is clearly commented.
> - Return values (where applicable) are included **only for test validation**.

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  MinStack
  --------
  Stack supporting O(1):
  - enter(x)
  - exit()
  - getMinimumWeight()

  Uses value encoding to avoid auxiliary structures.
*/
class MinStack {
private:
    stack<long long> s;   // single stack
    long long currentMin; // current minimum

public:
    MinStack() {}

    // enter(weight)
    void enter(long long x) {
        if (s.empty()) {
            // First element initializes minimum
            s.push(x);
            currentMin = x;
        } else if (x >= currentMin) {
            // Normal push
            s.push(x);
        } else {
            // Encode value to preserve previous minimum
            // encoded = 2*x - currentMin
            long long encoded = 2 * x - currentMin;
            s.push(encoded);
            currentMin = x;
        }
    }

    // exit()
    void exit() {
        if (s.empty()) {
            throw runtime_error("Exit on empty stack");
        }

        long long topVal = s.top();
        s.pop();

        // If encoded value, restore previous minimum
        if (topVal < currentMin) {
            // previousMin = 2*currentMin - encoded
            currentMin = 2 * currentMin - topVal;
        }
    }

    // getMinimumWeight()
    long long getMinimumWeight() const {
        if (s.empty()) {
            throw runtime_error("Minimum requested from empty stack");
        }
        return currentMin;
    }

    // Utility: check if empty (used for tests/demo)
    bool empty() const {
        return s.empty();
    }
};

int main() {
    cout << "Example 1:" << endl;
    MinStack ms1;
    ms1.enter(5);
    ms1.enter(3);
    ms1.enter(7);
    cout << "Min: " << ms1.getMinimumWeight() << endl; // 3
    ms1.exit();
    cout << "Min after exit: " << ms1.getMinimumWeight() << endl; // 3
    ms1.exit();
    cout << "Min after exit: " << ms1.getMinimumWeight() << endl; // 5

    cout << "\nExample 2:" << endl;
    MinStack ms2;
    ms2.enter(-2);
    ms2.enter(0);
    ms2.enter(-3);
    cout << "Min: " << ms2.getMinimumWeight() << endl; // -3
    ms2.exit();
    cout << "Min after exit: " << ms2.getMinimumWeight() << endl; // -2

    return 0;
}

```

## Complexity Analysis (Formal + Intuitive)

Let N be the number of elements currently in the stack.

⏱ Time Complexity

Worst Case (Big-O):
O(1) for enter, exit, and getMinimumWeight

Best Case (Ω):
Ω(1) for all operations

Average Case (Θ):
Θ(1)

Small-o (o):
o(N)
(Operations do not depend on stack size)

💾 Space Complexity

Auxiliary Space:
O(1)
Only one variable (currentMin) in addition to the stack.

Total Space:
O(N)
(Stack stores N values; no extra structures)

🔒 Correctness Invariant (Formal)

At all times:

currentMin = minimum of all actual values represented in the stack


Encoding guarantees:

If top >= currentMin → top is a real value

If top < currentMin → top is encoded, and previous minimum is:

previousMin = 2*currentMin - encoded


This invariant ensures:

Correct minimum retrieval

Correct restoration after exit()

❗ Why This Is Optimal Under Constraints

Auxiliary stack would violate constraints

Any traversal would violate O(1)

Encoding leverages stack LIFO order to restore state

This is the minimal-space, constant-time solution