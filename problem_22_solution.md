# LEVEL 4 — DAY 5  
## L4-D5-Q6: Compiler Expression Health Check (Combined Problem)  
### PART 2 — Code, Validation, and Complexity

---

## 1️⃣ solution.cpp

> This file contains:
> - A **single-pass**, **stack-based** validator
> - Detection of **UNBALANCED**, **INVALID**, **REDUNDANT**, or **VALID**
> - `main()` runs **sample expressions** and prints results
>
> ⚠️ Notes:
> - No regex, no parsing libraries
> - One left-to-right scan
> - Stack stores minimal symbols to enforce invariants
> - Return value is used by the test harness (clearly documented)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  classifyExpression
  ------------------
  Returns one of:
  "UNBALANCED", "INVALID", "REDUNDANT", "VALID"

  NOTE:
  Return value is REQUIRED for test validation.
*/
string classifyExpression(const string& expr) {
    stack<char> st;
    bool lastWasOperand = false;   // tracks operand/operator placement
    bool lastWasOperator = false;

    for (char ch : expr) {

        // Case 1: Opening bracket
        if (ch == '(') {
            st.push(ch);
            lastWasOperand = false;
            lastWasOperator = false;
        }

        // Case 2: Operand
        else if (ch >= 'a' && ch <= 'z') {
            st.push('o'); // placeholder for operand
            lastWasOperand = true;
            lastWasOperator = false;
        }

        // Case 3: Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Invalid placement
            if (!lastWasOperand) {
                return "INVALID";
            }
            st.push(ch);
            lastWasOperand = false;
            lastWasOperator = true;
        }

        // Case 4: Closing bracket
        else if (ch == ')') {
            bool hasOperator = false;

            // Pop until '('
            while (!st.empty() && st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' ||
                    st.top() == '*' || st.top() == '/') {
                    hasOperator = true;
                }
                st.pop();
            }

            // No matching '('
            if (st.empty()) {
                return "UNBALANCED";
            }

            // Found '('
            st.pop();

            // No operator inside brackets → redundant
            if (!hasOperator) {
                return "REDUNDANT";
            }

            // Bracketed expression becomes an operand
            st.push('o');
            lastWasOperand = true;
            lastWasOperator = false;
        }

        // Case 5: Invalid character
        else {
            return "INVALID";
        }
    }

    // Final checks
    while (!st.empty()) {
        if (st.top() == '(') {
            return "UNBALANCED";
        }
        st.pop();
    }

    if (lastWasOperator) {
        return "INVALID";
    }

    return "VALID";
}

int main() {
    vector<string> examples = {
        "a+(b*c)",
        "((a+b))",
        "a+*b",
        "(a+b",
        "(a)"
    };

    for (const string& expr : examples) {
        cout << "Expression: " << expr << endl;
        cout << "Result    : " << classifyExpression(expr) << endl;
        cout << endl;
    }

    return 0;
}
```

## 