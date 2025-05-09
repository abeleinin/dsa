/**
 * \c KernighanSolution
 * 
 * 1. Use Brian Kernighan's algorithm
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class KernighanSolution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

/**
 * \c BuiltinSolution
 * 
 * 1. Uses `popcnt` (short for population count) instruction
 * 
 * Time  : O(1)
 * Space : O(1)
 */
class BuiltinSolution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};