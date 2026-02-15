# LEVEL 4 — DAY 7  

## L4-D7-Q1 — The Museum Guard’s Logbook

---

## TEst cases

Test File Code (Validation Harness)

File: test_first_unique_character.cpp
This file:

Imports the student solution

Validates correctness programmatically

Can be reused for every student submission

Does NOT depend on main()

```cpp

#include <cassert>
#include <string>
#include <iostream>
using namespace std;

// Import the student's function
int firstUniqueCharacter(const string& log);

void runTests() {
    // Basic test cases
    assert(firstUniqueCharacter("museum") == 0);
    assert(firstUniqueCharacter("swiss") == 1);
    assert(firstUniqueCharacter("aabbcc") == -1);

    // Edge cases
    assert(firstUniqueCharacter("") == -1);
    assert(firstUniqueCharacter("a") == 0);
    assert(firstUniqueCharacter("aa") == -1);

    // Mixed characters
    assert(firstUniqueCharacter("abacbd") == 4);

    cout << "All tests passed successfully!" << endl;
}

int main() {
    runTests();
    return 0;
}

```

---

## PART 2

---

## ✅ Full C++ Solution Code (Main Solution File)

> **File:** `first_unique_character.cpp`  
> This file contains:
> - Complete solution logic  
> - A `main()` function that runs **exactly the sample inputs** from the question  
> - A helper function with a `return` value used by the test file  
>   (explicitly marked as *testing support*)

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
Purpose:
Find the index of the first non-repeating character in a string.

This function is intentionally separated so:
- The test file can import and validate it
- The main() function can demonstrate sample execution
*/
int firstUniqueCharacter(const string& log) {
    unordered_map<char, int> freq;

    // Phase 1: Count frequency of each character
    for (char c : log) {
        freq[c]++;
    }

    // Phase 2: Find first character with frequency == 1
    for (int i = 0; i < log.length(); i++) {
        if (freq[log[i]] == 1) {
            return i;  // Early termination
        }
    }

    return -1; // No unique character found
}

int main() {
    // Sample Input 1
    string log1 = "museum";
    cout << "Input: " << log1 << endl;
    cout << "Output: " << firstUniqueCharacter(log1) << endl;

    cout << endl;

    // Sample Input 2
    string log2 = "aabbcc";
    cout << "Input: " << log2 << endl;
    cout << "Output: " << firstUniqueCharacter(log2) << endl;

    return 0;
}
```

## Complete Complexity Analysis

Let N be the length of the input string.

⏱️ Time Complexity
Phase	Operation	Complexity
Frequency counting	Single traversal	O(N)
First unique detection	Single traversal	O(N)
Total Time Complexity

Worst Case: O(N)

Best Case: Ω(1)
(first character is unique, early termination)

Average Case: Θ(N)

📦 Space Complexity

Hash map stores at most one entry per unique character

ASCII character set → bounded upper limit

Type	Complexity
Auxiliary Space	O(1) (bounded character set)
General Case (unbounded charset)	O(N)
📊 Formal Asymptotic Notations

Big-O: O(N)

Big-Ω: Ω(1)

Big-Θ: Θ(N)

little-o: o(N²)

little-ω: ω(1)

⚠️ Edge Cases & Annotations

Empty string → return -1

Single character → always unique

All repeating characters → -1

Works with:

Letters

Digits

Symbols

Order preservation is guaranteed