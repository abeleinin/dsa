#include <vector>
#include <map>
using namespace std;

/**
 * \c Solution
 * 
 * 1. Create a map of target-num[i] to index
 * 2. Check if the current number is in the map
 * 3. Return the index pair
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> targetNumDiff;

        for(int i = 0; i < nums.size(); ++i){
            if(targetNumDiff.find(nums[i]) != targetNumDiff.end()){
                return vector<int>({targetNumDiff[nums[i]], i});
            }

            targetNumDiff[target - nums[i]] = i;
        }    

        return vector<int>();
    }
};