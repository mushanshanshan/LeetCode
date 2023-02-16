/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = 0;

    void _re(TreeNode* root, int d) {
        if (root == NULL) {
            res = max(res, d-1);
            return;
        }

        _re(root->left, d+1);
        _re(root->right, d+1);
    }

public:
    int maxDepth(TreeNode* root) {
        _re(root, 1);
        return res;
    }
};