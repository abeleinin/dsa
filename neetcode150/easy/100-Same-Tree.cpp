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
 * \c SimpleSolution
 * 
 * 1. Use dfs
 * 2. Define a base case for null TreeNodes
 * 3. Compare the node values of each tree
 * 4. Search the children branches
 * 5. Both the left and the right sub-trees must be the same so use &&
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class SimpleSolution {
public:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p) return !q;
        if (!q) return !p;

        if (p->val != q->val) return false;

        bool left = dfs(p->left, q->left);
        bool right = dfs(p->right, q->right);

        return left && right;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};

/**
 * \c CleanSolution
 * 
 * Simplifies base case and recursive call
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class CleanSolution {
public:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) return !p && !q;

        if (p->val != q->val) return false;

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
