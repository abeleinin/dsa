#include <vector>
#include <map>
#include <set>

using namespace std;

/**
 * \c MapSolution
 * 
 * 1. Create maps for each suduko criteria (rows, cols, 3x3 boxes)
 * 2. Iterate through the board and insert each value into the 3 sets
 * 3. For rows and cols the key is simply i and j, but for the 3x3 boxes
 *    we create create a pair using integer division (yes, pairs are hashable)
 * 4. Check if there's a conflict when inserting a given value (if there's a
 *    conflict it means that value is already in the set making the board invalid)
 * 
 * Time  : O(1)
 * Space : O(1)
 */
class MapSolution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> row;
        unordered_map<int, set<int>> col;
        unordered_map<pair<int, int>, set<int>> box;
    
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
    
                pair<int, int> boxKey = {i/3, j/3};
                auto [_, rowIn] = row[i].insert(val);
                auto [_, colIn] = col[j].insert(val);
                auto [_, boxIn] = box[boxKey].insert(val);
                if (!rowIn || !colIn || !boxIn) return false;
            }
        }
    
        return true;
    }
};

/**
 * \c VectorSolution
 * 
 * 1. Create vectors for each suduko criteria (rows, cols, 3x3 boxes)
 * 2. Use bitmasking to set 9 bits from (0-8) for each of the criteria vectors
 * 3. If there's a conflift by using bitwise AND on the bit positions 
 *    of the given value
 * 
 *    Example:
 *       row[0] = 000000000 
 * 
 *       row[0] |= (1 << 5)
 *       row[0] |= 000100000
 *       row[0]  = 000100000
 * 
 *       row[0] |= (1 << 3)
 *       row[0] |= 000001000
 *       row[0]  = 000101000
 * 
 *       row[0] |= (1 << 7)
 *       row[0] |= 010000000
 *       row[0]  = 010101000
 * 
 * Bit positions: [8][7][6][5][4][3][2][1][0]
 *                 0  1  0  1  0  1  0  0  0
 * Digits seen :      7     5     3
 * 
 * Time  : O(1)
 * Space : O(1)
 */
class VectorSolution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> box(9, 0);
    
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
    
                int boxIndex = (i/3) * 3 + (j/3);
                if (row[i] & (1 << val) ||
                    col[j] & (1 << val) ||
                    box[boxIndex] & (1 << val)) {
                    return false;
                }
    
                row[i] |= (1 << val);
                col[j] |= (1 << val);
                box[boxIndex] |= (1 << val);
            }
        }
    
        return true;
    }
};