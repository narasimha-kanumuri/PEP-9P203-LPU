# LEVEL 4 — DAY 7  

## L4-D7-Q4 — The Research Lab Memory System

---

## PART 2

File: test_lru_cache.cpp

Imports class

Validates eviction invariant
Reusable for student submissions

---

## Test cases

```cpp

#include <cassert>
#include <iostream>
using namespace std;

// Forward declaration
class LRUCache;

void runTests() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    assert(cache.get(1) == 10);

    cache.put(3, 30);  // Evict 2
    assert(cache.get(2) == -1);

    cache.put(4, 40);  // Evict 1
    assert(cache.get(1) == -1);
    assert(cache.get(3) == 30);
    assert(cache.get(4) == 40);

    // Update existing key
    cache.put(4, 400);
    assert(cache.get(4) == 400);

    cout << "All LRU cache tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}


```

---

# ✅ Full C++ Solution Code (Main Solution File)

> **File:** `lru_cache.cpp`  
> Contains:
> - Complete LRU Cache implementation
> - Hash Map + Doubly Linked List
> - Strict O(1) operations
> - main() executes exactly the example scenario
> - Clean separation for test harness reuse

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

/*
Node structure for Doubly Linked List
Stores:
- key
- value
- prev pointer
- next pointer
*/
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    Node* head;  // Dummy head (MRU side)
    Node* tail;  // Dummy tail (LRU side)

    /*
    Remove node from DLL
    */
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    /*
    Insert node right after head (Most Recently Used position)
    */
    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        // Initialize dummy head and tail
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        // Move accessed node to front
        removeNode(node);
        insertToFront(node);

        return node->value;
    }

    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {
            // Update existing node
            Node* node = cache[key];
            node->value = value;

            removeNode(node);
            insertToFront(node);
        }
        else {
            if (cache.size() == capacity) {
                // Evict LRU node (node before tail)
                Node* lru = tail->prev;

                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertToFront(newNode);
        }
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;  // 10

    cache.put(3, 30);              // Evicts key 2
    cout << cache.get(2) << endl;  // -1

    cache.put(4, 40);              // Evicts key 1
    cout << cache.get(1) << endl;  // -1
    cout << cache.get(3) << endl;  // 30
    cout << cache.get(4) << endl;  // 40

    return 0;
}

```

## 📐 Complete Complexity Analysis

Let:

N = number of operations

C = capacity

⏱️ Time Complexity
get(key)

Hash lookup → O(1)

Remove node → O(1)

Insert at front → O(1)

→ O(1)

put(key, value)

Hash lookup → O(1)

Insert / Remove → O(1)

Possible eviction → O(1)

→ O(1)

📊 Overall Time
Case	Complexity
Worst Case	O(1)
Average Case	Θ(1)
Best Case	Ω(1)
📦 Space Complexity

Hash map stores at most C entries

Doubly linked list stores at most C nodes

Metric	Complexity
Auxiliary Space	O(C)
Total Space	O(C)
📊 Formal Asymptotic Notations

Big-O: O(1)

Big-Ω: Ω(1)

Big-Θ: Θ(1)

little-o: o(N)

little-ω: ω(1) (since constant time)

🔐 Eviction Invariant (Critical Design Guarantee)

At all times:

head->next = Most Recently Used

tail->prev = Least Recently Used

Hash map always mirrors DLL nodes

On eviction:

Remove node before tail

Remove key from hash map

Invariant is preserved after every operation.

⚠️ Edge Cases & Annotations

Capacity = 1 works correctly

Updating existing key refreshes recency

Repeated get operations refresh position

No memory leak (evicted nodes deleted)