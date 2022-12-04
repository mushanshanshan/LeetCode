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
        TreeNode* cur;
        int qsize;
        bool flag = false;
        q.push(root);
        
        while (!q.empty()) {
            qsize = q.size();
            for (int i=0; i<qsize; i++) {
                cur = q.front();
                q.pop();
                if (flag && cur) return false;
                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                } else {
                    flag = true;
                }
            }
        }
        
        return true;
        
        
    }
};