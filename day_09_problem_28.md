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