#include <string>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use two-pointer technique to compare beginning and end characters
 * 2. Skip characters that are not isalnum() and compare the tolower() characters
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return true;
        }
        
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }

            if (!isalnum(s[j])) {
                --j;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            ++i;
            --j;
        }

        return true;
    }
};