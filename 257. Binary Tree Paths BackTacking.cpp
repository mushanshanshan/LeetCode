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
    vector<string> res;
    vector<int> temp;
    
    void backtracking(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            string s = "";
            for (int i=0; i<temp.size(); i++) {
                s += to_string(temp[i]);
                s += "->";
            }
            s += to_string(root->val);
            res.push_back(s);
        }
        
        if (root->left != NULL) {
            temp.push_back(root->val);
            backtracking(root->left);
            temp.pop_back();
        }
        
        if (root->right != NULL) {
            temp.push_back(root->val);
            backtracking(root->right);
            temp.pop_back();
        }
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        backtracking(root);
        return res;
    }
};