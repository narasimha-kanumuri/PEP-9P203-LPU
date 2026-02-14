# PART 2 — L4-D6-Q2  

## Suspicious Repeat Alert Within Limited Distance

---

## Test cases

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 Student solution must provide:
     bool hasNearbyDuplicate(const vector<int>&, int);
*/

bool hasNearbyDuplicate(const vector<int>&, int);

void runTest(const vector<int>& ids, int K, bool expected) {
    bool result = hasNearbyDuplicate(ids, K);
    if (result == expected) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected: "
             << (expected ? "true" : "false")
             << " | Got: "
             << (result ? "true" : "false") << "\n";
    }
}

int main() {
    runTest({10, 20, 30, 10}, 3, true);
    runTest({5, 6, 7, 5}, 2, false);
    runTest({1, 2, 3, 4}, 1, false);
    runTest({1, 2, 1}, 2, true);
    runTest({}, 5, false);
    return 0;
}


```

---

## Full C++ Solution Code (Main Solution File)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 Core function:
 Checks whether any value appears twice within distance <= K.

 NOTE:
 - The boolean return value is REQUIRED for the test file.
 - Early exit is intentional and mandatory.
*/
bool hasNearbyDuplicate(const vector<int>& ids, int K) {
    unordered_set<int> window;  // Tracks last K elements

    for (int i = 0; i < ids.size(); i++) {
        // Step 1: If current ID already in window → alert
        if (window.find(ids[i]) != window.end()) {
            return true;
        }

        // Step 2: Add current ID to window
        window.insert(ids[i]);

        // Step 3: Maintain window size (forget older entries)
        if (i >= K) {
            window.erase(ids[i - K]);
        }
    }
    return false;
}

int main() {
    // Sample Input 1
    vector<int> ids1 = {10, 20, 30, 10};
    int K1 = 3;
    cout << "Sample 1 Output: "
         << (hasNearbyDuplicate(ids1, K1) ? "true" : "false") << "\n";

    // Sample Input 2
    vector<int> ids2 = {5, 6, 7, 5};
    int K2 = 2;
    cout << "Sample 2 Output: "
         << (hasNearbyDuplicate(ids2, K2) ? "true" : "false") << "\n";

    return 0;
}
```

---


## Complete Complexity Analysis
Time Complexity

Let N be the number of badge scans.

Big-O (Worst Case):
O(N) — each element is processed once.

Theta (Average Case):
Θ(N) — hash operations are constant on average.

Omega (Best Case):
Ω(1) — duplicate detected immediately.

little-o:
o(N²) — strictly slower than quadratic growth.

little-omega:
ω(1) — grows beyond constant for large inputs.

Space Complexity

Auxiliary Space:

Hash Set holds at most K elements → O(K)

Worst Case:

If K ≥ N → O(N)

Amortized Analysis

Each element:

Inserted once

Removed once

Hash set operations → O(1) amortized per element

Edge Cases & Annotations

Empty input → always false

K = 0 → no valid distance → always false

Large K values safely handled

Early exit prevents unnecessary work