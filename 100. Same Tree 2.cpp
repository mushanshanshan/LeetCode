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
    bool global_res = true;

    void tr(TreeNode* p, TreeNode* q){
        if (!p && q || p && !q || p && p->val != q->val) global_res = false;
        if (!global_res || !p) return;

        tr(p->left, q->left);
        tr(p->right, q->right);

        return;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        tr(p, q);

        return global_res;
    }
};