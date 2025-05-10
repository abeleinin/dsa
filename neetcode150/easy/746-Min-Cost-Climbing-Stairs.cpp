#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use bottom-up dynamic programming approach
 * 2. From step i, your total cost is:
 *     - the cost of stepping on stair i plus
 *     - the cheaper of jumping 1 or 2 steps forward.
 * 
 *     Example:
 *        Given: cost = [10, 15, 20]
 * 
 *        Append 0: cost = [10, 15, 20, 0]
 * 
 *        i = 1:
 *          cost[1] += min(cost[2], cost[3]) -> 15 + min(20, 0) = 15
 * 
 *        i = 0:
 *          cost[0] += min(cost[1], cost[2]) -> 10 + min(15, 20) = 25
 * 
 *        Finally:
 *          min(cost[0], cost[1]) = min(25, 15) = 15
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        
        for (int i = cost.size() - 3; i > -1; i--) {
            cost[i] += min(cost[i+2], cost[i+1]);
        }
        
        return min(cost[0], cost[1]);
    }
};