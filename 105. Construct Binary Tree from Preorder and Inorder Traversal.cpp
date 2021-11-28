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
    TreeNode* tr(vector<int>& preorder, vector<int>& inorder){
        if (preorder.size() == 0){
            return NULL;
        }
        
        int splitv = preorder[0];
        int spliti = 0;
        for(; spliti<inorder.size(); spliti++){
            if (inorder[spliti] == splitv) {
                break;
            }
        }
        
        TreeNode* node = new TreeNode(splitv);
        
        vector<int> leftin{inorder.begin(), inorder.begin()+spliti};
        vector<int> rightin{inorder.begin()+spliti+1, inorder.end()};
        
        vector<int> leftpre{preorder.begin()+1, preorder.begin()+1+leftin.size()};
        vector<int> rightpre{preorder.begin()+1+leftin.size(), preorder.end()};
        
        node->left = tr(leftpre, leftin);
        node->right = tr(rightpre, rightin);
        
        return node;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        
        TreeNode* root = tr(preorder, inorder);
        return root;
        
    }
};