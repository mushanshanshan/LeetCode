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

    void tr(TreeNode* root, int mi, int mx) {

        if (!root) return;

        res = max(res, max(abs(root->val - mi), abs(root->val - mx)));

        mi = root->val < mi? root->val: mi;
        mx = root->val > mx? root->val: mx;

        tr(root->left, mi, mx);
        tr(root->right, mi, mx);
    }


public:
    int maxAncestorDiff(TreeNode* root) {
        tr(root, root->val, root->val);
        return res;
    }
};