# PART 1 — L4-D6-Q6  
## Secret Message Clusters

---

## Question (Story-based)

An intelligence agency intercepts **short encrypted messages**.  
Some messages are **rearranged versions of the same original message**, meaning they contain the **same letters in different orders**.

To analyze communication patterns, the agency wants to **group messages that are rearrangements of each other**.

Two messages belong to the same group **if one can be formed by rearranging the letters of the other**.

Your task is to group all such messages together.

---

## Input / Output

### Input
- A list of lowercase strings representing intercepted messages.

### Output
- A list of groups, where:
  - Each group contains messages that are anagrams of each other.
  - The order of messages inside a group does **not matter**.
  - The order of groups does **not matter**.

---

## Constraints

- **Hash Map usage is mandatory**.
- Key design must be **explicitly justified**.
- Overall time complexity should be **O(N · K)**  
  *(N = number of strings, K = max string length)*.
- Sorting strings is allowed **only if justified**.
- Output order is irrelevant.

---

## Sample Inputs & Outputs

### Sample Input
messages = ["eat", "tea", "tan", "ate", "nat", "bat"]

shell


### Sample Output
[
["eat", "tea", "ate"],
["tan", "nat"],
["bat"]
]

yaml


---

## Notes

- All messages consist of lowercase English letters.
- Messages with different lengths **cannot** be anagrams.
- Choosing the right **grouping key** is the main challenge.
- Multiple correct outputs may exist due to order irrelevance.

---

## Deep Implementation Narrative  
*(ELI5 → Logical Thinking → Code Mapping)*

### ELI5 Explanation

Imagine each word is made of **letter blocks**.

- If two words use the **same blocks in the same quantities**,  
  they belong to the same box.
- The order of blocks inside the box doesn’t matter — only **what blocks exist and how many**.

So:
- You create a **label** that represents the block counts.
- All words with the same label go into the same group.

---

### Logical Breakdown

We must:
1. Create a **unique signature** for every word
2. Use that signature as a **grouping key**
3. Collect all words that share the same key

Two common key strategies:
- **Sorted string** (simple, but involves sorting)
- **Character frequency vector** (fixed-size, faster)

---

### Code Mapping (Mental Blueprint)

| Concept | Why it exists | What it maps to |
|------|---------------|----------------|
| Message | Input unit | String |
| Signature | Identity of an anagram group | Hashable key |
| Grouping | Collect related messages | Hash Map |
| Output groups | Final clusters | Vector of vectors |

**Key Insight:**  
Different words → same key → same group.

---


# Anagram Sorter: Test Cases & Analysis

This problem involves grouping words that are anagrams of each other. Two words are anagrams if they contain the exact same characters with the exact same frequencies.

---

## Sample Test Cases

| Sample Input | Sample Output | One-Line Explanation |
| :--- | :--- | :--- |
| `["listen", "silent", "top"]` | `[["listen", "silent"], ["top"]]` | "listen" and "silent" share the exact same character counts. |
| `["aaa", "aa", "a"]` | `[["aaa"], ["aa"], ["a"]]` | Different lengths result in different frequency signatures, even with the same character type. |

---

## Variety Test Cases (Dry Run & Analysis)

### 1. The "Permutation Party" (All Anagrams)
**Input:** `["abc", "acb", "bac", "bca", "cab", "cba"]`  
**Output:** `[["abc", "acb", "bac", "bca", "cab", "cba"]]`

* **Signature:** Every word generates the same count: `a:1, b:1, c:1` (others 0).
* **Key:** `1#1#1#0#0...`
* **Result:** The map stores all 6 strings under this single key.

> **Explanation:** Confirms that the algorithm correctly identifies all possible permutations of a set of characters as a single cluster.

### 2. The "Overlapping Letters" (Not Anagrams)
**Input:** `["aabb", "abab", "aaab"]`  
**Output:** `[["aabb", "abab"], ["aaab"]]`

* **"aabb":** Signature `{a:2, b:2}`.
* **"abab":** Signature `{a:2, b:2}`. (Matches "aabb")
* **"aaab":** Signature `{a:3, b:1}`. (New key)

> **Explanation:** Tests if the frequency count is precise. Having the same letters is not enough; the quantities must match exactly.

### 3. The "Single Character & Empty"
**Input:** `["a", "", "a", ""]`  
**Output:** `[["a", "a"], ["", ""]]`

* **"a":** Signature `{a:1}`, rest 0.
* **"":** Signature all 0s. Key: `0#0#0...`
* **Result:** Correctly groups the empty strings and the single-letter strings separately.

> **Explanation:** Validates handling of edge cases like empty strings and repeated single-letter strings.

### 4. The "Length Distinction" (Fast Rejection)
**Input:** `["test", "tests"]`  
**Output:** `[["test"], ["tests"]]`

* **"test":** `t:2, e:1, s:1`.
* **"tests":** `t:2, e:1, s:2`.
* **Result:** The signatures differ specifically at the 's' count index.

> **Explanation:** Demonstrates that words that are prefixes of each other or differ by only one letter are correctly separated.

### 5. The "Character Diversity" (Full Alphabet)
**Input:** `["patter", "tapter", "zebra"]`  
**Output:** `[["patter", "tapter"], ["zebra"]]`

* **"patter":** Signature counts `p:1, a:1, t:2, e:1, r:1`.
* **"tapter":** Signature matches "patter". (Group 1)
* **"zebra":** Signature counts `z:1, e:1, b:1, r:1, a:1`. (Group 2)

> **Explanation:** Ensures the hash key effectively covers the entire 26-letter range without collisions between different character sets.