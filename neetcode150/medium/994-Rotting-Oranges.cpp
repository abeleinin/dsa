#include <vector>
#include <queue>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Iterate through the grid identifying:
 *    - Number of fresh oranges
 *    - Push rotten oranges to queue for processing
 * 2. Perform BFS on the rotten oranges expanding in each coordinate direction
 * 3. Condition the processing on the size of the queue, to keep track of how
 *    many "minutes" have passed (This is what the inner while loop does)
 * 4. As we push to the queue we decrement the fresh counter and at the end 
 *    return the "minutes" or -1 if fresh oranges still remain
 * 
 * Time  : O(m*n)
 * Space : O(m*n)
 */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        int fresh = 0;
        queue<pair<int, int>> q;        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;
    
                if (grid[i][j] == 1) {
                    ++fresh;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
    
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
    
                for (int d = 0; d < 4; d++) {
                    int dx = x + dir[d][0], dy = y + dir[d][1];
                    if (dx >= 0 && dx < n &&
                        dy >= 0 && dy < m &&
                        grid[dx][dy] == 1) {
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                        --fresh;
                    }
                }
            }
    
            if (!q.empty()) minutes++;
        }
    
        return fresh == 0 ? minutes : -1;
    }
};