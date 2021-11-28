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
    void tr(TreeNode* root, int sum, vector<int>& v){
        if (root->left == NULL && root->right == NULL){
            v.push_back(sum+root->val);
        }
        
        if (root->left != NULL) {tr(root->left, sum+root->val, v);}
        if (root->right != NULL) {tr(root->right, sum+root->val, v);}
        
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int sum = 0;
        
        if (root != NULL) {tr(root, sum, v);}
        
        for (int i : v){
            if (i == targetSum) {return true;}
            
        }
        
        return false;
    }
};