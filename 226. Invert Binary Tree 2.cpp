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
    void recursive(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        recursive(root->left);
        recursive(root->right);
    }


public:
    TreeNode* invertTree(TreeNode* root) {
        recursive(root);
        return root;
    }
};