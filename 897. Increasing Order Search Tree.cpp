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
public:
    TreeNode* res, *cur;
    
    void tr(TreeNode* root) {
        if (!root) return;
        
        tr(root->left);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        tr(root->right);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = new TreeNode(0);
        cur = res;
        tr(root);
        return res->right;
    }
};