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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        stack<TreeNode*> node_st;
        queue<int> int_q;
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int l = q.size();
            bool odd = level % 2 == 1;
            
            for (int i=0; i<l; i++) {
                auto cur = q.front();
                if (!cur) {
                    q.pop();
                    continue;
                }

                // printf("%d\n", cur->val);

                if (odd) {
                    int_q.push(cur->val);
                    node_st.push(cur);
                }

                q.pop();
                q.push(cur->left);
                q.push(cur->right);
            }

            if (odd) {
                while (!node_st.empty()) {
                    node_st.top()->val = int_q.front();
                    node_st.pop();
                    int_q.pop();
                }
            }

            level++;
        }

        return root;
    }
};