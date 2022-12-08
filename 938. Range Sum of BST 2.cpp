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

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        short flag = 0;

        if (root->val >= low) {
            rangeSumBST(root->left, low, high);
            flag += 1;
        }

        if (root->val <= high) {
            rangeSumBST(root->right, low, high);
            flag += 1;
        }

        if (flag == 2) res += root->val;

        return res;
    }
};