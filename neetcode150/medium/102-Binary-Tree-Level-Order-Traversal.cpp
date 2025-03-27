#include <vector>
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
 * \c Solution
 * 
 * 1. Use BFS to traverse the tree by it's levels
 * 2. The size of the queue tells you how many nodes are at a given level
 * 
 * Note: Check if the node is null before adding it to the queue to save memory and reduce uncessary queue ops
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
    
        // bfs
        queue<TreeNode*> q;
        q.push(root);
    
        vector<vector<int>> res;
    
        while(!q.empty()) {
            int N = q.size();
            vector<int> level;
    
            for (int i = 0; i < N; ++i) {
                auto node = q.front();
                q.pop();
    
                level.push_back(node->val);
    
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
    
            res.push_back(level);
        }
    
        return res;
    }
};