#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Perform prefix product of the values from 1 to n-1 and set n to that value
 * 2. Perform a suffix product of the values from i+1 to n and multiply that with n
 * 
 * Time  : O(n)
 * Space : O(1)
 * (output array doesn't count as extra space)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
    
        // Prefix sum
        int curr = 1;
        for (int i = 0; i < n; i++) {
            output[i] = curr;
            curr *= nums[i];
        }
    
        // Suffix sum
        curr = 1;
        for (int i = n-1; i > -1; i--) {
            output[i] *= curr;
            curr *= nums[i];
        }
    
        return output;
    }
};