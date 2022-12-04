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
    int d = 0;
    
    void getDepth(TreeNode* root, int depth){
        d = depth > d ? depth : d;
        if (root->right==NULL and root->left==NULL) return;
        if (root->right!=NULL) getDepth(root->right, depth+1);
        if (root->left!=NULL) getDepth(root->left, depth+1);
    }
    
    int maxDepth(TreeNode* root) {
        if (root!=NULL) getDepth(root, 1);
        return d;
    }
};