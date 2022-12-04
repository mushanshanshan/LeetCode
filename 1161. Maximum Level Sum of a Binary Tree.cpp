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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node;
        int maxsum=INT_MIN, res=0, level=0, qsize, tempsum;
        
        q.push(root);
        while (!q.empty()) {
            qsize = q.size();
            tempsum=0;
            level++;
            for (int i=0; i<qsize; i++) {
                node = q.front();
                q.pop();
                tempsum += node->val;
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
            if (tempsum > maxsum) {
                maxsum = tempsum;
                res = level;
            }
        }
        return res;
    }
};