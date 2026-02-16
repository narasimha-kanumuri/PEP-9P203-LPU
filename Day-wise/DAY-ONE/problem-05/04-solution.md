# 2️⃣ solution.md — Execution Artifacts

## 🔖 Header
**Concepts Used:** Hashing, Canonical Representation, String Manipulation, Map Aggregation

---

## Test file

```cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

// Utility to sort the result for deterministic testing comparisons
// (Since hash map iteration order is undefined)
void sortResult(std::vector<std::vector<std::string>>& res) {
    for (auto& group : res) {
        std::sort(group.begin(), group.end());
    }
    std::sort(res.begin(), res.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return a < b;
    });
}

void runTests() {
    std::cout << "Running Inventory Scramble Tests..." << std::endl;

    // --- 1. Normal Case ---
    std::vector<std::string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result1 = InventorySorter::groupLabels(input1);
    sortResult(result1);

    assert(result1.size() == 3);
    // Expected groups: [["ate","eat","tea"], ["bat"], ["nat","tan"]]
    assert(result1[0][0] == "ate");
    assert(result1[2][0] == "nat");
    std::cout << "[PASS] Normal Case: 3 groups identified correctly." << std::endl;

    // --- 2. Edge Case: Empty Input ---
    std::vector<std::string> input2 = {};
    auto result2 = InventorySorter::groupLabels(input2);
    assert(result2.empty());
    std::cout << "[PASS] Edge Case: Empty input returns empty result." << std::endl;

    // --- 3. Edge Case: Single Element ---
    std::vector<std::string> input3 = {"a"};
    auto result3 = InventorySorter::groupLabels(input3);
    assert(result3.size() == 1 && result3[0][0] == "a");
    std::cout << "[PASS] Edge Case: Single element handled." << std::endl;

    // --- 4. Logic Trap: No Anagrams ---
    std::vector<std::string> input4 = {"cat", "dog", "bird"};
    auto result4 = InventorySorter::groupLabels(input4);
    assert(result4.size() == 3); 
    std::cout << "[PASS] Logic Trap: Distinct words form distinct groups." << std::endl;

    // --- 5. Stress Case: Empty Strings ---
    std::vector<std::string> input5 = {"", "", "b"};
    auto result5 = InventorySorter::groupLabels(input5);
    sortResult(result5);
    assert(result5.size() == 2); 
    assert(result5[0].size() == 2); // Two empty strings group together
    std::cout << "[PASS] Stress Case: Empty strings handled as valid anagrams." << std::endl;

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
 * Solution for "The Warehouse Inventory Scramble" (Group Anagrams)
 * Uses sorting as a canonical key transformation to group equivalent strings.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class InventorySorter {
public:
    /**
     * Groups a list of product labels into clusters of anagrams.
     *
     * @param labels A vector of scrambled strings.
     * @return A vector of vectors, where each inner vector contains anagrams.
     */
    static std::vector<std::vector<std::string>> groupLabels(const std::vector<std::string>& labels) {
        // Map to store the canonical key (sorted string) and associated group
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const std::string& label : labels) {
            std::string key = label;

            // Transform to canonical form: "eat" -> "aet", "tea" -> "aet"
            // This sorts the characters in place to create a uniform key
            std::sort(key.begin(), key.end());

            // Add original string to the bucket corresponding to the sorted key
            map[key].push_back(label);
        }

        // Extract grouped vectors from the map into the result structure
        std::vector<std::vector<std::string>> result;
        result.reserve(map.size());
        for (auto& pair : map) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};

```

## C. Complexity Analysis

### 1. Time Complexity

| Case | Complexity | Reasoning |
| :--- | :--- | :--- |
| **Average Case** | $O(N \cdot K \log K)$ | For each of the $N$ strings, we perform a sort operation which takes $O(K \log K)$. Hash map insertions are amortized $O(1)$. Total time is dominated by key generation. |
| **Worst Case** | $O(N \cdot K \log K)$ | Sorting is deterministic. While hash collisions could theoretically degrade map operations, this is negligible compared to the $O(K \log K)$ sorting cost per string. |

> **Note:** $N$ represents the number of strings, and $K$ represents the maximum length of a single string.



---

### 2. Space Complexity

* **Auxiliary Space:** $O(N \cdot K)$
    * **Why:** We must store every string in the `unordered_map`. In the worst-case scenario where no anagrams exist, the map stores $N$ unique keys and $N$ strings across all vectors.
* **Input Space:** $O(N \cdot K)$
    * **Why:** The memory required to store the initial input vector of $N$ strings, each of length $K$.

---

### 3. Trade-offs

| Method | Complexity | Pros | Cons |
| :--- | :--- | :--- | :--- |
| **Sorting** (Used here) | $O(N \cdot K \log K)$ | Simple to implement; utilizes built-in STL support. | Becomes significantly slower if $K$ (string length) is very large. |
| **Frequency Count** | $O(N \cdot K)$ | Faster for extremely long strings (linear in $K$). | Requires custom logic to generate a hashable key from character counts. |



**Space vs. Time:**
We intentionally trade **$O(N \cdot K)$ space** (storing copies and keys in a map) to achieve near-linear time grouping. A brute-force comparison—checking every string against every other string—would result in **$O(N^2 \cdot K)$**, which is computationally unfeasible for large-scale warehouse inventories.

---
***End of Solution File***