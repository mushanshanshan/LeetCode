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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long int res = 0;
        queue<pair<TreeNode*, unsigned long long int>> q;
        
        q.push({root, 1});
        
        while(!q.empty()) {
            if (q.size() == 1) q.front().second = 1;
            int s = q.size();
            unsigned long long int left = q.front().second, right = left;
            for (int i=0; i<s; i++) {
                TreeNode* cur = q.front().first;
                right = q.front().second;
                q.pop();
                if (cur->left) q.push({cur->left, right * 2});
                if (cur->right) q.push({cur->right, right * 2 + 1});
            }
            
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};