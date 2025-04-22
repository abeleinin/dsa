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
 * \c ResursiveSolution
 * 
 * 1. Swap left and right nodes
 * 2. Invert left and right sides
 * 
 * Time  : O(n)
 * Space : O(height)
 */
class ResursiveSolution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        swap(root->right, root->left);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

/**
 * \c IterativeSolution
 * 
 * 1. Use a queue (FIFO) and push the root
 * 2. While the queue is not empty pop the front node and swap its left and right children
 * 3. Push the children (left and right) onto the queue
 * 
 * Time  : O(n)
 * Space : O(height)
 */
class IterativeSolution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
    
            if (curr) {
                swap(curr->left, curr->right);
    
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return root;
    }
};
