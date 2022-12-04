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
    bool res = true;
    
    int tr(TreeNode* cur) {
        if (!cur) return 0;
        
        int left = tr(cur->left);
        int right = tr(cur->right);
        
        if (abs(left-right) > 1) res = false;
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        tr(root);
        
        return res;
    }
};