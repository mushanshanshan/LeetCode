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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int res = 0, level_count = 1;
        bool first = true;

        while (!qu.empty()){
            first = true;
            for (int i=0; i<level_count; i++) {
                auto cur = qu.front();
                qu.pop();
                if (!cur) continue;
                if (first) {
                    res = cur->val;
                    first = false;
                }
                qu.push(cur->left);
                qu.push(cur->right);

            }
            level_count = qu.size();
        }

        return res;
    }
};