#include <queue>
#include <set>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use the edges of the heights as starting nodes of a graph
 * 2. Perform BFS on each node collecting the set of pacific and alantic nodes
 * 3. Find the intersection of the two sets
 * 
 * Time  : O(m*n)
 * Space : O(m)
 */
class Solution {
public:
    void bfs(const vector<vector<int>>& heights, 
                queue<pair<int, int>>& q,
                set<pair<int, int>>& ocean) {
            
        static const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<pair<int,int>> visited;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
    
            ocean.insert({x, y});
    
            for (int d = 0; d < 4; d++) {
                int dx = x + dir[d][0], dy = y + dir[d][1];
                if (dx >= 0 && dx < heights.size() &&
                    dy >= 0 && dy < heights[0].size() &&
                    !visited.count({dx, dy}) &&
                    heights[x][y] <= heights[dx][dy]) {
                    visited.insert({dx, dy});
                    q.push({dx, dy});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;
    
        int n = heights.size();
        int m = heights[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    pq.push({i, j});
                }
                if (i == n-1 || j == m-1) {
                    aq.push({i, j});
                }
            }
        }
    
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
    
        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);
    
        vector<vector<int>> res;
        for (auto pair : pacific) {
            if (atlantic.find(pair) != atlantic.end()) {
                res.push_back({pair.first, pair.second});
            }
        }
        return res;
    }
};