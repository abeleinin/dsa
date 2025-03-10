#include <vector>

using namespace std;

/**
 * 1. Use iterative dfs on island groups
 * 2. Set values to '0' after visiting
 * 3. Check all 4 adjacent directions and push to the stack
 * 
 * Time  : O(m * n)
 * Space : O(min(m, n))
 */
class Solution {
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

                // depth first search
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