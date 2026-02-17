# Complement Pair with Distance Constraint

## Concepts Used
Unordered Map, Complement Tracking, Lexicographic Ordering, Constraint Validation

---

# A. Core Implementation (Reusable Logic Only)

## File: complement_pair.h

```cpp
#ifndef COMPLEMENT_PAIR_H
#define COMPLEMENT_PAIR_H

#include <vector>
#include <utility>

std::pair<int,int> complementPairWithDistance(
    const std::vector<long long>& values,
    long long T,
    int K
);

#endif
```

## Test Cases

```cpp

#include <iostream>
#include "complement_pair.h"

int main() {

    // 1️⃣ Normal Case
    std::vector<long long> v1 = {2, 7, 11, 15};
    auto ans1 = complementPairWithDistance(v1, 9, 1);
    std::cout << "Normal Case: "
              << ans1.first << " "
              << ans1.second << std::endl;

    // 2️⃣ Edge Case (No solution)
    std::vector<long long> v2 = {1, 2, 3, 4};
    auto ans2 = complementPairWithDistance(v2, 100, 1);
    std::cout << "Edge Case: "
              << ans2.first << " "
              << ans2.second << std::endl;

    // 3️⃣ Extreme Case (Heavy duplicates)
    std::vector<long long> v3(50000, 1);
    auto ans3 = complementPairWithDistance(v3, 2, 20000);
    std::cout << "Extreme Case: "
              << ans3.first << " "
              << ans3.second << std::endl;

    return 0;
}


```


## Main.cpp

```cpp

#include "complement_pair.h"
#include <unordered_map>

std::pair<int,int> complementPairWithDistance(
    const std::vector<long long>& values,
    long long T,
    int K
) {
    std::unordered_map<long long, std::vector<int>> indexMap;
    std::pair<int,int> best = {-1, -1};

    for(int j = 0; j < (int)values.size(); j++) {

        long long needed = T - values[j];

        if(indexMap.count(needed)) {
            for(int i : indexMap[needed]) {

                if(j - i >= K) {
                    std::pair<int,int> candidate = {i, j};

                    if(best.first == -1 || candidate < best) {
                        best = candidate;
                    }
                }
            }
        }

        indexMap[values[j]].push_back(j);
    }

    return best;
}


```


## C. Complexity Analysis (Mathematical Framework)
1️⃣ Algorithm Time Complexity

Let n = values.size()

Raw Equation

In worst-case (all elements identical):

T(n) = 1 + 2 + 3 + ... + (n − 1)

Expansion

T(n) = n(n − 1) / 2

Dominant Term

≈ n² / 2

Simplified Big-O

Worst Case: O(n²)

Case Breakdown
Best Case

No complement found.
Each element performs O(1) lookup.

Time: O(n)

One-line: Only constant-time hash operations occur per element.

Average Case

Hash lookup O(1) expected.
Few duplicates.

Time: O(n)

One-line: Each element processed once with expected constant-time lookup.

Worst Case

All elements identical.
Every complement check scans growing vector.

Time: O(n²)

One-line: Duplicate-heavy input forces quadratic nested iteration.

Amortized Analysis

Hash insertions and vector push_back operations are amortized O(1).

2️⃣ Program Time Complexity (Distinguished)

Includes:

unordered_map bucket allocation

Possible rehashing

Hash collision chains

Vector dynamic resizing

Algorithm Complexity:
Average O(n)

Program Complexity:
Average O(n)
Worst-case due to hash collisions: O(n²)

One-line: Real performance depends on hash distribution and collision behavior.

3️⃣ Space Complexity (Full Breakdown)
A. Input Space

O(n)

B. Auxiliary Space

Hash map storing all indices:

O(n)

C. Recursion Stack

None → O(1)

D. STL Internal Allocation

Bucket array

Vectors storing indices

O(n)

E. Total Space Equation

S(n) = n (input) + n (hash storage)

= 2n

= O(n)

One-line: Each element stored once in auxiliary hash storage.

4️⃣ Complexity Summary Block (Mandatory)

Time:
Best: O(n)
Average: O(n)
Worst: O(n²)

Space:
O(n)