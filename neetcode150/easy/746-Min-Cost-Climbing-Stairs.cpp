#include <vector>

using namespace std;

/**
 * \c Solution
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