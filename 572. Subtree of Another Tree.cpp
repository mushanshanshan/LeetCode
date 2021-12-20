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
    bool tr(TreeNode* left, TreeNode* right) {
        if (!left || !right) {
            return left == right;
        }
        
        return (left->val == right->val && tr(left->left, right->left) && tr(left->right, right->right));
        
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true;
        if (tr(root, subRoot)) return true;
        return tr(root->left, subRoot) || tr(root->right, subRoot);
    }
};