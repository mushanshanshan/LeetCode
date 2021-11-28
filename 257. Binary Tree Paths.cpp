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
    
    void tr(TreeNode* root, vector<int>& path, vector<string>& res){
        
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL){
            string s;
            
            for (int i=0; i<path.size()-1;i++){
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size()-1]);
            
            res.push_back(s);
        }
        
        if (root->left != NULL){
            tr(root->left, path, res);
            path.pop_back();
        }
        
        if (root->right != NULL){
            tr(root->right, path, res);
            path.pop_back();
        }
        
    }
        
        
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res={};
        if (root != NULL) tr(root, path, res);
        return res;
        
    }
};