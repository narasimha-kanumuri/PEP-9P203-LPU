# LEVEL 4 — DAY 7  

## L4-D7-Q5 — The Financial Audit Anomaly

---

## PART 2
 ---

## Test Cases 

File: test_zero_sum_subarray.cpp

Imports student solution

Validates correctness

Reusable across submissions

Independent of main()

```cpp

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

// Import student function
bool hasZeroSumSubarray(const vector<int>& transactions);

void runTests() {

    // Basic cases
    assert(hasZeroSumSubarray({4, 2, -3, 1, 6}) == true);
    assert(hasZeroSumSubarray({1, 2, 3}) == false);
    assert(hasZeroSumSubarray({1, -1}) == true);
    assert(hasZeroSumSubarray({3, -1, -2, 5}) == true);

    // Edge cases
    assert(hasZeroSumSubarray({}) == false);
    assert(hasZeroSumSubarray({0}) == true);
    assert(hasZeroSumSubarray({5}) == false);

    // Larger mix
    assert(hasZeroSumSubarray({10, -3, 1, -4, 6}) == true);

    cout << "All zero-sum subarray tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}


```

---

# ✅ Full C++ Solution Code (Main Solution File)

> **File:** `zero_sum_subarray.cpp`  
> Contains:
> - Complete O(N) prefix-sum + hashing solution
> - Early termination logic
> - main() runs exactly the sample inputs
> - Function separated for test harness reuse

```cpp

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Purpose:
Determine if there exists a subarray with sum exactly zero.

This function:
- Uses prefix-sum reasoning
- Uses hashing for O(1) lookups
- Supports test harness reuse
*/
bool hasZeroSumSubarray(const vector<int>& transactions) {

    unordered_set<long long> seenSums;
    long long runningSum = 0;

    for (int amount : transactions) {

        runningSum += amount;

        // Case 1: Entire prefix sums to zero
        if (runningSum == 0) {
            return true;
        }

        // Case 2: Running sum seen before
        if (seenSums.find(runningSum) != seenSums.end()) {
            return true;
        }

        seenSums.insert(runningSum);
    }

    return false;
}

int main() {

    vector<int> sample1 = {4, 2, -3, 1, 6};
    cout << "Input: {4, 2, -3, 1, 6}" << endl;
    cout << "Output: "
         << (hasZeroSumSubarray(sample1) ? "true" : "false")
         << endl;

    cout << endl;

    vector<int> sample2 = {1, 2, 3};
    cout << "Input: {1, 2, 3}" << endl;
    cout << "Output: "
         << (hasZeroSumSubarray(sample2) ? "true" : "false")
         << endl;

    return 0;
}

```


## Complete Complexity Analysis

Let N = number of transactions.

⏱️ Time Complexity
Single Pass Traversal

Each element processed once

Hash lookup average O(1)

Insert average O(1)

Total:

O(N)

Best / Average / Worst
Case	Complexity
Best Case	Ω(1) (early zero or repeat found)
Average Case	Θ(N)
Worst Case	O(N)
📦 Space & Auxiliary Space

Hash set stores prefix sums

In worst case, all prefix sums are distinct

Metric	Complexity
Auxiliary Space	O(N)
Total Space	O(N)
📊 Formal Asymptotic Notations

Big-O: O(N)

Big-Ω: Ω(1)

Big-Θ: Θ(N)

little-o: o(N²)

little-ω: ω(1)

🔍 Why This Works

If at indices i and j:

prefixSum[i] == prefixSum[j]


Then:

transactions[i+1 ... j] = 0


We detect this instantly using hashing.

No recomputation of subarray sums.

⚠️ Edge Cases & Annotations

Empty array → false

Single zero element → true

Large values handled via long long

Duplicate prefix sums guarantee zero-sum subarray

Early exit ensures optimal behavior

🧠 Design Pattern Extracted

This problem teaches:

Prefix Sum

Hash-based detection

Cancellation logic

Pattern reuse for:

Count subarrays

Longest subarray

Target sum problems