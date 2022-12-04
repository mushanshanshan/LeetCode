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
    int countFromRoot(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        
        int count = 0;
        if (root->val == sum) count++;
        count += countFromRoot(root->left, sum - root->val);
        count += countFromRoot(root->right, sum - root->val);
        
        return count;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root) return countFromRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        else return 0;
    }
};