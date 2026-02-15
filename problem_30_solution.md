# LEVEL 4 — DAY 7  
## L4-D7-Q2 — The Alien Language Translator

---

## PART 2

---

## TEst Cases


```cpp
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// Import student solution
bool areIsomorphic(const string& alien, const string& human);

void runTests() {
    // Valid isomorphic cases
    assert(areIsomorphic("egg", "add") == true);
    assert(areIsomorphic("paper", "title") == true);
    assert(areIsomorphic("ab", "cd") == true);

    // Invalid mappings
    assert(areIsomorphic("foo", "bar") == false);
    assert(areIsomorphic("ab", "aa") == false);
    assert(areIsomorphic("aa", "ab") == false);

    // Edge cases
    assert(areIsomorphic("", "") == true);
    assert(areIsomorphic("a", "a") == true);
    assert(areIsomorphic("a", "b") == true);

    // Length mismatch
    assert(areIsomorphic("abc", "ab") == false);

    cout << "All isomorphic string tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}


```

---

## ✅ Full C++ Solution Code (Main Solution File)

> **File:** `isomorphic_strings.cpp`  
> This file contains:
> - Complete solution logic
> - A helper function returning `bool` (used by test file)
> - A `main()` function that runs **exact sample inputs** from the question

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
Purpose:
Determine whether two strings follow a valid one-to-one
and bidirectional character mapping.

This function is separated so it can be:
- Tested independently
- Imported by an external test harness
*/
bool areIsomorphic(const string& alien, const string& human) {
    if (alien.length() != human.length()) {
        return false;
    }

    unordered_map<char, char> alienToHuman;
    unordered_map<char, char> humanToAlien;

    for (int i = 0; i < alien.length(); i++) {
        char a = alien[i];
        char h = human[i];

        // Check alien → human mapping
        if (alienToHuman.count(a)) {
            if (alienToHuman[a] != h) {
                return false; // Conflict
            }
        } else {
            alienToHuman[a] = h;
        }

        // Check human → alien mapping
        if (humanToAlien.count(h)) {
            if (humanToAlien[h] != a) {
                return false; // Conflict
            }
        } else {
            humanToAlien[h] = a;
        }
    }

    return true;
}

int main() {
    // Sample Input 1
    string alien1 = "egg";
    string human1 = "add";
    cout << "Input: " << alien1 << ", " << human1 << endl;
    cout << "Output: " << (areIsomorphic(alien1, human1) ? "true" : "false") << endl;

    cout << endl;

    // Sample Input 2
    string alien2 = "foo";
    string human2 = "bar";
    cout << "Input: " << alien2 << ", " << human2 << endl;
    cout << "Output: " << (areIsomorphic(alien2, human2) ? "true" : "false") << endl;

    return 0;
}
```

## Complete Complexity Analysis

Let N be the length of the strings.

⏱️ Time Complexity

Single left-to-right traversal

Constant-time hash operations

Case	Complexity
Best Case	Ω(1) (early conflict)
Average Case	Θ(N)
Worst Case	O(N)
📦 Space & Auxiliary Space Complexity

Two hash maps

At most one entry per unique character

Metric	Complexity
Auxiliary Space	O(1) (bounded character set)
General Case	O(N)
📊 Formal Asymptotic Notations

Big-O: O(N)

Big-Ω: Ω(1)

Big-Θ: Θ(N)

little-o: o(N²)

little-ω: ω(1)

⚠️ Edge Cases & Annotations

Unequal length strings → immediate failure

Multiple alien chars mapping to one human char → invalid

One alien char mapping to multiple human chars → invalid

Empty strings are trivially isomorphic

Early exit ensures efficiency