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

    int res = INT_MIN;

    int recirsiveTree(TreeNode* root) {
        if (!root) return 0;

        int left = recirsiveTree(root->left) + root->val;
        int right = recirsiveTree(root->right) + root->val;
        int _max = max(left, max(right, root->val));

        res = max(res, max(_max, left + right - root->val));
        
        return _max;
    }


public:
    int maxPathSum(TreeNode* root) {
        recirsiveTree(root);
        return res;
    }
};