# 2️⃣ solution.md — Execution Artifacts

## 🔖 Header

**Concepts Used:** Nested Iteration, Array Indexing, Conditional Logic, Pairwise Aggregation

---

## Test Code

```cpp
#include <iostream>
#include <vector>
#include <cassert>

void runTests() {
    std::cout << "Running Centrifuge Tests..." << std::endl;

    // --- 1. Normal Case ---
    // Target 10 formed by 4 (index 1) and 6 (index 3)
    std::vector<int> weights1 = {1, 4, 8, 6, 2};
    std::pair<int, int> result1 = CentrifugeBalancer::findBalancePair(5, weights1, 10);
    assert(result1.first == 1 && result1.second == 3);
    std::cout << "[PASS] Normal Case: Found pair (4, 6) at indices 1, 3." << std::endl;

    // --- 2. Edge Case: No Solution ---
    // No two numbers sum to 100
    std::vector<int> weights2 = {10, 20, 30, 40};
    std::pair<int, int> result2 = CentrifugeBalancer::findBalancePair(4, weights2, 100);
    assert(result2.first == -1 && result2.second == -1);
    std::cout << "[PASS] Edge Case: No solution returns {-1, -1}." << std::endl;

    // --- 3. Edge Case: Minimum Input ---
    // Exactly two elements that match
    std::vector<int> weights3 = {5, 5};
    std::pair<int, int> result3 = CentrifugeBalancer::findBalancePair(2, weights3, 10);
    assert(result3.first == 0 && result3.second == 1);
    std::cout << "[PASS] Edge Case: Minimum array size (N=2) handled." << std::endl;

    // --- 4. Logic Trap: Duplicate Usage ---
    // Target is 8. Element 4 exists.
    // Logic must NOT return {0, 0} (using 4 twice). Must find {0, 2}.
    std::vector<int> weights4 = {4, 9, 4};
    std::pair<int, int> result4 = CentrifugeBalancer::findBalancePair(3, weights4, 8);
    assert(result4.first == 0 && result4.second == 2);
    std::cout << "[PASS] Logic Trap: Distinct indices enforced (4+4 valid only if two 4s exist)." << std::endl;

    // --- 5. Stress Case ---
    // N=1000, worst-case scenario (pair at very end or no pair)
    int stressN = 1000;
    std::vector<int> stressWeights(stressN, 1); 
    stressWeights[stressN-2] = 500;
    stressWeights[stressN-1] = 500;
    std::pair<int, int> resultStress = CentrifugeBalancer::findBalancePair(stressN, stressWeights, 1000);
    assert(resultStress.first == 998 && resultStress.second == 999);
    std::cout << "[PASS] Stress Case: Processed 1000 elements." << std::endl;

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
 * Solution for "The Bio-Lab Centrifuge" (Two Sum)
 * Implements a Brute Force approach to find two indices that sum to a target.
 */

#include <iostream>
#include <vector>
#include <utility> // For std::pair

class CentrifugeBalancer {
public:
    /**
     * Identifies two distinct tubes that sum exactly to the target weight.
     *
     * @param n The total number of test tubes.
     * @param weights A vector containing the weights of the tubes.
     * @param target The required total weight for balance.
     * @return A std::pair containing the 0-based indices of the two tubes.
     * Returns {-1, -1} if no valid pair exists.
     */
    static std::pair<int, int> findBalancePair(int n, const std::vector<int>& weights, int target) {
        // Defensive check for insufficient inputs
        if (n < 2) {
            return {-1, -1};
        }

        // Outer loop: Select the first element of the pair
        for (int i = 0; i < n - 1; ++i) {
            // Inner loop: Select the second element (start from i+1 to avoid duplicates/self-use)
            for (int j = i + 1; j < n; ++j) {

                // Constant time comparison
                if (weights[i] + weights[j] == target) {
                    return {i, j}; // Immediately return the first valid pair found
                }
            }
        }

        // No solution found after checking all N*(N-1)/2 pairs
        return {-1, -1};
    }
};
```


# 2️⃣ solution.md — Execution Artifacts (Section C)

> **🔖 Header** > **Topic:** Performance Evaluation & Resource Utilization for Nested Search

---

## C. Complexity Analysis



### 1. Time Complexity

| Case | Complexity | Reasoning |
| :--- | :--- | :--- |
| **Best Case** | $O(1)$ | If the very first two elements ($A[0]$ and $A[1]$) sum to the target, the function returns immediately without further iteration. |
| **Average Case** | $O(N^2)$ | On average, the algorithm scans half of all possible pairs. Since the total number of pairs is $\frac{N(N-1)}{2}$, the growth remains quadratic. |
| **Worst Case** | $O(N^2)$ | If the required pair is at the very end of the list or entirely absent, the nested loops execute fully. The CPU performs roughly $\frac{N^2}{2}$ comparisons. |

---

### 2. Space Complexity

* **Auxiliary Space:** $O(1)$
    * **Why:** The algorithm is highly memory-efficient. It only stores two integer iterators ($i, j$) and the return pair. No dynamic memory allocation or additional data structures (like HashMaps) occur within the function.
* **Input Space:** $O(N)$
    * **Why:** The input vector stores $N$ integers. This is considered "passive" storage as the data is passed by reference and not copied by the algorithm.



---

### 3. Trade-offs

#### Why use this? 
This is the **Brute Force** approach. It is the essential baseline for the problem because it requires **zero additional memory** and **no preprocessing** (like sorting). It is the easiest to implement and verify for small datasets.

#### What is sacrificed?
* **Scalability:** This logic does not scale well. For $N = 1,000,000$, $N^2 = 10^{12}$ operations. On a standard 2GHz processor, this would take approximately **500 seconds**. In contrast, an $O(N)$ approach using Hashing would finish in milliseconds.
* **Time for Space:** We strictly minimize memory usage ($O(1)$) but pay a heavy "tax" in the form of quadratic execution time ($O(N^2)$).

---
_End of Solution File_