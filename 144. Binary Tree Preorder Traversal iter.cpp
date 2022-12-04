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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* temp;
        
        if (root == NULL) {return v;}
        
        s.push(root);
        while (!s.empty()){
            temp = s.top();
            s.pop();
            
            if (temp != NULL){
                if (temp->right != NULL) {s.push(temp->right);}
                if (temp->left != NULL) {s.push(temp->left);}
                s.push(temp);
                s.push(NULL);
            } else {
                temp = s.top();
                s.pop();
                v.push_back(temp->val);
                
            }
            
            
            
        }
        return v;
    }
};