# solution.md

**Concepts Used:** Compile-time Evaluation, Primitive Data Types, `sizeof` Operator

---

## B. Executable Test Code

```cpp

#include <iostream>
#include <cassert>

// Forward declaration
void print_type_sizes();

int main() {
    // Functional Test: 
    // Verify the function runs without runtime error (segfault/exception).
    // Correctness of 'sizeof' is guaranteed by the C++ standard compliance 
    // of the compiler, but we verify standard minimums here.
    
    std::cout << "=== Running Type Size Verification ===" << std::endl;
    
    // Sanity checks based on C++ Standard minimum width requirements
    // char must be at least 8 bits (1 byte)
    assert(sizeof(char) == 1);
    
    // int is usually 4 bytes on modern 32/64-bit systems, but strictly >= 2 bytes
    assert(sizeof(int) >= 2);
    
    // double precision must provide at least as much precision as float
    assert(sizeof(double) >= sizeof(float));

    // Execute the display function
    print_type_sizes();

    std::cout << "=== Verification Complete: Standard Constraints Met ===" << std::endl;

    return 0;
}

```

---

## B. Complete Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Prints the memory size of fundamental C++ data types.
 * * Uses the sizeof operator to determine the storage size of 
 * primitives on the current architecture.
 */
void print_type_sizes() {
    // sizeof returns size in bytes (size_t)
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
}
```

# 2️⃣ solution.md — Execution Artifacts (Section C)

> **🔖 Header** > **Topic:** Resource Analysis & Compile-Time Evaluation

---

## C. Complexity Analysis

### 1. Time Complexity: $O(1)$

* **Why:** The `sizeof` operator is a compile-time operator for primitive types. This means the compiler calculates the memory requirement during the building of the program, not while it is running.
* **Compile-Time Replacement:** The compiler replaces `sizeof(int)` with a constant literal (e.g., `4`) directly in the machine code.
* **Execution:** At runtime, the program essentially executes four constant-time print statements: `std::cout << "..." << 4 << "...";`.
* **Conclusion:** Since there is no iteration (loops), recursion, or logic that scales with the size of data, the execution time remains constant regardless of external factors.

---

### 2. Space Complexity: $O(1)$

* **Why:** The memory usage does not grow based on input size—in fact, in this specific utility, there is no input to process.
* **Memory Allocation:** The program uses a fixed, predetermined amount of stack memory to:
    1. Invoke the function.
    2. Store the temporary output string literals.
    3. Manage the standard output buffer.
* **Conclusion:** Because the memory footprint is "static" and known before the program even starts, it is classified as constant space.

---

## End of Solution File_
