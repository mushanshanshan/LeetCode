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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        TreeNode* tnode;
        queue<TreeNode*> q;
        
        if (root != NULL) q.push(root);
        
        while (!q.empty()){
            int qsize = q.size();
            double sum = 0.0;
            for (int i=0; i < qsize; i++){
                tnode = q.front();
                q.pop();
                sum += tnode->val;
                if (tnode->left!= NULL) q.push(tnode->left);
                if (tnode->right!= NULL) q.push(tnode->right);
                
            }
            res.push_back(sum/qsize);
            
        }
        return res;
    }
};