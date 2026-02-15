# LEVEL 4 — DAY 7  

## L4-D7-Q6 — The Surveillance Window Analyzer

---

## PART 2

File: test_distinct_window.cpp

Imports student solution

Validates correctness

Reusable for all submissions

Independent of main()

---

```cpp

#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

// Import student function
vector<int> countDistinctInWindow(const vector<int>& activity, int K);

void runTests() {

    assert((countDistinctInWindow({1,2,1,3,4,2,3}, 4) == vector<int>{3,4,4,3}));
    assert((countDistinctInWindow({5,5,5,5}, 2) == vector<int>{1,1,1}));
    assert((countDistinctInWindow({1,2,3,4}, 1) == vector<int>{1,1,1,1}));
    assert((countDistinctInWindow({1,2,3,4}, 4) == vector<int>{4}));

    // Edge cases
    assert((countDistinctInWindow({}, 3) == vector<int>{}));
    assert((countDistinctInWindow({1,2}, 3) == vector<int>{}));

    cout << "All sliding window distinct tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}


```

---

# ✅ Full C++ Solution Code (Main Solution File)

> **File:** `distinct_elements_in_window.cpp`  
> Contains:
> - Complete O(N) sliding window + hashing solution
> - Clean reusable function for test harness
> - main() executes exactly the sample inputs from Part 1

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Purpose:
For every window of size K,
return the count of distinct elements.

Design:
- Sliding Window
- Frequency Hash Map
- O(N) time
*/
vector<int> countDistinctInWindow(const vector<int>& activity, int K) {

    vector<int> result;

    if (K <= 0 || activity.empty() || K > activity.size())
        return result;

    unordered_map<int, int> freq;

    // Step 1: Build first window
    for (int i = 0; i < K; i++) {
        freq[activity[i]]++;
    }

    result.push_back(freq.size());

    // Step 2: Slide the window
    for (int i = K; i < activity.size(); i++) {

        int elementToRemove = activity[i - K];
        int elementToAdd = activity[i];

        // Remove outgoing element
        freq[elementToRemove]--;
        if (freq[elementToRemove] == 0) {
            freq.erase(elementToRemove);
        }

        // Add incoming element
        freq[elementToAdd]++;

        result.push_back(freq.size());
    }

    return result;
}

int main() {

    vector<int> sample1 = {1, 2, 1, 3, 4, 2, 3};
    int K1 = 4;

    cout << "Input: {1,2,1,3,4,2,3}, K=4" << endl;
    vector<int> output1 = countDistinctInWindow(sample1, K1);

    for (int val : output1)
        cout << val << " ";
    cout << endl << endl;


    vector<int> sample2 = {5, 5, 5, 5};
    int K2 = 2;

    cout << "Input: {5,5,5,5}, K=2" << endl;
    vector<int> output2 = countDistinctInWindow(sample2, K2);

    for (int val : output2)
        cout << val << " ";
    cout << endl;

    return 0;
}
```

## Complete Complexity Analysis

Let:

N = size of array

K = window size

⏱️ Time Complexity
First Window Build:

Insert K elements → O(K)

Sliding Phase:

Each step:

One removal → O(1)

One insertion → O(1)

Total slides → (N - K)

Total:

O(K + (N - K)) = O(N)

Best / Average / Worst
Case	Complexity
Best Case	Ω(N)
Average Case	Θ(N)
Worst Case	O(N)

No nested loops.
Each element enters and exits exactly once.

📦 Space & Auxiliary Space

Frequency map holds at most K distinct elements

Metric	Complexity
Auxiliary Space	O(K)
Worst Case	O(N) (if K = N)
📊 Formal Asymptotic Notations

Big-O: O(N)

Big-Ω: Ω(N)

Big-Θ: Θ(N)

little-o: o(N log N)

little-ω: ω(1)

🔍 Why This Is Truly O(N)

Each element:

Inserted once

Removed once

Total operations proportional to N.

No recomputation.

⚠️ Edge Cases & Annotations

K = 1 → all outputs = 1

K = N → single output

K > N → empty result

Negative values handled naturally

Large numbers handled safely

🧠 Pattern Extracted

This teaches:

Sliding window

Frequency map maintenance

Incremental state updates

Efficient window analytics

Used in:

Network traffic monitoring

Log analysis

Real-time streaming analytics

Interview advanced problems