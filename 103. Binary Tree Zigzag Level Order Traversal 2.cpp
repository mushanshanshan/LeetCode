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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> cur_level;

        int l;
        bool rev = false;
        if (root) q.push(root);

        while (!q.empty()) {
            l = q.size();
            cur_level.clear();

            for (int i=0; i<l; i++) {
                TreeNode* cur = q.front();
                q.pop();
                cur_level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (rev) reverse(cur_level.begin(), cur_level.end());
            res.push_back(cur_level);
            rev = !rev;
        }

        return res;
    }
};