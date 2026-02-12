# PART 2 — L4-D6-Q1  

## First Honest Number in a Live Feed

---

## Test cses

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 IMPORTANT:
 - Student solution file must expose:
     vector<int> firstNonRepeatingStream(const vector<int>&);
 - This test file imports and validates the logic.
*/

vector<int> firstNonRepeatingStream(const vector<int>&); // Student function

void runTest(const vector<int>& input, const vector<int>& expected) {
    vector<int> output = firstNonRepeatingStream(input);
    if (output == expected) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected: ";
        for (int x : expected) cout << x << " ";
        cout << "\nGot: ";
        for (int x : output) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    runTest({4, 5, 4, 5, 3}, {4, 4, 5, -1, 3});
    runTest({1, 2, 3, 4}, {1, 1, 1, 1});
    runTest({7, 7, 7}, {-1, -1, -1});
    runTest({10, 20, 10, 30, 20}, {10, 10, 20, 20, 30});
    return 0;
}


```

---

## Full C++ Solution Code (Main Solution File)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 Core function:
 Processes a stream and returns the first non-repeating element
 after each insertion.

 NOTE:
 - The return vector is primarily for TESTING PURPOSES.
 - In real execution (main), we print results immediately.
*/
vector<int> firstNonRepeatingStream(const vector<int>& stream) {
    unordered_map<int, int> freq;   // Frequency tracker
    queue<int> q;                   // Maintains arrival order
    vector<int> result;             // Used only for testing

    for (int num : stream) {
        // Step 1: Increase frequency
        freq[num]++;

        // Step 2: Push new element into queue
        q.push(num);

        // Step 3: Remove invalid (repeating) elements from front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Step 4: Decide current answer
        if (q.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(q.front());
        }
    }
    return result; // <-- Used by test file
}

int main() {
    // Sample Input 1
    vector<int> stream1 = {4, 5, 4, 5, 3};
    auto out1 = firstNonRepeatingStream(stream1);

    cout << "Output for Sample 1:\n";
    for (int x : out1) cout << x << " ";
    cout << "\n";

    // Sample Input 2
    vector<int> stream2 = {10, 10, 20, 30, 20};
    auto out2 = firstNonRepeatingStream(stream2);

    cout << "Output for Sample 2:\n";
    for (int x : out2) cout << x << " ";
    cout << "\n";

    return 0;
}
```

## Complete Complexity Analysis
Time Complexity

Let N be the number of elements in the stream.

Big-O (Worst Case):
O(N)
Each element is inserted into the queue once and removed once.

Theta (Average Case):
Θ(N)
Hash operations and queue operations remain constant-time on average.

Omega (Best Case):
Ω(N)
Even in the best scenario, each element must be processed once.

little-o:
o(N²)
Growth is strictly slower than quadratic.

little-omega:
ω(1)
Time grows beyond constant for increasing input size.

Space Complexity

Input Space: O(N)

Auxiliary Space:

Hash Map: O(N) (frequency tracking)

Queue: O(N) (order tracking)

Total Space: O(N)

Amortized Analysis

Each element:

Enqueued once

Dequeued once

Therefore, per element cost = O(1) amortized

Edge Cases & Annotations

All elements repeating → output always -1

Stream with all unique elements → first element persists

Large stream → safe due to amortized guarantees

Hash collisions → may degrade in theory, but average-case remains O(1)