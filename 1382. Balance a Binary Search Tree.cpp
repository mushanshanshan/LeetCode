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
    vector<int> list;
    
    void tr(TreeNode* node) {
        if (!node) return;
        
        tr(node->left);
        list.push_back(node->val);
        tr(node->right);
    }
    
    TreeNode* buildTree(int left, int right) {
        if (left > right) return NULL;
        
        int mid = (left + right) / 2;
        TreeNode* cur = new TreeNode(list[mid]);
        cur->left = buildTree(left, mid-1);
        cur->right = buildTree(mid+1, right);
        
        return cur;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        tr(root);
        TreeNode* res = buildTree(0, list.size()-1);
        
        return res;
        
        
        
        
    }
};