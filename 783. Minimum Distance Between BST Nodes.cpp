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
    int res = INT_MAX;
    int pre = -1;

    void _re(TreeNode* root) {
        if (!root) return;
        _re(root->left);
        res = min(res, pre == -1? INT_MAX: root->val - pre);
        pre = root->val;
        _re(root->right);

    }

public:
    int minDiffInBST(TreeNode* root) {
        _re(root);
        return res;
    }
};