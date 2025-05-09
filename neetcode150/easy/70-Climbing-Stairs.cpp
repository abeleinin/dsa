#include <unordered_map>

using namespace std;

/**
 * \c MapSolution
 * 
 * 1. Create a map containing base cases for 1 and 2 stairs
 * 2. Base case becomes if the number is within the map
 * 3. Cache each nth stair in the map
 * 4. Return the result
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class MapSolution {
public:
    unordered_map<int, int> mp = {{1, 1}, {2, 2}};
    
    int climbStairs(int n) {
        if (mp.find(n) != mp.end()) return mp[n];
    
        mp[n] = climbStairs(n-1) + climbStairs(n-2);
    
        return mp[n];
    }
};

/**
 * \c OptimalSolution
 * 
 * 1. Keep track of the prev and curr value
 * 2. For each stair, save curr as temp, update curr from prev, update prev from temp
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class OptimalSolution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int temp = 0;
        int curr = 1;
        int prev = 0;

        for (int i = 1; i <= n; i++) {
            temp = curr;
            curr += prev;
            prev = temp;
        }

        return curr;
    }
};