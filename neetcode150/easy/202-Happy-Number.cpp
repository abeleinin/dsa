#include <set>

using namespace std;

/**
 * \c SetSolution
 * 
 * 1. Use a set to maintain values that have been processed (possible cycles)
 * 2. Perform the happy number computation and update n
 * 3. Return false if the set contains n
 * 
 * Time  : O(log n)
 * Space : O(n)
 */
class SetSolution {
public:
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1) {
            if (seen.contains(n)) return false;
            seen.insert(n);

            int tot = 0; 
            while (n > 0) {
                tot += pow(n%10, 2);
                n /= 10;
            }
            n = tot;
        }
        return true;
    }
};

/**
 * \c OptimalSolution
 * 
 * 1. Use Floyd's cycle detection algorithm
 * 2. Define a single step of the happy number computation as a util function
 * 3. Compute a fast and slow solution
 * 4. Break if the pointers are the same
 * 5. Return fase == 1
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class OptimalSolution {
public:
    int compute(int n) {
        int tot = 0; 
        while (n > 0) {
            tot += pow(n%10, 2);
            n /= 10;
        }
        return tot;
    }
        
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
    
        while (fast != 1) {
            slow = compute(slow);
            fast = compute(compute(fast));
    
            if (fast == slow) {
                break;
            }
        }
    
        return fast == 1;
    }
};