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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> level_sum;
        queue<TreeNode*> q;
        int cur_level = 0, cur_level_node = 1, next_level_node = 1;

        q.push(root);

        while (!q.empty()) {
            cur_level++;
            cur_level_node = next_level_node;
            next_level_node = 0;

            for (int i=0; i<cur_level_node; i++) {
                TreeNode* cur = q.front();
                q.pop();
                level_sum[cur_level] += cur->val;
                
                if (cur->left) {
                    next_level_node++;
                    q.push(cur->left);
                }

                if (cur->right) {
                    next_level_node++;
                    q.push(cur->right);
                }
            }
        }

        cur_level = 0, cur_level_node = 1, next_level_node = 1;

        q.push(root);
        while (!q.empty()) {
            cur_level++;
            cur_level_node = next_level_node;
            next_level_node = 0;

            for (int i=0; i<cur_level_node; i++) {
                TreeNode* cur = q.front();
                q.pop();
                int child_sum = 0;
                
                if (cur->left) {
                    child_sum += cur->left->val;
                    next_level_node++;
                    q.push(cur->left);
                }
                if (cur->right) {
                    child_sum += cur->right->val;
                    next_level_node++;
                    q.push(cur->right);
                }

                // printf("%d-%d\n", child_sum, level_sum[cur_level+1]);

                if (cur->left) {
                    cur->left->val = level_sum[cur_level+1] - child_sum;
                }
                if (cur->right) {
                    cur->right->val = level_sum[cur_level+1] - child_sum;
                }
            }
        }

        root->val = 0;
        return root;
    }
};