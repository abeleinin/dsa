#include <vector>

using namespace std;

/**
 * \c Solution1
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int price = 0;
        for(int i = 1; i < prices.size(); i++){
            int curr = prices[i] - min_val;
            if(curr > price){
                price = curr;
            } else if(prices[i] < min_val){
                min_val = prices[i];
            }
        }
        return price;
    }
};

/**
 * \c Solution2
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr = 0;

        int i = 0;
        int j = 1;
        while (j <= prices.size()-1) {
            if (prices[i] < prices[j]) {
                curr = prices[j] - prices[i];
            } else {
                i = j;
            }
            res = max(res, curr);
            ++j;
        }
        return res;
    }
};