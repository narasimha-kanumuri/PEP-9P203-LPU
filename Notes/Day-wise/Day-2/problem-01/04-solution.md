# Solution.cpp

---

## 🔖 Concepts Used

Binary Search, Monotonic Missing-Count Function, Boundary Detection

---

## Test File

```cpp

int main() {
    Solution sol;

    // Normal case
    vector<int> arr1 = {2, 3, 4, 7, 11};
    cout << sol.findKthMissing(arr1, 5) << endl; // Expected: 9

    // Edge case: all missing after array
    vector<int> arr2 = {1, 2, 3, 4};
    cout << sol.findKthMissing(arr2, 2) << endl; // Expected: 6

    // Edge case: missing before first element
    vector<int> arr3 = {5, 6, 7};
    cout << sol.findKthMissing(arr3, 3) << endl; // Expected: 3

    // Extreme case
    vector<int> arr4 = {1000000000};
    cout << sol.findKthMissing(arr4, 999999999) << endl;

    return 0;
}


```

---

## Solution.cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthMissing(vector<int>& arr, long long k) {
        int n = arr.size();
        
        // If kth missing is before first element
        if (arr[0] > k) return k;

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long missing = (long long)arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // At this point, high < low
        // high is last index where missing < k
        if (high < 0) return k;

        long long missingAtHigh = (long long)arr[high] - (high + 1);

        return arr[high] + (k - missingAtHigh);
    }
};

```

# C. Complexity Analysis

---

## 1️⃣ Algorithm Time Complexity

### Raw Equation
$$T(n) = T(n/2) + O(1)$$

### Expansion
$$T(n) = O(\log n)$$

### Dominant Term Justification
- Each iteration halves the search space using binary search.
- No nested operations inside loop.



---

### Case Breakdown

- **Best Case**
  - **Condition:** Target boundary found early
  - **Time:** $O(\log n)$
  - **Explanation:** Binary search always halves space regardless.
- **Average Case**
  - **Condition:** Random distribution
  - **Time:** $O(\log n)$
  - **Explanation:** Search depth proportional to tree height.
- **Worst Case**
  - **Condition:** Boundary lies at extreme end
  - **Time:** $O(\log n)$
  - **Explanation:** Full binary depth traversal.
- **Amortized**
  - Not applicable (no repeated restructuring).

---

## 2️⃣ Program Time Complexity (Distinguished)

- Vector access: $O(1)$
- Arithmetic operations: $O(1)$
- No STL restructuring
- No hashing
- No reallocation
- **Algorithm:** $O(\log n)$
- **Program:** $O(\log n)$

---

## 3️⃣ Space Complexity

- **A. Input Space:** $O(n)$
- **B. Auxiliary Space:** $O(1)$
- **C. Recursion Stack:** None
- **D. STL Internal Allocation:** Vector already allocated externally.

### E. Total Space Equation
$$S(n) = O(n) + O(1)$$

### One-line Explanation
- Uses constant extra memory while operating on input array.

---

## 4️⃣ Trade-offs

- ✅ Much faster than brute force $O(n + k)$
- ⚠️ Requires strictly increasing sorted array
- ❌ Cannot apply if array unsorted

---

## 🔷 Complexity Summary (1-Line)

- **Time:** $O(\log n)$
- **Space:** $O(1)$ auxiliary, $O(n)$ total including input