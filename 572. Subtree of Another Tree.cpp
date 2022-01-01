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
    bool subtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return root == subRoot;
        
        return root->val == subRoot->val && subtree(root->left,  subRoot->left) && subtree(root->right,  subRoot->right);
    }
    
    bool tr(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (subtree(root, subRoot)) return true;
        
        return tr(root->left, subRoot) || tr(root->right, subRoot);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true;
        
        return tr(root, subRoot);
    }
};