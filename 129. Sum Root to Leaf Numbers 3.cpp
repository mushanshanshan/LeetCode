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
    int res = 0;
    void re(TreeNode* cur, int pre) {
        if (!cur) return;
        pre = 10 * pre + cur->val;
        if (!cur->left && !cur->right) res += pre;

        re(cur->left, pre);
        re(cur->right, pre);
    }
public:
    int sumNumbers(TreeNode* root) {
        re(root, 0);
        return res;
    }
};