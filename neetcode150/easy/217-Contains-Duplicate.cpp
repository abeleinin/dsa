#include <vector>
#include <unordered_set>
using namespace std;

/**
 * \c SortSolution
 * 
 * 1. Sort the numbers
 * 2. Check if the consecutive elements are the same
 * 
 * Time  : O(n log n)
 * Space : O(1)
 */
class SortSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i+1]) return true;
        }

        return false;
    }
};

/**
 * \c SetSolution
 * 
 * 1. Use a std::unordered_set
 * 2. std::unordered_set::insert returns pair<iterator, bool>, when pair::second is true 
 *    the new element was sucessfully inserted (meaning it is not in the set)
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class SetSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
    
        for (int n : nums) {
            auto [_, inserted] = seen.insert(n);
            if (!inserted) return true;
        }
    
        return false;
    }
};