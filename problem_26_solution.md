# PART 2 — L4-D6-Q4  

## Secure Command Script Validator

---

## Test cases

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 Student solution must provide:
     bool isValidScript(const string&);
*/

bool isValidScript(const string&);

void runTest(const string& input, bool expected) {
    bool result = isValidScript(input);
    if (result == expected) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected: "
             << (expected ? "true" : "false")
             << " | Got: "
             << (result ? "true" : "false") << "\n";
    }
}

int main() {
    runTest("{[()()]}", false);              // empty ()
    runTest("{[(a+b)*(c-d)]}", true);        // valid
    runTest("([{}])", false);                // empty {}
    runTest("{[()x]}", true);                // non-empty ()
    runTest("((a+b))", true);                // nested, non-empty
    runTest("()", false);                    // empty
    runTest("{[}", false);                   // mismatch
    runTest("", true);                       // no symbols → valid
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
 Validates a script containing (), {}, [] with extra rules:
 1) Proper matching and nesting
 2) NO empty pairs allowed (e.g., (), {}, [])
 3) Single left-to-right traversal

 NOTE:
 - Non-symbol characters are ignored.
 - The boolean return is REQUIRED for the test file.
*/
bool isValidScript(const string& script) {
    unordered_map<char, char> match = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    // Stack stores: (opening_symbol, index_position)
    stack<pair<char, int>> st;

    for (int i = 0; i < (int)script.size(); i++) {
        char c = script[i];

        // Opening symbols
        if (c == '(' || c == '{' || c == '[') {
            st.push({c, i});
        }
        // Closing symbols
        else if (c == ')' || c == '}' || c == ']') {
            // No matching opener
            if (st.empty()) return false;

            auto top = st.top();
            st.pop();

            // Type mismatch
            if (top.first != match[c]) return false;

            // Empty pair check:
            // If opener index + 1 == closer index → nothing inside
            if (top.second + 1 == i) return false;
        }
        // Ignore all other characters
    }

    // If stack not empty → unmatched opening symbols
    return st.empty();
}

int main() {
    // Sample Input 1
    string s1 = "{[()()]}";
    cout << "Sample 1 Output: "
         << (isValidScript(s1) ? "true" : "false") << "\n";

    // Sample Input 2
    string s2 = "{[(a+b)*(c-d)]}";
    cout << "Sample 2 Output: "
         << (isValidScript(s2) ? "true" : "false") << "\n";

    return 0;
}

```

## Complete Complexity Analysis
Time Complexity

Let N be the length of the script.

Big-O (Worst Case):
O(N) — single pass through the string.

Theta (Average Case):
Θ(N) — each character processed once.

Omega (Best Case):
Ω(N) — even to confirm validity, full scan may be required.

little-o:
o(N²) — strictly slower growth than quadratic.

little-omega:
ω(1) — grows beyond constant with input size.

Space Complexity

Auxiliary Space:

Stack can hold up to N opening symbols → O(N)

Input Space: O(N)

Total Space: O(N)

Amortized Analysis

Each symbol:

Pushed once

Popped once

Stack operations are O(1) amortized.

Edge Cases & Annotations

Empty string → valid (no violations)

Only opening symbols → invalid

Only closing symbols → invalid

Nested empty pair inside valid structure → invalid

Non-symbol characters are ignored safely