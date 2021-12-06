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
    void midorder(TreeNode* node, vector<int>& v){
        if (node == NULL) {return;}
        
        midorder(node->left, v);
        v.push_back(node->val);
        midorder(node->right, v);
        
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> v{};
        midorder(root, v);
        
        int min = v[1] - v[0];
        for (int i=1; i<v.size()-1; i++){
            if (v[i+1] - v[i] < min) {min = v[i+1] - v[i];}
        }
        
        return min;
        
    }
};