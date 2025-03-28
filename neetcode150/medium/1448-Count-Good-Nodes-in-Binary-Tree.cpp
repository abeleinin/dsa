#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * \c Solution1
 * 
 * 1. 
 * 
 * Time  : O(n)
 * Space : O(w)
 */
class Solution1 {
public:
    int res = 0;
    void dfs(TreeNode* curr, int currMax) {
        if (!curr) {
            return;
        }
    
        if (curr->val >= currMax) {
            res++;
        }
    
        dfs(curr->left, max(currMax, curr->val));
        dfs(curr->right, max(currMax, curr->val));
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};

/**
 * \c Solution2
 * 
 * 1. 
 * 
 * Time  : O(n)
 * Space : O(w)
 */
class Solution2 {
public:
    int dfs(TreeNode* curr, int currMax) {
        if (!curr) {
            return 0;
        }
    
        int count = (curr->val >= currMax) ? 1 : 0;
    
        int val = max(currMax, curr->val);
    
        count += dfs(curr->left, val);
        count += dfs(curr->right, val);
            
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
