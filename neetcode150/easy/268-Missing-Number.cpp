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
 *    and from [0,nums.size()+1]
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size()+1; i++) {
            res ^= i;
            if (i < nums.size()) res ^= nums[i];
        }
        return res;
    }
};