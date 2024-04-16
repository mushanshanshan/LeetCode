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
private:
    void re(TreeNode* cur, int val, int depth) {
        if (!cur) return;

        if (depth == 1) {
            TreeNode* ori_left = cur->left;
            TreeNode* ori_right = cur->right;

            cur->left = new TreeNode(val, ori_left, NULL);
            cur->right = new TreeNode(val, NULL, ori_right);
        } else {
            re(cur->left, val, depth-1);
            re(cur->right, val, depth-1);
        }
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummy = new TreeNode(0, root, NULL);

        re(dummy, val, depth);

        return dummy->left;
    }
};