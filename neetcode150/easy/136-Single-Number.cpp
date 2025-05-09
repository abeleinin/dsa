#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Solve using bitwise XOR op and the following properties:
 * 
 *    a ^ a = 0 
 *    a ^ 0 = a
 * 
 * 2. Therefore, the solution is simply using XOR over the input
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};