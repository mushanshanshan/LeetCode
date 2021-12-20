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
    vector<TreeNode*> res;
    
    TreeNode* tr(TreeNode* root, unordered_set<int>& del) {
        if (!root) return NULL;

        root->left = tr(root->left, del);
        root->right = tr(root->right, del);
        
        if (del.count(root->val)) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
        }
        
        if (del.count(root->val)) root=NULL;
        
        return root;
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del;
        for (int i: to_delete) del.insert(i);
        root = tr(root, del);
        if (root) res.push_back(root);
        return res;
    }
};