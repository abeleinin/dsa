#include <map>
#include <string>
using namespace std;

/**
 * \c Solution
 * 
 * 1. Create an array of all 26 letters
 *   - increment for characters in string s
 *   - decrement for characters in string t
 * 2. Check if the count array contains any non zero values
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int count[26];
        for (int i = 0; i < s.size(); i++) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        
        for (int i : count) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }
};