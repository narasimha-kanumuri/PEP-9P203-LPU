# PART 2 — L4-D6-Q5  

## Inventory Match Report with Quantities

---

## Test cases

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 Student solution must provide:
     vector<int> intersectWithFrequency(const vector<int>&,
                                        const vector<int>&);
*/

vector<int> intersectWithFrequency(const vector<int>&,
                                   const vector<int>&);

bool sameMultiset(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

void runTest(const vector<int>& A,
             const vector<int>& B,
             const vector<int>& expected) {
    vector<int> result = intersectWithFrequency(A, B);
    if (sameMultiset(result, expected)) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected: ";
        for (int x : expected) cout << x << " ";
        cout << "\nGot: ";
        for (int x : result) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    runTest({1, 2, 2, 1}, {2, 2}, {2, 2});
    runTest({4, 9, 5}, {9, 4, 9, 8, 4}, {4, 9});
    runTest({1, 1, 1}, {1, 1}, {1, 1});
    runTest({1, 2, 3}, {4, 5, 6}, {});
    runTest({}, {1, 2}, {});
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
 Returns the intersection of two arrays including duplicate counts.

 NOTE:
 - The returned vector is REQUIRED for the test file.
 - Order of elements in the result does NOT matter.
*/
vector<int> intersectWithFrequency(const vector<int>& A,
                                   const vector<int>& B) {
    unordered_map<int, int> freq;
    vector<int> result;

    // Step 1: Count frequency of elements in A
    for (int x : A) {
        freq[x]++;
    }

    // Step 2: Traverse B and build intersection
    for (int x : B) {
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;  // consume one occurrence
        }
    }
    return result; // <-- Used by test file
}

int main() {
    // Sample Input 1
    vector<int> A1 = {1, 2, 2, 1};
    vector<int> B1 = {2, 2};
    auto out1 = intersectWithFrequency(A1, B1);

    cout << "Sample 1 Output:\n";
    for (int x : out1) cout << x << " ";
    cout << "\n";

    // Sample Input 2
    vector<int> A2 = {4, 9, 5};
    vector<int> B2 = {9, 4, 9, 8, 4};
    auto out2 = intersectWithFrequency(A2, B2);

    cout << "Sample 2 Output:\n";
    for (int x : out2) cout << x << " ";
    cout << "\n";

    return 0;
}


```

## Complete Complexity Analysis
Time Complexity

Let:

N = size of array A

M = size of array B

Big-O (Worst Case):
O(N + M) — one traversal of each array.

Theta (Average Case):
Θ(N + M) — hash operations are constant on average.

Omega (Best Case):
Ω(N) — counting A is mandatory.

little-o:
o((N + M)²) — strictly better than quadratic.

little-omega:
ω(1) — grows beyond constant for non-trivial input.

Space Complexity

Auxiliary Space:

Hash Map storing frequencies → O(N) (worst case)

Result vector → O(min(N, M))

Total Space: O(N + min(N, M))

Amortized Analysis

Each element:

Inserted once into hash map

Looked up once

Possibly decremented once

All hash operations → O(1) amortized

Edge Cases & Annotations

One or both arrays empty → empty result

No common elements → empty result

All elements common → min-frequency preserved

Order does not matter → test validates via multiset comparison