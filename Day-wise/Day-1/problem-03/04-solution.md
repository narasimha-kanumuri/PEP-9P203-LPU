# 📘 DAY 1 — PROGRAM 3 — FILE 2  
## 📄 solution.md  

---

# 🔖 Concepts Used  
HashMap, Frequency Counting, Custom Comparator Sorting, Vector Transformation  

---

## A. Complete Solution Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> frequencyOrderedUnique(const vector<int>& nums) {
    unordered_map<int, long long> freq;

    // Frequency counting
    for (int num : nums) {
        freq[num]++;
    }

    // Move unique elements to vector
    vector<pair<int, long long>> elements;
    elements.reserve(freq.size());

    for (const auto& entry : freq) {
        elements.push_back({entry.first, entry.second});
    }

    // Custom sort:
    // 1. Frequency descending
    // 2. Value ascending
    sort(elements.begin(), elements.end(),
        [](const pair<int, long long>& a, const pair<int, long long>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

    vector<int> result;
    result.reserve(elements.size());

    for (const auto& p : elements) {
        result.push_back(p.first);
    }

    return result;
}
```

## B. Executable Test Code

```cpp

int main() {
    // Normal Case
    vector<int> nums1 = {4, 6, 4, 3, 6, 4, 2};
    auto result1 = frequencyOrderedUnique(nums1);
    cout << "Test 1: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Edge Case (All Unique)
    vector<int> nums2 = {10, -1, 10, 5, -1, 5};
    auto result2 = frequencyOrderedUnique(nums2);
    cout << "Test 2: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Extreme Case (Large identical elements)
    vector<int> nums3(100000, 7);
    auto result3 = frequencyOrderedUnique(nums3);
    cout << "Test 3: ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
```

C. Complexity Analysis
1️⃣ Algorithm Time Complexity
Raw Equation
Let:

𝑛
n = size of input array

𝑘
k = number of unique elements

𝑇
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
𝑘
)
+
𝑂
(
𝑘
log
⁡
𝑘
)
T(n)=O(n)+O(k)+O(klogk)
Expansion
Frequency counting → 
𝑂
(
𝑛
)
O(n)

Copy to vector → 
𝑂
(
𝑘
)
O(k)

Sorting unique elements → 
𝑂
(
𝑘
log
⁡
𝑘
)
O(klogk)

𝑇
(
𝑛
)
=
𝑛
+
𝑘
+
𝑘
log
⁡
𝑘
T(n)=n+k+klogk
Dominant Term Justification
Since 
𝑘
≤
𝑛
k≤n,

Worst case (all elements unique):

𝑘
=
𝑛
k=n
𝑇
(
𝑛
)
=
𝑛
+
𝑛
+
𝑛
log
⁡
𝑛
T(n)=n+n+nlogn
𝑇
(
𝑛
)
=
𝑂
(
𝑛
log
⁡
𝑛
)
T(n)=O(nlogn)
Case Breakdown
✅ Best Case
Condition: All elements identical

𝑘
=
1
k=1

Sorting cost negligible

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
One-line: Only frequency counting dominates.

📊 Average Case
Condition: Moderate duplicates

𝑘
<
𝑛
k<n

𝑇
(
𝑛
)
=
𝑂
(
𝑛
+
𝑘
log
⁡
𝑘
)
T(n)=O(n+klogk)
One-line: Sorting limited to unique elements.

❌ Worst Case
Condition: All elements unique

𝑇
(
𝑛
)
=
𝑂
(
𝑛
log
⁡
𝑛
)
T(n)=O(nlogn)
One-line: Sorting all elements by frequency.

⚡ Amortized
unordered_map insert/find → average 
𝑂
(
1
)
O(1)

One-line: Hashing operations average constant time.

2️⃣ Program Time Complexity (Distinguished)
unordered_map insert → average 
𝑂
(
1
)
O(1), worst 
𝑂
(
𝑛
)
O(n) (hash collision)

sort → comparator constant time

Memory allocation → vector reserve prevents repeated reallocations

Algorithm:

𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
Program (average case):

𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
Program (worst collision case):

𝑂
(
𝑛
2
)
O(n 
2
 )
Reason: Pathological hash collisions.

3️⃣ Space Complexity (Full Breakdown)
A. Input Space
𝑂
(
𝑛
)
O(n)
B. Auxiliary Space
unordered_map storing k elements → 
𝑂
(
𝑘
)
O(k)

vector storing k pairs → 
𝑂
(
𝑘
)
O(k)

result vector → 
𝑂
(
𝑘
)
O(k)

𝐴
𝑢
𝑥
𝑖
𝑙
𝑖
𝑎
𝑟
𝑦
=
𝑂
(
𝑘
)
Auxiliary=O(k)
Worst case:

𝑂
(
𝑛
)
O(n)
C. Recursion Stack
None → 
𝑂
(
1
)
O(1)

D. STL Internal Allocation
unordered_map bucket allocation

vector capacity allocation

Combined bounded by 
𝑂
(
𝑘
)
O(k)

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
𝑘
)
S(n)=O(n)+O(k)
Worst case:

𝑆
(
𝑛
)
=
𝑂
(
𝑛
)
S(n)=O(n)
One-line: Extra memory proportional to number of unique elements.

4️⃣ Trade-offs
Faster than brute-force 
𝑂
(
𝑛
2
)
O(n 
2
 ) counting

Uses extra memory for frequency storage

Sorting required due to dual-condition ordering

🔚 Complexity Summary (1-Line)
Time: O(n log n) worst case
Space: O(n)