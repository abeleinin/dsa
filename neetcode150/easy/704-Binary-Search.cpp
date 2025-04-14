#include <vector>
using namespace std;

/**
 * \c IterativeSolution
 * 
 * 1. Use two pointers
 * 2. Calculate middle as (high + low) / 2
 * 3. Update low or high depending on whether curr is greater or less than target (use middle)
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class IterativeSolution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
    
        int curr, mid;
        while (low <= high) {
            mid = (high + low) / 2;
            curr = nums[mid];
                
            if (curr == target) return mid;
                
            if (curr < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

/**
 * \c RecursiveSolution
 * 
 * 1. Use recursive util function with high/low pointers
 * 2. Calculate middle value from high/low
 * 3. Update high/low in recursive calls dependent on whether curr is greater or less than target (use middle)
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class RecursiveSolution {
public:
    int recursive_search(vector<int>& nums, int target, int low, int high) {
        int curr, mid;
        if (low <= high) {
            mid = (high + low) / 2;
            curr = nums[mid];
    
            if (curr == target) return mid;
    
            if (curr < target) {
                return recursive_search(nums, target, mid+1, high);
            } else {
                return recursive_search(nums, target, low, mid-1);
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return recursive_search(nums, target, 0, nums.size()-1);
    }
};