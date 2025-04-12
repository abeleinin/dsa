#include <stack>
#include <string>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Push open parens to stack
 * 2. On closed paren check if stack.top is the open paren
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char p : s) {
            if (p == '(' || p == '[' || p == '{') {
                st.push(p);
            } else if (st.empty()) {
                return false;
            } else if (p == ')' && st.top() != '(') {
                return false;
            } else if (p == ']' && st.top() != '[') {
                return false;
            } else if (p == '}' && st.top() != '{') {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};