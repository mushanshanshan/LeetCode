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
    bool isSymmetric(TreeNode* root) {
        TreeNode* tnode;
        queue<TreeNode*> q;
        
        
        if (root == NULL) {
            return true;
        } else {
            q.push(root);
        }
        
        
        while (!q.empty()){
            vector<int> v;
            int qsize = q.size();
            
            for (int i=0; i<qsize; i++){
                tnode = q.front();
                q.pop();
                if (tnode == NULL){
                    v.push_back(INT_MIN);
                    continue;
                }
                v.push_back(tnode->val);
                
                q.push(tnode->right);
                q.push(tnode->left);
            }
            
            int vsize = v.size();
            if (vsize != 1 && vsize%2 != 0) return false;
            
            for (int i=0; i<vsize/2; i++){
                if (v[i] != v[vsize-1-i]){
                    return false;
                }
                
            }
            
            
        }
        return true;
    }
};