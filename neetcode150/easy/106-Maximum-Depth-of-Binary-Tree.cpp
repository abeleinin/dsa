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
 * 1. Use tail recursion to accumulate the depth of the left and right branches
 * 2. Return the max of either side
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class RecursiveSolution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int valLeft = 1 + maxDepth(root->left);
        int valRight = 1 + maxDepth(root->right);
        return max(valLeft, valRight);
    }
};

/**
 * \c IterativeSolution
 * 
 * 1. Use a queue (FIFO) of pairs containing nodes and their depth
 * 2. Process the queue and maintain a result value containing the max depth so far
 * 3. Push the left and right children with "curr node depth + 1"
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class IterativeSolution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int res = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.first) {
                res = max(res, curr.second);
                q.push(make_pair(curr.first->left, curr.second+1));
                q.push(make_pair(curr.first->right, curr.second+1));
            }
        }
        return res;
    }
};
