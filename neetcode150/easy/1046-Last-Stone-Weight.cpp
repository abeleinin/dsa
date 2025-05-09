#include <queue>
#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Create a max heap with all the stones
 * 2. Play the game (smashing the to 2 largest stones) until 1 stone remains
 * 3. Return the 0 if the heap is empty, otherwise return the last stone
 * 
 * Time  : O(n log n)
 * Space : O(n)
 */
class Solution {
public:
    priority_queue<int> maxh;
    
    int lastStoneWeight(vector<int>& stones) {
        for (int s : stones) maxh.push(s);
    
        while (maxh.size() > 1) {
            int y = maxh.top(); maxh.pop();
            int x = maxh.top(); maxh.pop();
    
            if (x != y) maxh.push(y-x);
        }
    
        if (maxh.empty()) return 0;
    
        return maxh.top();
    }
};