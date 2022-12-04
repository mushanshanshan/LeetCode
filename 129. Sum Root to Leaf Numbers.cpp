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
    int res = 0;
    
    void tr(TreeNode* node, int sum) {
        if (!node) return;
        
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) res += sum;
        else {
            tr(node->left, sum);
            tr(node->right, sum);
        }
        
    }
    
    int sumNumbers(TreeNode* root) {
        tr(root, 0);
        return res;
    }
};