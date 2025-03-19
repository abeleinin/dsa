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

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->right, root->left);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

class Solution2 {
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