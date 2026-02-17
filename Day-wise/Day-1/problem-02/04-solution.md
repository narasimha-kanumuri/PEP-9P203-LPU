# 🔖 Concepts Used
Sliding Window  
HashSet  
Invariant Maintenance  
Amortized Analysis  

---

# A. Complete Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

bool containsDuplicateWithinK(const vector<int>& arr, int K) {
    if (K <= 0 || arr.empty()) return false;

    unordered_set<int> window;

    for (int i = 0; i < arr.size(); i++) {

        if (window.count(arr[i])) {
            return true;
        }

        window.insert(arr[i]);

        if (window.size() > K) {
            window.erase(arr[i - K]);
        }
    }

    return false;
}
B. Executable Test Code
int main() {

    // Normal case
    vector<int> arr1 = {4, 1, 3, 4};
    cout << containsDuplicateWithinK(arr1, 3) << endl;  // Expected: 1

    // Edge case (K = 0)
    vector<int> arr2 = {1, 2, 1};
    cout << containsDuplicateWithinK(arr2, 0) << endl;  // Expected: 0

    // Extreme/stress case
    vector<int> arr3(100000, 5);
    cout << containsDuplicateWithinK(arr3, 99999) << endl;  // Expected: 1

    return 0;
}
C. Complexity Analysis
1️⃣ Algorithm Time Complexity
Raw Equation
𝑇
(
𝑛
)
=
∑
𝑖
=
0
𝑛
−
1
(
𝐼
𝑛
𝑠
𝑒
𝑟
𝑡
+
𝐿
𝑜
𝑜
𝑘
𝑢
𝑝
+
𝑃
𝑜
𝑠
𝑠
𝑖
𝑏
𝑙
𝑒
 
𝐸
𝑟
𝑎
𝑠
𝑒
)
T(n)= 
i=0
∑
n−1
​
 (Insert+Lookup+Possible Erase)
Expansion
Each iteration performs:

One lookup → O(1) average

One insert → O(1) average

One erase (conditional) → O(1) average

𝑇
(
𝑛
)
=
𝑛
⋅
𝑂
(
1
)
T(n)=n⋅O(1)
Dominant Term Justification
Each element enters the set once and leaves at most once.

𝑇
(
𝑛
)
=
𝑂
(
𝑛
)
T(n)=O(n)
Case Breakdown
Best Case
Occurs when duplicate found early.
Time: O(1)
One-line: Early termination after first repeated value.

Average Case
Uniform distribution, minimal collisions.
Time: O(n)
One-line: Each element processed once.

Worst Case
No duplicates within K and maximum hash collisions.
Time: O(n) average, O(n²) worst theoretical
One-line: Hash collisions degrade operations to linear per insert.

Amortized Case
Hash resizing spreads rehash cost.
Time: O(n)
One-line: Rehash cost distributed across insertions.

2️⃣ Program Time Complexity (Distinguished)
Algorithm: O(n) average

Program Considerations:

unordered_set may rehash → occasional O(n)

Hash collision chains may degrade to O(n)

erase operation cost depends on bucket structure

Program Worst Case: O(n²) theoretical due to collision clustering.

3️⃣ Space Complexity
A. Input Space
𝑂
(
𝑛
)
O(n)
B. Auxiliary Space
At most K elements in window.

𝑂
(
𝐾
)
O(K)
C. Recursion Stack
None.

𝑂
(
1
)
O(1)
D. STL Internal Allocation
unordered_set bucket storage:

𝑂
(
𝐾
)
O(K)
E. Total Space Equation
𝑆
(
𝑛
)
=
𝑂
(
𝑛
)
+
𝑂
(
𝐾
)
S(n)=O(n)+O(K)
Auxiliary (excluding input):

𝑂
(
𝐾
)
O(K)
4️⃣ Trade-offs
Better than brute force O(NK).

Sacrifices:

Extra memory

Hash collision sensitivity

🔹 Complexity Summary (1-Line)
Time: O(n) average, O(n²) worst theoretical
Space: O(K) auxiliary