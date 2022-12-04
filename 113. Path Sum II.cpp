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
    vector<vector<int>> res;
    
    void tr(TreeNode* cur, int target, vector<int> temp) {
        if(!cur) return;
        
        if (!cur->left && !cur->right) {
            if (target == cur->val) {
                temp.push_back(cur->val);
                res.push_back(temp);
            } 
            return;
        }
        
        temp.push_back(cur->val);
        target-= cur->val;
        
        tr(cur->left, target, temp);
        tr(cur->right, target, temp);
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        tr(root, targetSum, temp);
        return res;
    }
};