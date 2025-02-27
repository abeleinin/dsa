#include <set>
#include <string>

using namespace std;

/**
 * \c Solution1
 * 
 * 1. Check insertion into a set to determine when a character collision occurs.
 * 2. You don't know the position of the conflicting char, so you have to use while not equal to determine location
 * 3. Incremenet both i and j when coflict otherwise just j
 * 4. Use (int)chars.size() to determine current substring length
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        set<char> chars;

        int i = 0;
        int j = 0;
        while (j < s.size()){
            auto [_, inserted] = chars.insert(s[j]);
            if (!inserted) {
                while (s[i] != s[j]) {
                    chars.erase(s[i]);
                    ++i;
                }
                ++i;
            } 
            res = max(res, (int)chars.size());
            j++;
        }
        return res;
    }
};