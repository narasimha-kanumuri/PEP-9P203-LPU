<!--
Following Problem_Instructions.md, start generating second problem from Set1-ProgramList.md, which is House Robber with Circular Alarm

House robber problem,
but first and last houses are connected by alarm wire.
*(Twist: circular DP split case)*
-->

# Problem: House Robber with Circular Alarm

### 🔖 Concepts Involved

- Dynamic Programming (DP), Circular Arrays, State Transition, Local vs. Global Optimization

---

### 📖 Problem Story / Context

- You are a professional robber planning to rob houses along a street. 
- Each house has a certain amount of money stashed.
- **The Constraint:**
- All houses at this place are arranged in a circular manner.
- If two adjacent houses are robbed, the alarm will go off.
- **Goal:**
- Determine the maximum amount of money you can rob tonight **without alerting the police**.
- **Twist:** The first and last houses are also adjacent due to the circular arrangement, so you cannot rob both the first and last house.

### 🧩 Problem Breakdown

- Let `n` be the number of houses.
- Let `nums` be an array where `nums[i]` represents the amount of money in the `i`-th house.
- **Case 1:** Rob houses from `0` to `n-2` (exclude the last house).
- **Case 2:** Rob houses from `1` to `n-1` (exclude the first house).
- The answer is the maximum of the two cases.

### Test cases with trace and expected output(in depth):

#### Test Case 1:

- **Input:** `nums = [2, 3, 2]`
- **Output:** `3`
- **Explanation:**
  - Case 1: Rob houses `0` and `1` → Total = `2 + 3 = 5` (Invalid, adjacent)
  - Case 2: Rob house `1` → Total = `3`
  - Maximum = `3`
  - Robbing the first and last house together is not possible due to the circular arrangement.
  - Thus, the maximum amount that can be robbed is `3`.
  - The optimal strategy is to rob the second house only.

#### Test Case 2:

- **Input:** `nums = [1, 2, 3, 1]`
- **Output:** `4`

- **Explanation:**
  - Case 1: Rob houses `0`, `2` → Total = `1 + 3 = 4`
  - Case 2: Rob houses `1`, `3` → Total = `2 + 1 = 3`
  - Maximum = `4`
  - The optimal strategy is to rob the first and third house, yielding a total of `4`.
  
#### Test Case 3(edge case):

- **Input:** `nums = [0]`
- **Output:** `0`
- **Explanation:**
  - There is only one house with no money.
  - The maximum amount that can be robbed is `0`.  
  

## Cpp Solution:

```cpp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Helper function to calculate max rob amount for linear houses
        auto robLinear = [&](int start, int end) {
            int prev2 = 0; // dp[i-2]
            int prev1 = 0; // dp[i-1]
            for (int i = start; i <= end; ++i) {
                int current = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = current;
            }
            return prev1;
        };
        
        // Case 1: Rob from house 0 to n-2
        int case1 = robLinear(0, n - 2);
        // Case 2: Rob from house 1 to n-1
        int case2 = robLinear(1, n - 1);
        
        return max(case1, case2);
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums) << endl; // Output: 4
}

//
```

## Line by line code explanation in tabular format:

| Line Number | Code Snippet | Explanation |
|-------------|--------------|-------------| 

| 1-2 | `class Solution {`<br>`public:` | Defines a class named `Solution` with public access specifier. | 
| 3 | `int rob(vector<int>& nums) {` | Declares a member function `rob` that takes a reference to a vector of integers and returns an integer. This function will contain the main logic to solve the problem. |
| 4 | `int n = nums.size();` | Stores the size of the input vector `nums` in variable `n`. |
| 5 | `if (n == 1) return nums[0];` |
Checks if there is only one house. If true, returns the amount of money in that house since it's the only option. |
| 7-14 | `auto robLinear = [&](int start, int end) { ... };` | Defines a lambda function `robLinear` that calculates the maximum amount of money that can be robbed from a linear arrangement of houses between indices `start` and `end`. |
| 8 | `int prev2 = 0;` | Initializes `prev2` to store the maximum amount robbed from the house two steps back. |
| 9 | `int prev1 = 0;` | Initializes `prev1`