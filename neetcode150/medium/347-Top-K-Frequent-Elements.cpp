#include <vector>
#include <map>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Create frequency count map for each value in the input
 * 2. Sort these frequencies using bucket sort where the 
 *    number of buckets is the size of the input+1
 * 3. Since the answer is guaranteed to be unique we can 
 *    reverse iterate through the buckets until k is 0
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
    
        for (int n : nums) {
            counts[n]++;
        }
    
        vector<vector<int>> bin(nums.size()+1);
        for (auto [key, val] : counts) {
            bin[val].push_back(key);
        }
    
        vector<int> res;
        for (int i = bin.size()-1; i > -1; --i) {
            for (int n : bin[i]) {
                res.push_back(n);
                --k;
                if (k == 0) return res;
            }
        }
        return res;
    }
};