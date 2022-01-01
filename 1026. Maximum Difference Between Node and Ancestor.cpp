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
    int res = INT_MIN;
    
    void tr(TreeNode* root, int mi, int mx) {
        if (!root) return;
        
        res = max(res, max(abs(root->val - mi), abs(root->val - mx)));
        
        if (root->val > mx) {
            mx = root->val;
        } else if (root->val < mi) {
            mi = root->val;
        }
        
        tr(root->right, mi, mx);
        tr(root->left, mi, mx);
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        tr(root, root->val, root->val);
        return res;
    }
};