/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* tr(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == p || root == q || root == NULL) {return root;}
        
        TreeNode* left = tr(root->left, p, q);
        TreeNode* right = tr(root->right, p, q);
        
        if (left != NULL && right != NULL) {return root;}
        if (left != NULL && right == NULL) {return left;}
        return right;

        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return tr(root, p, q);
    }
};