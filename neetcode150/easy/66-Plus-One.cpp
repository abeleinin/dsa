#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Iterate through the digits in reverse
 * 2. If the value is less than 10 then we know there isn't a carry 
 *    digit and we can return 
 * 3. Otherwise, we have to carry a digit, so set the currenet value 
 *    to 0 and continue
 * 4. If we exit the for loop it means we've processed the entire 
 *    input and still have a carry value, so we must insert it at 
 *    the beginning of the input
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i > -1; i--) {
            if (++digits[i] < 10) {
                return digits;
            }
            digits[i] = 0;
        }
    
        digits.insert(digits.begin(), 1);
    
        return digits;
    }
};