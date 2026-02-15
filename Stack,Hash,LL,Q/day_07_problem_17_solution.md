<!--
---
marp: true

---
-->

# LEVEL 4 — DAY 5  

## L4-D5-Q1: Live Server Rollback Monitor  

### PART 2 — Code, Validation, and Complexity

---

## 1️⃣ solution.cpp

> This file contains:

> - Complete solution logic
> - A reusable function for validation
> - A `main()` that runs **two sample examples** exactly as described


```cpp
# include <bits/stdc++.h>
using namespace std;

/*
  Function: findFirstInvalidOperation
  ----------------------------------
  Processes operations online and returns:
  - 1-based index of first invalid operation
  - -1 if all operations are valid

  NOTE:
  The return value is REQUIRED for test validation.
*/
int findFirstInvalidOperation(const vector<string>& operations) {
    int activeVersions = 0;  // Represents current deployed versions

    for (int i = 0; i < (int)operations.size(); i++) {
        const string& op = operations[i];

        if (op.find("DEPLOY") == 0) {
            // DEPLOY x → add one version
            activeVersions++;
        } 
        else if (op == "ROLLBACK") {
            // Before rollback, ensure something exists
            if (activeVersions == 0) {
                // Invalid rollback detected
                return i + 1; // 1-based index
            }
            activeVersions--;
        }
    }

    // All operations valid
    return -1;  // Used by test harness
}

int main() {
    // Sample Example 1
    vector<string> ops1 = {
        "DEPLOY 1",
        "DEPLOY 2",
        "ROLLBACK",
        "ROLLBACK"
    };

    cout << "Output (Example 1): "
         << findFirstInvalidOperation(ops1) << endl;

    // Sample Example 2
    vector<string> ops2 = {
        "ROLLBACK",
        "DEPLOY 5"
    };

    cout << "Output (Example 2): "
         << findFirstInvalidOperation(ops2) << endl;

    return 0;
}

```

## test_solution.cpp

```Cpp

# include <bits/stdc++.h>
using namespace std;

// Import student solution
int findFirstInvalidOperation(const vector<string>& operations);

void runTest(
    const vector<string>& ops,
    int expected,
    const string& testName
) {
    int result = findFirstInvalidOperation(ops);

    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got     : " << result << endl;
    }
}

int main() {
    runTest(
        {"DEPLOY 1", "DEPLOY 2", "ROLLBACK"},
        -1,
        "Valid rollback sequence"
    );

    runTest(
        {"ROLLBACK"},
        1,
        "Immediate invalid rollback"
    );

    runTest(
        {"DEPLOY 1", "ROLLBACK", "ROLLBACK"},
        3,
        "Rollback exceeds deploy count"
    );

    runTest(
        {},
        -1,
        "Empty operation list"
    );

    return 0;
}

```

# Part 2: Complexity Analysis (Formal + Intuitive)

Let **$N$** be the total number of operations in the sequence.

## ⏱️ Time Complexity

Every operation is processed exactly once to maintain the integrity of the system state. This linear approach ensures we don't skip critical state transitions.

| Case | Notation | Condition / Reason |
| :--- | :--- | :--- |
| **Best Case** | $\Omega(1)$ | Occurs if the first operation is an invalid `ROLLBACK`. |
| **Average Case** | $\Theta(N)$ | Most real inputs require scanning until the end or near-end. |
| **Small-o** | $o(N^2)$ | Strictly asymptotically smaller than quadratic time. |

## 💾 Space Complexity

- **Auxiliary Space: $O(1)$**
  
  - Only a single integer (`activeVersions`) is used to track the current state, regardless of input size.
- **Total Space: $O(1)$**
  - Excluding the input storage itself, the algorithm's memory footprint remains constant.

---

## 🔒 Correctness Invariant

To ensure the system remains in a valid state, the following condition must hold at every step:
> **activeVersions** $\ge 0$

### Impact of Invariant

- **Validation:** Prevents a `ROLLBACK` from occurring without a prior deployment.
- **Stability:** Guarantees system state validity until a violation is detected.
- **Failure Protocol:** Once broken, correctness is irrecoverable; requires immediate termination to prevent state corruption.

---

## ❗ Why This Is Optimal

1. **Inspection Necessity:** Any valid solution must inspect each operation at least once to ensure the invariant is never violated.
2. **Online Constraint:** The requirement for real-time validation prevents the use of batch processing or deferred validation techniques.
3. **Efficiency:** Consequently, $\Theta(N)$ time is both **necessary and sufficient** for this problem.

---

## End of PART 2
