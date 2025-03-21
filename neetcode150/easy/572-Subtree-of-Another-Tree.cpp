#include <algorithm>

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
 * \c Solution
 * 
 * 1. Create isSameTree helper function (leetcode 100)
 * 2. Use early return if the trees are the same
 * 3. Otherwise, check if the left or right children of root are the same as the subRoot
 * 
 * Time  : O(mn)
 * Space : O(height of root)
 */
class Solution {
public:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return !t1 && !t2;
    
        if (t1->val != t2->val) return false;
    
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
    
        // early return saves uneccassary recursive calls
        if (isSameTree(root, subRoot)) return true;
    
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};