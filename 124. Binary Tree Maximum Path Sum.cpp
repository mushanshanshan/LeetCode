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
    int tr(TreeNode* root) {
        if (!root) return 0;
        
        int left = max(tr(root->left), 0);
        int right = max(tr(root->right), 0);
        
        res = max(res, root->val+left+right);
        
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        tr(root);
        return res;
    }
    
private:
    int res = INT_MIN;
};