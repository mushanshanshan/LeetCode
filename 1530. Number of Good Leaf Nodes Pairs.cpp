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
    int res = 0;
    int max_dis = 0;

    vector<int> dfs(TreeNode* root) {
        vector<int> cur(max_dis + 1, 0);  // Ensure enough space for distances up to max_dis
        if (!root) return cur;

        if (!root->left && !root->right) {
            cur[1] = 1;  // Leaf node, distance to itself is 1
            return cur;
        }

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        // Calculate pairs
        for (int i = 0; i <= max_dis; i++) {
            for (int j = 0; j <= max_dis; j++) {
                if (i + j <= max_dis) {
                    res += l[i] * r[j];
                }
            }
        }

        // Update current node distances
        for (int i = 1; i < max_dis; i++) {
            cur[i + 1] = l[i] + r[i];
        }

        return cur;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        max_dis = distance;
        dfs(root);
        return res;
    }
};
