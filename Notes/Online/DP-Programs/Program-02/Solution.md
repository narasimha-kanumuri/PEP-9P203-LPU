<!--
cpp implementation for 01.program.md which is the house robber problem. The code uses a space optimized dynamic programming approach to calculate the maximum amount of money that can be robbed without robbing two adjacent houses.

ALso, include, all the list of cpp concepts, ds concepts with brief in depth(NOT LONG) explanation used in the code.
-->

# 🏠 House Robber Problem Cpp implementation

```cpp

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        int prev2 = nums[0]; // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]
        
        for (int i = 2; i < nums.size(); i++) {
            int current = max(prev1, prev2 + nums[i]); // dp[i]
            prev2 = prev1; // update dp[i-2] for next iteration
            prev1 = current; // update dp[i-1] for next iteration
        }
        
        return prev1; // The last computed value is the answer
    }
};

//main function to test the implementation
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int result = sol.rob(nums);
    // Output the result
    return 0;
}

```

## C++ Concepts Used like builtin functions, libraries, & kind of symbols used in clean tabular format:

| Concept | Explanation |
| --- | --- |
| `#include <vector>` | This is a preprocessor directive that includes the vector library, which allows us to use the `std::vector` container for dynamic arrays. |
| `using namespace std;` | This line allows us to use standard library features without prefixing them with `std::`. It simplifies code readability. |
| `class Solution` | Defines a class named `Solution` which contains the method to solve the problem. This is a common practice in competitive programming and coding interviews. |
| `int rob(vector<int>& nums)` | This is a member function of the `Solution` class that takes a reference to a vector of integers as input and returns an integer. It implements the logic to solve the House Robber problem. |
| `if (nums.empty()) return 0;` | This checks if the input vector is empty and returns 0 if true, as there are no houses to rob. |
| `if (nums.size() == 1) return nums[0];` | This checks if there is only one house and returns its value, as that would be the maximum amount that can be robbed. |
| `int prev2 = nums[0];` | Initializes `prev2` to the value of the first house, representing the maximum amount that can be robbed from the first house. |
| `int prev1 = max(nums[0], nums[1]);` | Initializes `prev1` to the maximum of the first two houses, representing the maximum amount that can be robbed from the first two houses. |
| `for (int i = 2; i < nums.size(); i++)` | This loop iterates through the houses starting from the third house (index 2) to calculate the maximum amount that can be robbed up to each house. |
| `int current = max(prev1, prev2 + nums[i]);` | This calculates the maximum amount that can be robbed at the current house by comparing the amount robbed from the previous house (`prev1`) and the amount robbed from two houses back plus the current house's value (`prev2 + nums[i]`). |
| `prev2 = prev1;` | Updates `prev2` to the value of `prev1` for the next iteration, effectively shifting the window of consideration for the next house. |
| `prev1 = current;` | Updates `prev1` to the value of `current` for the next iteration, representing the maximum amount that can be robbed up to the current house. |
| `return prev1;` | After the loop, `prev1` contains the maximum amount that can be robbed from all the houses, which is returned as the final result. |

## Data Structures Concepts Used:

| Concept | Explanation |
| --- | --- |
| `vector<int>` | A dynamic array that can resize itself automatically when elements are added or removed. It is part of the C++ Standard Library and provides efficient access and modification of elements. 


## Cpp implementation with modified output

### Also print the houses that are robbed to achieve the maximum amount.

```cpp

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        int prev2 = nums[0]; // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]
        vector<int> robbedHouses; // To keep track of robbed houses
        
        for (int i = 2; i < nums.size(); i++) {
            int current = max(prev1, prev2 + nums[i]); // dp[i]
            if (current == prev1) {
                // If we choose not to rob the current house
                robbedHouses.push_back(i - 1); // Add the previous house to the list
            } else {
                // If we choose to rob the current house
                robbedHouses.push_back(i); // Add the current house to the list
            }
            prev2 = prev1; // update dp[i-2] for next iteration
            prev1 = current; // update dp[i-1] for next iteration
        }
        
        cout << "Robbed Houses: ";
        for (int house : robbedHouses) {
            cout << house << " ";
        }
        cout << endl;
        
        return prev1; // The last computed value is the answer
    }
};

//main function to test the implementation
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int result = sol.rob(nums);
    cout << "Maximum Amount Robbed: " << result << endl;
    return 0;
}

```

