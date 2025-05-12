#include <vector>
#include <unordered_set>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Creates a set of the input vector.
 * 2. Checks if the given number is the "beginning" of a sequence (ie num-1 is not contained in the set)
 * 3. If it's the "beginning" of a sequence, count the sequence length using while loop
 * 
 * Uses std::unordered_set<>::contains, added in C++20
 * https://en.cppreference.com/w/cpp/container/unordered_set/contains
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
    
        int res = 0;
        for (int num : unique) {
            if (unique.contains(num-1)) continue;
    
            int count = 1;
            while (unique.contains(++num)) ++count;
            res = max(count, res);
        }
        return res;
    }
};