# 2️⃣ solution.md — Execution Artifacts

## 🔖 Header

**Concepts Used:** Prefix Sums, Hash Maps (`std::unordered_map`), Frequency Counting, Space-Time Tradeoff

---

## A. Test cases File

```cpp

#include <iostream>
#include <vector>
#include <cassert>

void runTests() {
    std::cout << "Running Power Surge Tests..." << std::endl;

    // --- 1. Normal Case (Mixed Positive/Negative) ---
    // Usage: [1, 1, 1], K=2 -> [1,1] at index (0,1) and (1,2)
    std::vector<int> case1 = {1, 1, 1};
    int res1 = PowerSurgeMonitor::countValidWindows(3, case1, 2);
    assert(res1 == 2);
    std::cout << "[PASS] Normal Case: Simple positive integers." << std::endl;

    // --- 2. Edge Case (Negative Numbers) ---
    // Usage: [1, 2, 3], K=3 -> [1,2] and [3]
    std::vector<int> case2 = {1, 2, 3};
    int res2 = PowerSurgeMonitor::countValidWindows(3, case2, 3);
    assert(res2 == 2);
    std::cout << "[PASS] Edge Case: Target K exists as single element and subarray." << std::endl;

    // --- 3. Edge Case (Target 0 with negatives) ---
    // Usage: [1, -1, 1, -1], K=0 -> [1,-1], [-1,1], [1,-1], [1,-1,1,-1]
    std::vector<int> case3 = {1, -1, 1, -1};
    int res3 = PowerSurgeMonitor::countValidWindows(4, case3, 0);
    assert(res3 == 4);
    std::cout << "[PASS] Edge Case: Target 0 with cancelling pairs." << std::endl;

    // --- 4. Logic Trap (Prefix Sum 0 initialization) ---
    // Usage: [3, 4], K=3. Needs prefixHistory[0]=1 to catch the first '3'.
    std::vector<int> case4 = {3, 4};
    int res4 = PowerSurgeMonitor::countValidWindows(2, case4, 3);
    assert(res4 == 1);
    std::cout << "[PASS] Logic Trap: Subarray starting at index 0 detected." << std::endl;

    // --- 5. Stress Case (Large N, all zeros) ---
    // Usage: [0, 0, 0...], K=0.
    // N=1000 zeros. Result is N*(N+1)/2 = 500500.
    int stressN = 1000;
    std::vector<int> zeros(stressN, 0);
    int resStress = PowerSurgeMonitor::countValidWindows(stressN, zeros, 0);
    assert(resStress == (stressN * (stressN + 1)) / 2);
    std::cout << "[PASS] Stress Case: N=1000 zeros handled correctly." << std::endl;

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    runTests();
    return 0;
}

```

---

## B. Complete Solution Code

```cpp
/**
 * Solution for "The Power Surge Windows" (Subarray Sum Equals K)
 * Implements the Prefix Sum + Hash Map optimization to solve in O(N).
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class PowerSurgeMonitor {
public:
    /**
     * Counts the total number of continuous subarrays whose elements sum to k.
     *
     * @param n The number of log entries.
     * @param usage The vector of energy usage logs (can be negative).
     * @param k The target energy sum.
     * @return The count of valid subarrays.
     */
    static int countValidWindows(int n, const std::vector<int>& usage, int k) {
        // Map stores <PrefixSum, Frequency>
        // Use unordered_map for O(1) average lookup time
        std::unordered_map<int, int> prefixHistory;

        int currentSum = 0;
        int count = 0;

        // Base Case: A prefix sum of 0 exists effectively at index -1 (empty subarray).
        // This handles subarrays that start from index 0 ending at current index.
        prefixHistory[0] = 1;

        for (int x : usage) {
            currentSum += x;

            // Derived logic: If (CurrentSum - OldSum) = k, then (CurrentSum - k) = OldSum
            int neededOldSum = currentSum - k;

            // If we have seen this neededOldSum before, add its frequency to count
            if (prefixHistory.find(neededOldSum) != prefixHistory.end()) {
                count += prefixHistory[neededOldSum];
            }

            // Record the current prefix sum for future iterations
            prefixHistory[currentSum]++;
        }

        return count;
    }
};

```

---

# 2️⃣ solution.md — Execution Artifacts (Section C)

> **🔖 Header**
> **Topic:** Prefix Sum & Hash Map Performance Analysis

---

## C. Complexity Analysis



### 1. Time Complexity

| Case | Complexity | Reasoning |
| :--- | :--- | :--- |
| **Best Case** | $O(N)$ | The algorithm iterates through the array exactly once, performing constant-time lookups at each step. |
| **Average Case** | $O(N)$ | Map insertions and lookups (`std::unordered_map`) take $O(1)$ amortized time. Even with large inputs, the one-pass nature ensures linear scaling. |
| **Worst Case** | $O(N^2)$ | In extremely rare cases of total hash collisions (pathological cases), operations degrade to $O(N)$. For standard integers and modern hash functions, this is negligible. |

> **Note on Map Selection:** If `std::map` (Red-Black Tree) were used instead of `std::unordered_map`, complexity would be strictly $O(N \log N)$ (guaranteed), but with significantly higher constant factors and slower execution than the average hash map.

---

### 2. Space Complexity

* **Auxiliary Space:** $O(N)$
    * **Why:** In the worst-case scenario (e.g., an array of all unique positive numbers), every calculated prefix sum is unique. The hash map must store up to $N+1$ entries (the extra 1 accounts for the base case `{0: 1}`).
* **Input Space:** $O(N)$
    * **Why:** Standard memory required to store the input vector of energy readings.



---

### 3. Trade-offs

#### Why better than brute force?
Brute force requires checking every possible subarray $(i, j)$, leading to $O(N^2)$ or even $O(N^3)$ depending on how the sum is calculated. This solution reduces the time to linear $O(N)$ by **caching history**. Instead of recalculating sums, we look backward in time to find specific "complements."

#### What is sacrificed?
* **Memory:** We sacrifice $O(N)$ memory to store the prefix history. Brute force is more space-efficient, using only $O(1)$ auxiliary space.
* **Complexity Overhead:** Hashing introduces computational overhead (hashing functions, bucket resizing). For very small $N$ (e.g., 5-10 elements), a simple nested array-based loop might be slightly faster due to cache locality, but the hash-based method is vastly superior as $N$ grows into the thousands or millions.

---
_End of Solution File_