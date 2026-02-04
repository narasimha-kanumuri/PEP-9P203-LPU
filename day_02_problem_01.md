<!-->
---
marp: true
---
-->
# Program 1: In-Place Array Compaction  

## Remove Duplicates from a Sorted Array

---

## Problem

Given a **sorted integer array**, remove duplicate elements **in-place** so that each unique element appears only once.

Return the **new logical length** of the array.

---

## Constraints

- Array is sorted in non-decreasing order
- 1 ≤ N ≤ 10^5
- No extra arrays allowed
- Only O(1) extra space
- Order must be preserved

---

## Example

### Input


[1, 1, 2, 2, 2, 3]


### Output


Array (logical): [1, 2, 3]
Returned Length: 3


---

## ELI5 Explanation

Imagine the array is written on a notebook.

- One finger **reads** numbers from left to right
- One finger **writes** only when a new number is found
- Because the array is sorted, duplicates always come together

We do not delete anything.
We simply **overwrite duplicates** with the next unique value.

---

## Implementation Narrative (English → Code)

1. The first element is always unique.
2. Keep a variable `writeIndex` that tells where the next unique value should be written.
3. Start scanning the array from index `1`.
4. For each element:
   - Compare it with the last written unique element.
   - If different:
     - Write it at `writeIndex`
     - Move `writeIndex` forward
5. At the end, `writeIndex` represents the new logical size.

---

## Solution Code (C++)

```cpp
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;

    int writeIndex = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[writeIndex - 1]) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    return writeIndex;
}

```

---

## Test Cases (Separate File)

```cpp
#include <iostream>
#include <vector>
#include "remove_duplicates.cpp"

using namespace std;

void test(vector<int> arr) {
    int len = removeDuplicates(arr);

    cout << "[ ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "] -> Length = " << len << endl;
}

int main() {
    test({1, 1, 2, 2, 2, 3});
    test({1, 1, 1});
    test({1, 2, 3, 4});
    test({5});
    test({});

    return 0;
}

```

---

## Time and Space Complexity

Time Complexity: O(N)

Extra Space Complexity: O(1)


---

## Classroom Discussion Questions


Why does this solution require the array to be sorted?

What happens if the array is unsorted?

How would this logic change for a linked list?