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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        TreeNode* tempt;
        int qsize;
        
        if (root != NULL) {q.push(root);}
        
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                tempt = q.front();
                q.pop();
                if (i == qsize - 1) res.push_back(tempt->val);
                if (tempt->left != NULL) q.push(tempt->left);
                if (tempt->right != NULL) q.push(tempt->right);
            }
        }
        return res;
    }
};