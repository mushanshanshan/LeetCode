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
    queue<TreeNode*> qu;
    bool it(TreeNode* root) {
        qu.push(root);
        bool even_level = false;
        int pre = 0;

        while (!qu.empty()) {
            int level_count = qu.size();
            even_level = !even_level;
            if (even_level) pre = 0;
            else pre = INT_MAX;
            for (int i=0; i<level_count; i++) {
                auto cur = qu.front();
                qu.pop();

                if (even_level) {
                    if (cur->val % 2 != 1 || cur->val <= pre) return false;
                } else {
                    if (cur->val % 2 != 0 || cur->val >= pre) return false;
                }


                pre = cur->val;
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }
        }

        return true;
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        return it(root);
    }
};