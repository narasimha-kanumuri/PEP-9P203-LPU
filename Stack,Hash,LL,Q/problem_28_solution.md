# PART 2 — L4-D6-Q6  

## Secret Message Clusters

---

## Test Cases

```cpp

#include <bits/stdc++.h>
using namespace std;

/*
 Student solution must provide:
     vector<vector<string>> groupAnagrams(const vector<string>&);
*/

vector<vector<string>> groupAnagrams(const vector<string>&);

vector<vector<string>> normalize(vector<vector<string>> groups) {
    for (auto& g : groups) {
        sort(g.begin(), g.end());
    }
    sort(groups.begin(), groups.end());
    return groups;
}

void runTest(const vector<string>& input,
             vector<vector<string>> expected) {
    auto result = groupAnagrams(input);
    if (normalize(result) == normalize(expected)) {
        cout << "PASS\n";
    } else {
        cout << "FAIL\nExpected:\n";
        for (auto& g : expected) {
            for (auto& w : g) cout << w << " ";
            cout << "\n";
        }
        cout << "Got:\n";
        for (auto& g : result) {
            for (auto& w : g) cout << w << " ";
            cout << "\n";
        }
    }
}

int main() {
    runTest(
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}
    );

    runTest(
        {"abc", "bca", "cab", "xyz", "zyx"},
        {{"abc", "bca", "cab"}, {"xyz", "zyx"}}
    );

    runTest(
        {},
        {}
    );

    runTest(
        {"a"},
        {{"a"}}
    );

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
 Groups strings that are anagrams of each other.

 KEY DESIGN JUSTIFICATION:
 - We use a fixed-size frequency signature of 26 lowercase letters.
 - This avoids sorting each string.
 - Signature creation is O(K) per string (K = string length).
 - The signature is converted to a string key for hashing.

 NOTE:
 - Returned structure is REQUIRED for the test file.
 - Order of groups and order within groups do NOT matter.
*/
vector<vector<string>> groupAnagrams(const vector<string>& messages) {
    unordered_map<string, vector<string>> groups;

    for (const string& word : messages) {
        // Build frequency signature
        int freq[26] = {0};
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Convert frequency array to a hashable key
        // Example: "1#0#0#2#..."
        string key;
        for (int i = 0; i < 26; i++) {
            key += to_string(freq[i]) + "#";
        }

        groups[key].push_back(word);
    }

    // Collect grouped results
    vector<vector<string>> result;
    for (auto& entry : groups) {
        result.push_back(entry.second);
    }
    return result; // <-- Used by test file
}

int main() {
    vector<string> messages = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups = groupAnagrams(messages);

    cout << "Grouped Messages:\n";
    for (const auto& group : groups) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "\n";
    }
    return 0;
}


```

## Complete Complexity Analysis

Let:

N = number of strings

K = maximum length of a string

Time Complexity

Big-O (Worst Case):
O(N · K)
Each string builds a frequency signature in O(K).

Theta (Average Case):
Θ(N · K)
Hash insertions and lookups are O(1) on average.

Omega (Best Case):
Ω(N)
Even with empty strings, each must be processed.

little-o:
o(N · K · log K)
Faster than sorting-based approaches.

little-omega:
ω(1)
Grows beyond constant with input size.

Space Complexity

Auxiliary Space:

Hash map keys: O(N · 26)

Stored strings: O(N · K)

Total Space:
O(N · K)

Amortized Analysis

Hash map insertions → O(1) amortized

Frequency signature creation → fixed cost per character

Edge Cases & Annotations

Empty input → empty result

Single string → one group

Strings of different lengths → never grouped

Order independence handled in tests via normalization

Frequency-key avoids sorting overhead