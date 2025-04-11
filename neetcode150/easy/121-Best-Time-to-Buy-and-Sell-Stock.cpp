#include <vector>

using namespace std;

/**
 * \c Solution1
 * 
 * 1. Maintain min_val within current window, if you find a smaller value update 
 * 2. Keep track of the max profit
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int curr = prices[i] - min_val;
            if (curr > profit) {
                profit = curr;
            } else if (prices[i] < min_val) {
                min_val = prices[i];
            }
        }
        return profit;
    }
};