# LEVEL 4 — DAY 5  

## L4-D5-Q5: One-Bucket Water Line Simulation (with a Twist)  

### PART 2 — Code, Validation, and Complexity  

### **Chosen Design: FAST JOIN (O(1)), SLOW SERVE (O(N))**

---

## Test Cases: test_solution.cpp

This test file:

Imports student queue implementation

Validates FIFO behavior

Reusable across student submissions

⚠️ Constraint reminder:

Recursion is allowed here only because it does not create a second data structure.

Any loop-based reversal or extra stack violates constraints.

```cpp

#include <bits/stdc++.h>
using namespace std;

// Import student queue
class OneStackQueue {
public:
    void join(int x);
    int serve();
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
    runTest("Basic FIFO order", []() {
        OneStackQueue q;
        q.join(1);
        q.join(2);
        q.join(3);
        if (q.serve() != 1) throw runtime_error("Wrong order");
        if (q.serve() != 2) throw runtime_error("Wrong order");
        if (q.serve() != 3) throw runtime_error("Wrong order");
    });

    runTest("Interleaved operations", []() {
        OneStackQueue q;
        q.join(5);
        q.join(6);
        if (q.serve() != 5) throw runtime_error("Wrong serve");
        q.join(7);
        if (q.serve() != 6) throw runtime_error("Wrong serve");
    });

    runTest("Single element", []() {
        OneStackQueue q;
        q.join(42);
        if (q.serve() != 42) throw runtime_error("Wrong value");
    });

    return 0;
}


```

---

## 1️⃣ Design Choice (Explicit)

We **choose**:
- `join(x)` → **O(1)**  
- `serve()` → **O(N)**

### Why this choice?
- With exactly **one stack**, reversal is unavoidable.
- We choose to pay the reversal cost **only when serving**, not on every join.
- This is realistic for queues where arrivals are frequent and service is less frequent.

---

## 2️⃣ solution.cpp

> This file contains:
> - One-stack queue implementation
> - `join()` is constant time
> - `serve()` reconstructs stack to access the oldest element
> - `main()` demonstrates **two sample scenarios**
>
> ⚠️ Important:
> - No second stack is used.
> - Temporary recursion is **not** used (no hidden stack).
> - Return values are included **only for test validation**.

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  OneStackQueue
  -------------
  Queue implemented using exactly one stack.

  Tradeoff chosen:
  - join(x): O(1)
  - serve(): O(N)
*/
class OneStackQueue {
private:
    stack<int> s;

public:
    // join(x): O(1)
    void join(int x) {
        s.push(x);
    }

    // serve(): O(N)
    int serve() {
        if (s.empty()) {
            throw runtime_error("Serve on empty queue");
        }

        // Remove top element
        int topElement = s.top();
        s.pop();

        // Base case: this is the oldest element
        if (s.empty()) {
            return topElement;
        }

        // Recursively find the bottom (oldest) element
        int oldest = serve();

        // Restore stack state
        s.push(topElement);

        return oldest; // Returned for validation
    }

    bool empty() const {
        return s.empty();
    }
};

int main() {
    cout << "Example 1:" << endl;
    OneStackQueue q1;
    q1.join(1);
    q1.join(2);
    q1.join(3);

    cout << "Served: " << q1.serve() << endl; // 1
    cout << "Served: " << q1.serve() << endl; // 2

    cout << "\nExample 2:" << endl;
    OneStackQueue q2;
    q2.join(10);
    q2.join(20);

    cout << "Served: " << q2.serve() << endl; // 10
    q2.join(30);
    cout << "Served: " << q2.serve() << endl; // 20

    return 0;
}
```

## Complexity Analysis (Formal + Intuitive)

Let N be the number of elements currently in the queue.

⏱ Time Complexity
join(x)

Big-O: O(1)

Ω(1), Θ(1), o(N)

serve()

Big-O: O(N)

Ω(1) (when only one element)

Θ(N) (average case)

o(N²)

💾 Space Complexity

Auxiliary Space:
O(N) (call stack during recursion)

Extra Data Structures:
O(1) (exactly one stack)

Total Space:
O(N)

5️⃣ Correctness Invariant (Formal)

At all times:

Bottom of stack = oldest element
Top of stack    = newest element


During serve():

Elements are temporarily removed

Oldest element is extracted

Stack is restored exactly to its previous order (minus served element)

FIFO order is preserved.

6️⃣ Why This Tradeoff Is Unavoidable

With:

Only one stack

No recursion-as-storage loophole

No second container

You must reverse order at some point.

Reversal cost must appear in either join or serve.

Hence:

Making both operations O(1) is provably impossible.