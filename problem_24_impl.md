- [Suspicious Repeat Alert Within Limited Distance](#suspicious-repeat-alert-within-limited-distance)
- [1️⃣ What Is This Question REALLY Asking?](#1️⃣-what-is-this-question-really-asking)
- [2️⃣ Why Is This Problem Tricky?](#2️⃣-why-is-this-problem-tricky)
- [3️⃣ ELI5 Core Idea](#3️⃣-eli5-core-idea)
- [4️⃣ Exact Logical Rule (Math Version)](#4️⃣-exact-logical-rule-math-version)
- [5️⃣ Step-by-Step Thinking Before Code](#5️⃣-step-by-step-thinking-before-code)
- [6️⃣ English → Code Mapping Table](#6️⃣-english--code-mapping-table)
- [7️⃣ Walk Through ALL Test Cases](#7️⃣-walk-through-all-test-cases)
    - [Test Case 1](#test-case-1)
    - [Test Case 2](#test-case-2)
    - [Test Case 3](#test-case-3)
    - [Test Case 4](#test-case-4)
    - [Test Case 5](#test-case-5)
- [8️⃣ Edge Cases](#8️⃣-edge-cases)
- [9️⃣ Final Clean Implementation](#9️⃣-final-clean-implementation)
- [🔟 Complexity (Simple English)](#-complexity-simple-english)
- [Final Mental Model](#final-mental-model)



# Suspicious Repeat Alert Within Limited Distance

---

# 1️⃣ What Is This Question REALLY Asking?

We are given:

- A list of badge IDs (numbers)
- A number K

We must check:

Does the same number appear again within K positions?

Important:

- We are NOT checking if duplicates exist anywhere.
- We are checking if duplicates exist CLOSE to each other.
- If distance between two same IDs ≤ K → return true.
- If all duplicates are farther than K → return false.

And the moment we find one valid repeat → STOP immediately.

---

# 2️⃣ Why Is This Problem Tricky?

Students usually misunderstand:

- They check entire past instead of last K.
- They forget to remove old elements.
- They confuse "duplicate exists" with "duplicate within K".

The word that causes confusion is:

> "within the last K entries"

That means:
Only recent history matters.

Not entire history.

---

# 3️⃣ ELI5 Core Idea

Imagine you are guarding a room.

You can remember only the last K people who entered.

When a new person enters:

- If you remember them → ALERT.
- If not → remember them.
- If your memory becomes bigger than K → forget the oldest person.

You do NOT care about people from long ago.

That is the entire idea.

---

# 4️⃣ Exact Logical Rule (Math Version)

If the same value appears at:

- index i
- index j

Then:

Distance = |i - j|

Valid only if:

Distance ≤ K

If distance > K → ignore it.

---

# 5️⃣ Step-by-Step Thinking Before Code

Step 1: Create a structure to remember last K elements  
Step 2: Traverse array from left to right  
Step 3: For each element:
- Check if already in memory → return true  
Step 4: Add current element to memory  
Step 5: If memory size exceeds K → remove oldest element  

Repeat until finished.

If loop ends → return false.

---

# 6️⃣ English → Code Mapping Table

| English Rule | Code Line | Why |
|--------------|-----------|-----|
| We need fast lookup | `unordered_set<int> window;` | O(1) search |
| Traverse left to right | `for (int i = 0; i < ids.size(); i++)` | One pass |
| Check duplicate | `window.find(ids[i])` | Detect repeat |
| Return immediately | `return true;` | Early exit |
| Add current ID | `window.insert(ids[i]);` | Track recent |
| Remove old element | `window.erase(ids[i - K]);` | Maintain K window |

---

# 7️⃣ Walk Through ALL Test Cases

---

### Test Case 1
Input: `[10, 20, 30, 10]`, K = 3  
Expected: true  

Simulation:

i = 0 → window = {} → add 10 → {10}  
i = 1 → add 20 → {10,20}  
i = 2 → add 30 → {10,20,30}  
i = 3 → 10 already in window → return true  

Distance = 3 - 0 = 3 ≤ K → valid

---

### Test Case 2
Input: `[5, 6, 7, 5]`, K = 2  
Expected: false  

i = 0 → {5}  
i = 1 → {5,6}  
i = 2 → add 7 → {5,6,7}  
Since i >= K → remove ids[0] → remove 5  
Window = {6,7}  

i = 3 → check 5  
5 NOT in window  

Return false  

Distance was 3 → greater than K → invalid

---

### Test Case 3
Input: `[1, 2, 3, 4]`, K = 1  
Expected: false  

No duplicate appears  
Return false

---

### Test Case 4
Input: `[1, 2, 1]`, K = 2  
Expected: true  

i = 0 → {1}  
i = 1 → {1,2}  
i = 2 → 1 found in window → return true  

Distance = 2 ≤ 2 → valid

---

### Test Case 5
Input: `[]`, K = 5  
Expected: false  

Loop never runs  
Return false

---

# 8️⃣ Edge Cases

Empty input → false  

K = 0 → always false  
Because distance must be ≤ 0  
Two different indices cannot have distance 0  

K > N → works fine  
Window may grow but still correct  

All unique → false  

All same and K ≥ 1 → true immediately  

---

# 9️⃣ Final Clean Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

bool hasNearbyDuplicate(const vector<int>& ids, int K) {
    unordered_set<int> window;

    for (int i = 0; i < ids.size(); i++) {
        if (window.find(ids[i]) != window.end()) {
            return true;
        }

        window.insert(ids[i]);

        if (i >= K) {
            window.erase(ids[i - K]);
        }
    }

    return false;
}
```

---

# 🔟 Complexity (Simple English)

Time Complexity:

We visit each element once.  
Each element is inserted once and removed once.  
So total work grows linearly.

Time = O(N)

Best case = O(1)  
If duplicate found immediately.

Space Complexity:

We store at most K elements in set.

Worst case:

If K ≥ N → O(N)

Otherwise → O(K)

---

# Final Mental Model

This is NOT duplicate detection.

This is:

Duplicate detection inside a moving window of size K.

Window always represents:

Last K elements only.

That is the entire logic.
