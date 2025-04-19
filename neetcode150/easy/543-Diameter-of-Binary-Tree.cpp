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
 * \c Solution
 * 
 * 1. Use dfs
 * 2. Maintain a global maxDiameter
 * 3. The current depth is the depth of the left and right j
 * 4. return max(left, right) + 1, to compute the diameter through a node
 * 
 * Time  : O()
 * Space : O()
 */
class Solution {
public:
    int maxDiameter = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
            
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxDiameter = max(maxDiameter, right + left);
    
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};