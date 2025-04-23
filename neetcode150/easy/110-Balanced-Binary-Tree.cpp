#include <algorithm>
#include <queue>

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
 * \c RecursiveSolution
 * 
 * 1. Compute height it bottom-up, returning early if an imbalance is found
 * 2. Helper returns height if balanced, -1 if not
 * 
 * Time  : O(n)
 * Space : O(height)
 */
class RecursiveSolution {
public:
    int check(TreeNode* root) {
        if (!root) return 0;
    
        int left = check(root->left);
        if (left == -1) return -1;
    
        int right = check(root->right);
        if (right == -1) return -1;
    
        if (abs(left - right) > 1) return -1;
    
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

/**
 * \c IterativeSolution
 * 
 * 1. Use queue
 * 2. Compare the absolute difference between left and right branches
 * 3. Push children
 * 
 * Time  : O(n log n)
 * Space : O(n^2)
 */
class IterativeSolution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
    
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
    
        queue<TreeNode*> q;
        q.push(root);
    
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
    
            if (abs(height(curr->left) - height(curr->right)) > 1) {
                return false;
            }
    
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    
        return true;
    }
};