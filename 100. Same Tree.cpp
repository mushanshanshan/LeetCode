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
    bool compare(TreeNode* p, TreeNode* q){
        if ((p==NULL) + (q==NULL) == 1) return false;
        if ((p==NULL) + (q==NULL) == 2) return true;
        if (p->val != q->val) return false;
        
        return compare(p->left, q->left) && compare(q->right,p->right);
        
    }
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }
};