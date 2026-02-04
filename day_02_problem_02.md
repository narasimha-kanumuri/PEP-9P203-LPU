<!--
---
marp: true

-->
---
 
 # Program 2: Valid Palindrome (Ignore Noise)

---

## Problem

Given a string `s`, determine whether it is a **palindrome**.

A string is considered a palindrome if:
- It reads the same forward and backward
- **Ignoring**:
  - Spaces
  - Punctuation
  - Special characters
  - Letter case (uppercase vs lowercase)

You must **not create a cleaned copy of the string**.

Return `true` if it is a palindrome, otherwise return `false`.

---

## Constraints

- 1 ≤ length of string ≤ 10^5
- String may contain:
  - Uppercase and lowercase letters
  - Digits
  - Spaces
  - Special characters
- Only constant extra space allowed (`O(1)`)

---

## Examples

### Example 1
**Input**
"A man, a plan, a canal: Panama"

markdown
Copy code

**Output**
true

yaml
Copy code

---

### Example 2
**Input**
"race a car"

markdown
Copy code

**Output**
false

yaml
Copy code

---

### Example 3
**Input**
" "

markdown
Copy code

**Output**
true

yaml
Copy code

---

## ELI5 Explanation

Imagine you are checking a sentence written on paper.

- You put one finger at the **start**
- Another finger at the **end**
- You move both fingers toward the center

But:
- You **skip spaces**
- You **skip symbols**
- You treat `A` and `a` as the **same letter**

If all meaningful letters match while moving inward, the string is a palindrome.

---

## Key Observations

- We do **not** modify the string
- We do **not** create a new filtered string
- We only **read characters**
- Comparison happens only on:
  - Letters (`a–z`, `A–Z`)
  - Digits (`0–9`)

---

## Implementation Narrative (English → Code)

### Step 1: Two Pointers

- `left` starts at the **beginning** of the string
- `right` starts at the **end** of the string

These pointers move **towards each other**.

---

### Step 2: Skip Non-Alphanumeric Characters

At each step:
- If `s[left]` is **not** a letter or digit → move `left` forward
- If `s[right]` is **not** a letter or digit → move `right` backward

This ensures we only compare **meaningful characters**.

---

### Step 3: Normalize Characters

Before comparing:
- Convert both characters to **lowercase**
- This removes case sensitivity (`A` == `a`)

---

### Step 4: Compare Characters

- If normalized `s[left] != s[right]`:
  - Immediately return `false`
- Otherwise:
  - Move both pointers inward

---

### Step 5: Termination Condition

- Loop continues while `left < right`
- If the loop finishes without mismatch:
  - Return `true`

---

## Why This Works

- Every character is visited **at most once**
- Skipping happens in-place
- No extra memory is used
- Works for:
  - Empty strings
  - Strings with only symbols
  - Mixed-case sentences

---

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Extra Space:** `O(1)`

---

## Conceptual Bridges

- Two-pointer logic is identical to:
  - Array boundary checks
  - Fast/slow pointer ideas in linked lists
- This prepares students for:
  - Middle of linked list
  - Reversal checks
  - Cycle detection reasoning


# Program 2: Valid Palindrome (Ignore Noise)
## Part 2 — Solution Code and Test Cases

---

## Solution Code (C++)

```cpp
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters on the left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Skip non-alphanumeric characters on the right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

```

## Test cases

```cpp

#include <iostream>
#include <string>
#include "palindrome.cpp"
using namespace std;
void runTest(const string& input, bool expected) {
    bool result = isPalindrome(input);
    cout << "Input: \"" << input << "\"\n";
    cout << "Expected: " << (expected ? "true" : "false")
         << ", Got: " << (result ? "true" : "false") << "\n\n";
}
int main() {
    // 1. Classic palindrome with punctuation
    runTest("A man, a plan, a canal: Panama", true);
    // 2. Clearly not a palindrome
    runTest("race a car", false);
    // 3. Empty string
    runTest("", true);
    // 4. Only spaces
    runTest("     ", true);
    // 5. Only special characters
    runTest("!!!@@@###", false);
    // 6. Single character
    runTest("a", true);
    // 7. Mixed case palindrome
    runTest("NoOn", true);
    // 8. Digits included
    runTest("1a2b2a1", true);
    // 9. Almost palindrome (one mismatch)
    runTest("ab@c#d!ba", false);
    // 10. Long realistic sentence
    runTest("Was it a rat I saw?", true);
    return 0;
}

```