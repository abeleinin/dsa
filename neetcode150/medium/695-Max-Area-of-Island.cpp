#include <vector>
#include <queue>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Iterate through entire grid and perform dfs on each island
 * 
 * Time  : O(m * n)
 * Space : O(min(m * n, k))
 */
class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int res = 0;
            int n = grid.size();
            int m = grid[0].size();
    
            queue<pair<int, int>> q;
            static const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
    
                    int curr = 1;
                    grid[i][j] = 0;
                    q.push({i, j});
    
                    // bfs
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
    
                        for (int d = 0; d < 4; ++d) {
                            int nx = x + dir[d][0], ny = y + dir[d][1];
                            if (nx >= 0 && nx < n && 
                                ny >= 0 && ny < m && 
                                grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                                ++curr;
                            }
                        }
                    }
                    res = max(res, curr);
                }
            }
            return res;
        }
    };