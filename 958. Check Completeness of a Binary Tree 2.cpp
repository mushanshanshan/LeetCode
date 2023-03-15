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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        bool end = false;
        q.push(root);


        while (!q.empty()) {
            int l = q.size();

            for (int i=0; i<l; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    if (end == true) return false;
                    q.push(cur->left);
                    q.push(cur->right);
                } else {
                    end = true;
                }
            }
        }

        return true;

    }
};