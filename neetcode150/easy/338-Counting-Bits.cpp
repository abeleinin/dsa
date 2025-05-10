#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Create a vector of the hamming weight of values from [0, n]
 * 2. Use efficient way to compute hamming weight:
 *    a. Right shift i by 1 bit — this is equivalent to dividing i by 2
 *       res[i >> 1]
 *    b. Extract least significant bit with (i & 1) - 1 if i is odd, 0 if even
 * 
 *    Example:
 *      res[5] = res[5 >> 1] + (5 & 1)
 *      res[5] = res[101 >> 1] + (101 & 001)
 *      res[5] = res[2] + (1)
 *      res[5] = 1 + 1
 *      res[5] = 2
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 1; i < n+1; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

/**
 * \c BuiltinSolution
 * 
 * 1. Uses `popcnt` (short for population count) instruction
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class BuiltinSolution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 0; i < n+1; i++) {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};