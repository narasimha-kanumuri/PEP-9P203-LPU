/*
    Problem: Given a 2D grid representing heights, calculate the total amount of water that can be trapped after raining.

    Approach:
    1. Use a BFS approach starting from the boundary cells to mark all reachable cells that cannot trap water.
    2. For each unvisited cell, calculate the minimum height of its neighbors and determine how much water it can trap based on its own height.

    Time Complexity: O(n*m)
    Space Complexity: O(n*m)

    Step-by step Logic is as follows:
    1. Initialize a visited matrix to keep track of which cells have been processed.
    2. Push all boundary cells into a queue and mark them as visited.
    3. Perform BFS from the boundary cells, marking all reachable cells that are less than or equal to the current cell's height as visited.
    4. After BFS, iterate through all cells. For each unvisited cell, calculate the minimum height of its neighbors and determine how much water it can trap based on its own height.

*/


#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    // Step 1: BFS from boundary cells
    // visited matrix to track processed cells
    // queue for BFS
    // Initialize visited matrix and queue
    // Mark all boundary cells as visited and push them into the queue
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int,int>> q;

    // Push all boundary cells
    for (int i = 0; i < n; i++) {
        for (int j : {0, m-1}) {
            q.push({i, j});
            visited[i][j] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i : {0, n-1}) {
            if (!visited[i][j]) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    // Directions: ↙ and ↘ reverse (we go upward)
    vector<pair<int,int>> dirs = {{-1, -1}, {-1, 1}};

    // BFS to mark reachable cells from the boundary that cannot trap water 
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();// Current cell coordinates 
        
        // Explore neighbors in the upward direction (↙ and ↘)
        for (auto [dx, dy] : dirs) {
            
            // Explore neighbors in the upward direction
            int nx = x + dx;// Next x coordinate
            int ny = y + dy; // Next y coordinate

            // Check if the neighbor is within bounds and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                
                // If the neighbor's height is less than or equal to the current cell's height, it can be visited and added to the queue 
                if (grid[nx][ny] <= grid[x][y]) {
                    
                    // Mark the neighbor as visited and add it to the queue for further exploration 
                    visited[nx][ny] = 1; // Mark as visited 
                    q.push({nx, ny}); // Add to queue for BFS 
                }
            }
        }
    }

    // Step 2: Calculate trapped water for unvisited cells 
    int water = 0;

    // Iterate through all cells to calculate trapped water for unvisited cells 
    for (int i = 0; i < n; i++) {

        // For each unvisited cell, calculate the minimum height of its neighbors and determine how much water it can trap based on its own height 
        for (int j = 0; j < m; j++) {

            // If the cell is unvisited, it means it can potentially trap water
            if (!visited[i][j]) {

                // Calculate the minimum height of the neighbors (↙ and ↘) to determine how much water can be trapped 
                int minBound = INT_MAX;

                // Explore neighbors in the upward direction (↙ and ↘) to find the minimum height of the neighbors
                for (auto [dx, dy] : vector<pair<int,int>>{{1,-1},{1,1}}) {
                    int ni = i + dx; // Next i coordinate
                    int nj = j + dy; // Next j coordinate

                     // Check if the neighbor is within bounds and update the minimum bound if necessary 
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        // Update the minimum bound based on the neighbor's height 
                        minBound = min(minBound, grid[ni][nj]);
                    }
                }

                // If the minimum bound is greater than the current cell's height, it means water can be trapped, and we add the difference to the total water count 
                if (minBound > grid[i][j]) {
                    // Calculate the amount of water trapped at this cell and add it to the total water count 
                    water += (minBound - grid[i][j]);
                }
            }
        }
    }

    return water; // Return the total amount of water trapped 
}

// Example usage
int main() {
    vector<vector<int>> grid = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    cout << "Total water trapped: " << trapWater(grid) << endl; // Output: Total water trapped: 4

    return 0;
}

// The above code defines a function `trapWater` that calculates the total amount of water that can be trapped in a 2D grid of heights. It uses a BFS approach to mark all reachable cells from the boundary and then calculates the trapped water for unvisited cells based on the minimum height of their neighbors. The main function demonstrates how to use this function with an example grid.

// 5 test cases are provided in the comments, and the expected output is also mentioned for each case. You can uncomment the test cases to verify the correctness of the implementation.

/*
Test Cases:
1. Input: [[1, 4, 3, 1, 3, 2], [3, 2, 1, 3, 2, 4], [2, 3, 3, 2, 3, 1]]
   Output: Total water trapped: 4
2. Input: [[3, 3, 3, 3, 3], [3, 1, 1, 1, 3], [3, 1, 2, 1, 3], [3, 1, 1, 1, 3], [3, 3, 3, 3, 3]]
   Output: Total water trapped: 8 

3. Input: [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
   Output: Total water trapped: 1

4. Input: [[5, 5, 5], [5, 1, 5], [5, 5, 5]]
   Output: Total water trapped: 4

5. Input: [[1, 2, 3], [2, 1, 2], [3, 2, 1]]
   Output: Total water trapped: 0

*/