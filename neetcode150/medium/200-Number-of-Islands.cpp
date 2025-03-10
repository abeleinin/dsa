#include <vector>

using namespace std;

/**
 * \c IterativeSolution
 * 
 * 1. Use iterative dfs on island groups
 * 2. Set values to '0' after visiting
 * 3. Check all 4 adjacent directions and push to the stack
 * 
 * Time  : O(m * n)
 * Space : O(min(m, n))
 */
class IterativeSolution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                
                ++islands;

                // Depth first search
                vector<pair<int, int>> q = {{i, j}};
                while (!q.empty()) {
                    auto [x, y] = q.back();
                    q.pop_back();

                    grid[x][y] = '0';

                    if (x-1 >= 0 && grid[x-1][y] == '1') {
                        q.push_back({x-1, y});
                    } 
                    if (x+1 < n && grid[x+1][y] == '1') {
                        q.push_back({x+1, y});
                    } 
                    if (y-1 >= 0 && grid[x][y-1] == '1') {
                        q.push_back({x, y-1});
                    } 
                    if (y+1 < m && grid[x][y+1] == '1') {
                        q.push_back({x, y+1});
                    }
                }
            }
        }

        return islands;
    }
};

/**
 * \c RecursiveSolution
 * 
 * 1. Use recursive dfs on island groups
 * 2. Set values to '0' after visiting
 * 3. Check all 4 adjacent directions and push to the stack
 * 
 * Time  : O(m * n)
 * Space : O(min(m, n))
 */
class Solution {
public:
    void dfs(vector<vector<char>>& grid, const pair<int, int>& coord) {
        int x = coord.first;
        int y = coord.second;
        if (grid[x][y] == '0') {
            return;
        }
    
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = '0';
    
        if (x-1 >= 0 && grid[x-1][y] == '1') {
            dfs(grid, {x-1, y});
        } 
        if (x+1 < n && grid[x+1][y] == '1') {
            dfs(grid, {x+1, y});
        } 
        if (y-1 >= 0 && grid[x][y-1] == '1') {
            dfs(grid, {x, y-1});
        } 
        if (y+1 < m && grid[x][y+1] == '1') {
            dfs(grid, {x, y+1});
        }
    
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                    
                ++islands;
    
                dfs(grid, {i, j});
            }
        }
    
        return islands;
    }
};