#include <vector>
#include <queue>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use iterative BFS from the 'O's on the 4 edges of the board
 * 2. Mark all 'O's connect to these edge 'O's with a temporary 
 *    value denoting that they're not surrounded by 'X's
 * 3. Iterate through the entire board replaces 'E's with 'O's and 
 *    all remaining 'O's (the surrounded ones) with 'X's
 * 
 * Time  : O(m*n)
 * Space : O(1)
 */
class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
    
        queue<pair<int, int>> q;
        q.push({i, j});
    
        board[i][j] = 'E';
    
        static const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
    
            for (int d = 0; d < 4; d++) {
                int dx = x + dir[d][0], dy = y + dir[d][1];
                if (dx >= 0 && dx < n &&
                    dy >= 0 && dy < m &&
                    board[dx][dy] == 'O') {
                    board[dx][dy] = 'E';
                    q.push({dx, dy});
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
    
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][m-1] == 'O') bfs(board, i, m-1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[n-1][j] == 'O') bfs(board, n-1, j);
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};