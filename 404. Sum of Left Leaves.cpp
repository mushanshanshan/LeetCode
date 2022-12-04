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
    void countLeft(TreeNode* root, int& sum){
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {sum += root->left->val;}
        if (root->left != NULL) {countLeft(root->left, sum);}    
        if (root->right != NULL) {countLeft(root->right, sum);}    
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        countLeft(root, sum);
        return sum;
    }
};