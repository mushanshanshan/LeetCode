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
    unordered_set<int> set;
    
    bool tr(TreeNode* root, int k) {
        if (root == NULL) return false;
        if (set.count(root->val)) return true;
        
        set.insert(k-root->val);
        
        bool left = tr(root->left, k);
        bool right = tr(root->right, k);
        
        return left || right;
    }
    
    bool findTarget(TreeNode* root, int k) {
        return tr(root, k);
    }
};