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

## Complexity Analysis (Formal + Intuitive)

Let N be the number of operations.
⏱ Time Complexity
Worst Case (Big-O):
O(N)
Every operation is processed exactly once.
Best Case (Ω):
Ω(1)
If the first operation is an invalid "ROLLBACK".
Average Case (Θ):
Θ(N)
Most real inputs require scanning until the end or near-end.
Small-o (o):
o(N²)
Strictly asymptotically smaller than quadratic time.
💾 Space Complexity
Auxiliary Space:
O(1)
Only a single integer (activeVersions) is used.
Total Space:
O(1) (excluding input storage)
🔒 Correctness Invariant
At every step:
activeVersions ≥ 0
This invariant ensures:
No rollback happens without a prior deployment
The system state is always valid until a violation is detected
Once broken, correctness is irrecoverable → immediate termination.
❗ Why This Is Optimal
Any solution must inspect each operation at least once
Online constraint prevents batch or deferred validation
Hence Θ(N) time is both necessary and sufficient

## End of PART 2
