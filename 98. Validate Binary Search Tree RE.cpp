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
    bool check(TreeNode* cur, int mi, int ma) {
        if (!cur) return true;
        if (cur->val < mi || cur->val > ma) return false;
        return check(cur->left, mi, cur->val) && check(cur->right, cur->val, ma);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};