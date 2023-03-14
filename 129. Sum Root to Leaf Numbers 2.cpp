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

    void helper(TreeNode* root, int cur) {
        if (!root->left && !root->right) {
            res += cur * 10 + root->val;
            return;
        }

        if (root->left) helper(root->left, cur * 10 + root->val);
        if (root->right) helper(root->right, cur * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};