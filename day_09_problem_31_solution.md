# LEVEL 4 — DAY 7  

## L4-D7-Q3 — The Power Grid Restoration Problem

---

## TEst cases

File: test_longest_consecutive.cpp

Imports student solution

Validates correctness

Can be reused for all submissions

Does NOT depend on main()

```cpp
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

// Import student function
int longestConsecutive(const vector<int>& stations);

void runTests() {

    // Basic cases
    assert(longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
    assert(longestConsecutive({10, 5, 6, 7, 1}) == 3);

    // Edge cases
    assert(longestConsecutive({}) == 0);
    assert(longestConsecutive({1}) == 1);

    // Duplicates
    assert(longestConsecutive({1,2,2,3}) == 3);

    // Negative numbers
    assert(longestConsecutive({-1, -2, -3, 5}) == 3);

    // Large gap
    assert(longestConsecutive({1, 1000, 5000}) == 1);

    cout << "All longest consecutive sequence tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}


```

---
# PART 2

---

# ✅ Full C++ Solution Code (Main Solution File)

> **File:** `longest_consecutive_sequence.cpp`  
> Contains:
> - Complete O(N) hashing-based solution
> - Clean separation of logic for test harness reuse
> - `main()` executes exactly the sample inputs from Part 1

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Purpose:
Find the length of the longest consecutive sequence
in an unsorted integer array.

This function is separated so:
- Test file can import and validate it
- main() can demonstrate sample execution
*/
int longestConsecutive(const vector<int>& stations) {
    if (stations.empty()) return 0;

    unordered_set<int> lookup;

    // Insert all elements into hash set (duplicates auto-removed)
    for (int num : stations) {
        lookup.insert(num);
    }

    int maxLength = 0;

    // Traverse each number
    for (int num : lookup) {

        // Check if this is a sequence starting point
        if (lookup.find(num - 1) == lookup.end()) {

            int current = num;
            int length = 1;

            // Expand forward
            while (lookup.find(current + 1) != lookup.end()) {
                current++;
                length++;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {

    vector<int> sample1 = {100, 4, 200, 1, 3, 2};
    cout << "Input: {100, 4, 200, 1, 3, 2}" << endl;
    cout << "Output: " << longestConsecutive(sample1) << endl;

    cout << endl;

    vector<int> sample2 = {10, 5, 6, 7, 1};
    cout << "Input: {10, 5, 6, 7, 1}" << endl;
    cout << "Output: " << longestConsecutive(sample2) << endl;

    return 0;
}
```

## Complete Complexity Analysis

Let N = number of elements in input.

⏱️ Time Complexity
Phase 1 — Insert into Hash Set

Each insertion: O(1) average

Total: O(N)

Phase 2 — Sequence Expansion

Each number is visited at most once in expansion

No number is expanded twice

Total: O(N)

Overall Time Complexity
Case	Complexity
Best Case	Ω(N)
Average Case	Θ(N)
Worst Case	O(N)

Why not O(N²)?
Because we only expand from true sequence starts.

📦 Space & Auxiliary Space Complexity

Hash set stores all unique elements

Metric	Complexity
Auxiliary Space	O(N)
Total Space	O(N)
📊 Formal Asymptotic Notations

Big-O: O(N)

Big-Ω: Ω(N)

Big-Θ: Θ(N)

little-o: o(N log N) (since no sorting used)

little-ω: ω(1)

⚠️ Edge Cases & Annotations

Empty input → return 0

All numbers isolated → return 1

Duplicates automatically removed by hash set

Negative numbers handled naturally

Very large values supported (no sorting)

🔍 Why This Is Truly O(N)

Key invariant:

Each element participates in:

One insertion

At most one expansion chain

No redundant re-expansion.