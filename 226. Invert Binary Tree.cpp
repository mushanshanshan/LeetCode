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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* tnode, t2node;
        
        if (root != NULL) q.push(root);
        
        while(!q.empty()){
            int qsize = q.size();
            
            for (int i=0; i<qsize; i++){
                tnode = q.front();
                q.pop();
                
                if (tnode->left !=NULL) q.push(tnode->left);
                if (tnode->right !=NULL) q.push(tnode->right);
                swap(tnode->left, tnode->right);
            }
        }
        return root;
    }
};