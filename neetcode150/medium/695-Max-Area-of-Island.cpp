#include <vector>
#include <queue>
#include <stack>

using namespace std;

/**
 * \c IterativeBfsSolution
 * 
 * 1. Iterate through entire grid 
 * 2. Perform BFS on each island and compare its size to the current max island
 * 3. Return the largest island found
 * 
 * Time  : O(m * n)
 * Space : O(min(m * n, k))
 */
class IterativeBfsSolution {
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
    
                // Breath first search
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
    
                    for (int d = 0; d < 4; ++d) {
                        int dx = x + dir[d][0], dy = y + dir[d][1];
                        if (dx >= 0 && dx < n && 
                            dy >= 0 && dy < m && 
                            grid[dx][dy] == 1) {
                            grid[dx][dy] = 0;
                            q.push({dx, dy});
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


/**
 * \c IterativeDfsSolution
 * 
 * 1. Iterate through entire grid
 * 2. Perform DFS on each island and compare its size to the current max island
 * 3. Return the largest island found
 * 
 * Time  : O(m * n)
 * Space : O(m * n)
 */
class IterativeDfsSolution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                    
                grid[i][j] = 0;
                st.push({i, j});
                int curr = 1;
                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();
    
                    for (int d = 0; d < 4; d++) {
                        int dx = x + dir[d][0], dy = y + dir[d][1];
                        if (dx >= 0 && dx < n &&
                            dy >= 0 && dy < m &&
                            grid[dx][dy] == 1) {
                            grid[dx][dy] = 0;
                            st.push({dx, dy});
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

/**
 * \c RecursiveDfsSolution
 * 
 * 1. Iterate through entire grid
 * 2. Perform recursive DFS on each island and compare its size to the current max island
 * 3. Return the largest island found
 * 
 * Time  : O(m * n)
 * Space : O(m * n)
 */
class RecursiveDfsSolution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        grid[x][y] = 0; 
        int area = 1;
    
        for (int d = 0; d < 4; d++) {
            int dx = x + dir[d][0], dy = y + dir[d][1];
            if (dx >= 0 && dx < n &&
                dy >= 0 && dy < m &&
                grid[dx][dy] == 1) {
                area += dfs(grid, dx, dy);
            }
        }
    
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                    
                int islands = dfs(grid, i, j);
                res = max(res, islands);
            }
        }
        return res;
    }
};
