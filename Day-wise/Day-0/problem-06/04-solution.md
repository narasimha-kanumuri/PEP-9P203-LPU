Here is the **solution.md** file for Day 01 - Program 06 ("The Streaming Packet Stitcher"), generated according to the **5-File DSA Documentation Contract (v1.3)**.

***

# 2️⃣ solution.md — Execution Artifacts

#### 🔖 Header
**Concepts Used:** `std::unordered_set`, Hashing, Sequence Traversal, $O(N)$ Optimization

---

### A. Complete Solution Code

```cpp
/**
 * Solution for "The Streaming Packet Stitcher" (Longest Consecutive Sequence)
 * Uses a Hash Set to perform O(1) lookups, enabling an O(N) solution 
 * by identifying the start of sequences intelligently.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for std::max

class PacketStitcher {
public:
    /**
     * Finds the length of the longest consecutive sequence of integers.
     * 
     * @param packets A vector of integers representing packet IDs (unsorted).
     * @return The length of the longest consecutive sequence.
     */
    static int longestConsecutiveSequence(const std::vector<int>& packets) {
        if (packets.empty()) {
            return 0;
        }

        // 1. Load all elements into a Hash Set for O(1) existence checks.
        //    This also naturally handles duplicates.
        std::unordered_set<int> numSet(packets.begin(), packets.end());
        
        int maxLength = 0;

        // 2. Iterate through the set (not the array, to avoid processing duplicates)
        for (int num : numSet) {
            // 3. CORE LOGIC: Identify the "Start" of a sequence.
            //    If (num - 1) exists, 'num' is NOT the start. We skip it.
            //    This ensures we only run the while loop once per sequence.
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // 4. Expand the sequence forward
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                maxLength = std::max(maxLength, currentStreak);
            }
        }

        return maxLength;
    }
};
```

---

### B. Executable Test Code

```cpp
#include <iostream>
#include <vector>
#include <cassert>

void runTests() {
    std::cout << "Running Packet Stitcher Tests..." << std::endl;

    // --- 1. Normal Case ---
    // Sequence: 1, 2, 3, 4 (Length 4)
    std::vector<int> input1 = {100, 4, 200, 1, 3, 2};
    int result1 = PacketStitcher::longestConsecutiveSequence(input1);
    assert(result1 == 4);
    std::cout << "[PASS] Normal Case: Detected sequence." << std::endl;

    // --- 2. Edge Case: Empty Input ---
    std::vector<int> input2 = {};
    int result2 = PacketStitcher::longestConsecutiveSequence(input2);
    assert(result2 == 0);
    std::cout << "[PASS] Edge Case: Empty input returns 0." << std::endl;

    // --- 3. Edge Case: Duplicates ---
    // Sequence: 0, 1, 2 (Length 3). Duplicates shouldn't inflate count.
    std::vector<int> input3 = {1, 2, 0, 1};
    int result3 = PacketStitcher::longestConsecutiveSequence(input3);
    assert(result3 == 3);
    std::cout << "[PASS] Edge Case: Duplicates handled correctly." << std::endl;

    // --- 4. Logic Trap: Multiple Sequences ---
    // Sequences: and. Longest is 5.
    std::vector<int> input4 = {1, 10, 2, 11, 3, 12, 14, 13};
    int result4 = PacketStitcher::longestConsecutiveSequence(input4);
    assert(result4 == 5);
    std::cout << "[PASS] Logic Trap: Multiple sequences, longest selected." << std::endl;

    // --- 5. Stress Case: Negative Numbers ---
    // Sequence: -1, 0, 1
    std::vector<int> input5 = {0, -1};
    int result5 = PacketStitcher::longestConsecutiveSequence(input5);
    assert(result5 == 2);
    std::cout << "[PASS] Stress Case: Negative sequence [-1, 0] detected." << std::endl;

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    runTests();
    return 0;
}
```

---

### C. Complexity Analysis

#### 1. Time Complexity
*   **Best/Average/Worst Case:** $O(N)$
    *   **The Myth:** Seeing a `while` loop inside a `for` loop usually suggests $O(N^2)$.
    *   **The Reality:** The check `if (numSet.find(num - 1) == numSet.end())` ensures that the inner `while` loop **only** runs for numbers that are the *start* of a sequence.
    *   **Amortized Analysis:** Each number in the array is visited exactly twice: once when added to the set, and once when checked by the `if` condition or the `while` loop. Therefore, total operations are $2N$, which simplifies to $O(N)$.

#### 2. Space Complexity
*   **Auxiliary Space:** $O(N)$
    *   **Why:** We create an `unordered_set` to store all unique elements from the input vector. This provides $O(1)$ access speed at the cost of linear memory usage.
*   **Input Space:** $O(N)$
    *   **Why:** To store the input vector.

#### 3. Trade-offs
*   **Why not sorting?**
    *   Sorting the array would allow us to solve this in $O(N)$ (one pass) *after* the sort. However, sorting itself takes $O(N \log N)$. The problem constraint specifically demands $O(N)$, forcing the use of a Hash Set.
*   **Space vs. Time:**
    *   We sacrifice $O(N)$ memory (for the Hash Set) to gain a speed advantage over sorting ($O(N)$ vs $O(N \log N)$). If memory were extremely tight, we would be forced to sort.