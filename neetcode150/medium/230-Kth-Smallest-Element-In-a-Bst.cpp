#include <vector>

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
 */
class Solution1 {
public:
    vector<int> res;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
    
        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // in order traversal - left, node, right
        dfs(root);
        return res[k-1];
    }
};

/**
 * \c Solution2
 * 
 * 
 * 
 */
class Solution2 {
public:
    int res;
    
    void dfs(TreeNode* node, int& k) {
        if (!node) {
            return;
        }
    
        dfs(node->left, k);
    
        k--;
        if (k == 0) {
            res = node->val;
            return;
        }
    
        dfs(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};