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
    vector<int> recursion(TreeNode* node) {
        if (node == NULL) return vector<int>{0,0};
        
        vector<int> left = recursion(node->left);
        vector<int> right = recursion(node->right);
        
        vector<int> cur{0,0};
        cur[0] = max(left[0],left[1]) + max(right[0],right[1]);
        cur[1] = left[0] + right[0] + node->val;
        
        return cur;
    }
    
    
    int rob(TreeNode* root) {
        vector<int> cur = recursion(root);
        return max(cur[0], cur[1]);
    }
};