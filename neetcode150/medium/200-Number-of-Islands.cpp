#include <stack>
#include <queue>

using namespace std;

/**
 * \c IterativeDfsSolution
 * 
 * 1. Use iterative DFS on island groups
 * 2. Set values to '0' immediately after popping
 * 3. Check all 4 adjacent directions and push to the stack
 * 
 * Time  : O(m * n)
 * Space : O(min(m, n))
 */
class IterativeDfsSolution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                
                ++islands;

                // Depth first search
                stack<pair<int, int>> stack;
                stack.push({i, j});
                int x, y;
                while (!stack.empty()) {
                    tie(x, y) = stack.top();
                    stack.pop();

                    grid[x][y] = '0';

                    if (x-1 >= 0 && grid[x-1][y] == '1') {
                        stack.push({x-1, y});
                    } 
                    if (x+1 < n && grid[x+1][y] == '1') {
                        stack.push({x+1, y});
                    } 
                    if (y-1 >= 0 && grid[x][y-1] == '1') {
                        stack.push({x, y-1});
                    } 
                    if (y+1 < m && grid[x][y+1] == '1') {
                        stack.push({x, y+1});
                    }
                }
            }
        }

        return islands;
    }
};

/**
 * \c RecursiveDfsSolution
 * 
 * 1. Use recursive dfs on island groups
 * 2. Set values to '0' immediately upon processing
 * 3. Recursively check all 4 adjacent directions
 * 
 * Time  : O(m * n)
 * Space : O(m * n)
 */
class RecursiveDfsSolution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0') return;
    
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = '0';
    
        if (x-1 >= 0 && grid[x-1][y] == '1') {
            dfs(grid, x-1, y);
        } 
        if (x+1 < n && grid[x+1][y] == '1') {
            dfs(grid, x+1, y);
        } 
        if (y-1 >= 0 && grid[x][y-1] == '1') {
            dfs(grid, x, y-1);
        } 
        if (y+1 < m && grid[x][y+1] == '1') {
            dfs(grid, x, y+1);
        }
    
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                    
                ++islands;
    
                dfs(grid, i, j);
            }
        }
    
        return islands;
    }
};

/**
 * \c IterativeBfsSolution
 * 
 * 1. Use iterative BFS on island groups
 * 2. Set values to '0' after pushing to the queue since neighboring cells
 *    may be processed before it 
 * 3. Check all 4 adjacent directions, push to the queue and mark as visited
 * 
 * Time  : O(m * n)
 * Space : O(min(m, n))
 */
 class IterativeBfsSolution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                    
                ++islands;
    
                // Breath first search
                queue<pair<int, int>> queue;
                queue.push({i, j});
                grid[i][j] = '0';
    
                int x, y;
                while (!queue.empty()) {
                    tie(x, y) = queue.front();
                    queue.pop();
    
                    for (int d = 0; d < 4; ++d) {
                        int dx = x + dir[d][0], dy = y + dir[d][1];
                        if (dx >= 0 && dx < n &&
                            dy >= 0 && dy < m &&
                            grid[dx][dy] == '1') {
                            queue.push({dx, dy});
                            grid[dx][dy] = '0';
                        } 
                    }
                }
            }
        }
    
        return islands;
    }
};