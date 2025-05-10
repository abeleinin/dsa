#include <cstdint>

/**
 * \c Solution
 * 
 * 1. Use left shift operator on result and right shift operator on n
 * 2. Use the AND (&) operator to check if the least significant bit is set in n
 * 3. Use OR (|) to append that bit to the result
 * 
 * Example:
 *    n = 010110 (binary) -> reverse = 011010
 * 
 *    Step-by-step:
 *      res = 0
 * 
 *      i = 0:
 *        res <<= 1      -> 000000
 *        res |= n & 1   -> 0 | 0 = 0
 *        n >>= 1        -> 001011
 * 
 *      i = 1:
 *        res <<= 1      -> 000000
 *        res |= n & 1   -> 0 | 1 = 1
 *        n >>= 1        -> 000101
 * 
 *      i = 2:
 *        res <<= 1      -> 000010
 *        res |= n & 1   -> 2 | 1 = 3 (000011)
 *        n >>= 1        -> 000010
 * 
 *      i = 3:
 *        res <<= 1      -> 000110
 *        res |= n & 1   -> 0 (still 000110)
 *        n >>= 1        -> 000001
 * 
 *      i = 4:
 *        res <<= 1      -> 001100
 *        res |= n & 1   -> 1 = 001101
 *        n >>= 1        -> 000000
 * 
 *      i = 5:
 *        res <<= 1      -> 011010
 *        res |= n & 1   -> 0 (no change)
 * 
 *      ...
 *      (remaining bits are zero, res shifts left 1 each time)
 * 
 * Final res = 00000000 00000000 00000000 011010 (decimal: 26)
 * 
 * Time  : O(32)
 * Space : O(1)
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }
        return res;
    }
};