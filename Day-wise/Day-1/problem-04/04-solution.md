# Solution — Maximum Length Substring With At Most K Distinct Characters

## Concepts Used
Sliding Window, HashMap Frequency Tracking, Two-Pointer Technique, Amortized Analysis

---

## A. Complete Solution Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubstringAtMostKDistinct(const string& s, int K) {
    if (K == 0) return 0;

    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;

        while (freq.size() > K) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    cout << longestSubstringAtMostKDistinct("ecebaaa", 2) << endl;   // 4
    cout << longestSubstringAtMostKDistinct("aaabbb", 1) << endl;    // 3
    cout << longestSubstringAtMostKDistinct("abc", 5) << endl;       // 3
    cout << longestSubstringAtMostKDistinct("aaaaa", 0) << endl;     // 0

    return 0;
}

```

---

## C. Complexity Analysis

1️⃣ Algorithm Time Complexity
Raw Equation

T(n) = ∑ (Right Pointer Moves) + ∑ (Left Pointer Moves)

Right pointer moves = n
Left pointer moves ≤ n

T(n) = n + n
T(n) = 2n

Dominant Term Justification

Each character is inserted once and removed once from the window.

Simplified Big-O

O(n)

Case Breakdown
Best Case: O(n)
All characters already within K distinct.
One-line: Single forward scan without window shrink.

Average Case: O(n)
Window expands and shrinks proportionally.
One-line: Each index processed at most twice.

Worst Case: O(n)
Every character causes expansion and contraction.
One-line: Still linear because pointers never move backward.

Amortized: O(n)
Shrink operations distributed across total pointer movements.
One-line: No index is processed more than twice.

2️⃣ Program Time Complexity
Algorithm: O(n)

Program: O(n) average; worst-case hash operations degrade slightly but remain bounded.

Includes:

Hash table operations (average O(1))

Occasional erase operations

Constant-time pointer updates

No nested full reprocessing occurs.

3️⃣ Space Complexity
A. Input Space: O(n) (string storage)
B. Auxiliary Space: O(K) (frequency map)
C. Recursion Stack: O(0)
D. STL Internal Allocation: O(K) buckets

Since K ≤ 26 (lowercase letters),

Total Space Equation

S(n) = n + K
S(n) = n + 26

Simplified:

O(n) total
O(1) auxiliary (bounded by alphabet size)

4️⃣ Trade-offs
Better than brute force O(n²).
Sacrifice: Extra hash storage to maintain window invariant.

5️⃣ Complexity Summary
Time: O(n)
Space: O(1) auxiliary, O(n) including input