# PART 2 — L4-D6-Q3  

## Longest Streak Without Repeated Visitors

---

## Test cases

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 Student solution must provide:
     int longestDistinctSubarrayLength(const vector<int>&);
*/

int longestDistinctSubarrayLength(const vector<int>&);

void runTest(const vector<int>& ids, int expected) {
    int result = longestDistinctSubarrayLength(ids);
    if (result == expected) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected: " << expected
             << " | Got: " << result << "\n";
    }
}

int main() {
    runTest({1, 2, 3, 1, 2, 3, 4}, 4);
    runTest({5, 5, 5, 5}, 1);
    runTest({1, 2, 3, 4, 5}, 5);
    runTest({}, 0);
    runTest({7, 3, 5, 3, 1, 3, 5, 1}, 4);
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
 Returns the length of the longest contiguous subarray
 containing all distinct elements.

 NOTE:
 - The return value is REQUIRED for the test file.
 - Logic is single-pass using a sliding window.
*/
int longestDistinctSubarrayLength(const vector<int>& ids) {
    unordered_map<int, int> lastSeen; // ID -> last index
    int left = 0;                     // Window start
    int maxLen = 0;

    for (int right = 0; right < (int)ids.size(); right++) {
        // If we have seen this ID and it lies inside the current window,
        // move the left boundary just after its previous occurrence.
        if (lastSeen.count(ids[right]) && lastSeen[ids[right]] >= left) {
            left = lastSeen[ids[right]] + 1;
        }

        // Update last seen index of current ID
        lastSeen[ids[right]] = right;

        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen; // <-- Used by test file
}

int main() {
    // Sample Input 1
    vector<int> ids1 = {1, 2, 3, 1, 2, 3, 4};
    cout << "Sample 1 Output: "
         << longestDistinctSubarrayLength(ids1) << "\n";

    // Sample Input 2
    vector<int> ids2 = {5, 5, 5, 5};
    cout << "Sample 2 Output: "
         << longestDistinctSubarrayLength(ids2) << "\n";

    return 0;
}

```

---

## Complete Complexity Analysis
Time Complexity

Let N be the number of wristband IDs.

Big-O (Worst Case):
O(N) — each element is processed once.

Theta (Average Case):
Θ(N) — sliding window with constant-time hash operations.

Omega (Best Case):
Ω(N) — even with all unique elements, full traversal is required.

little-o:
o(N²) — strictly slower than quadratic.

little-omega:
ω(1) — grows beyond constant as input size increases.

Space Complexity

Auxiliary Space:

Hash Map storing last seen indices → O(N) in worst case.

Input Space: O(N)

Total Space: O(N)

Amortized Analysis

Both pointers (left, right) only move forward.

Each index is visited at most twice.

Hash map updates are O(1) amortized.

Edge Cases & Annotations

Empty input → result is 0

All elements same → result is 1

All elements unique → result is array length

Large inputs safely handled due to linear guarantees