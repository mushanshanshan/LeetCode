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

    int sum = 0;
    long res = 0;

    void _accumulate_tree(TreeNode* root) {
        if (!root) return;

        sum += root->val;
        _accumulate_tree(root->left);
        _accumulate_tree(root->right);
    }


    int _check_max_mul(TreeNode* root) {
        if (!root) return 0;

        int temp = root->val + _check_max_mul(root->left) + _check_max_mul(root->right);
        res = max(res, (long)temp * (long)(sum - temp));

        return temp;
    }


public:
    int maxProduct(TreeNode* root) {
        _accumulate_tree(root);
        _check_max_mul(root);

        return res % (int)(1e9 + 7);
    }
};