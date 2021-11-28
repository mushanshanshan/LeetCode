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
    TreeNode* tr(vector<int>& inorder, vector<int>& postorder){
        if (inorder.size() == 0){
            return NULL;
        }
        
        int splitValue = postorder[postorder.size()-1];
        int splitPoint = 0;
        
        TreeNode* node = new TreeNode(splitValue);
        
        
        
        for (; splitPoint < inorder.size(); splitPoint++){
            if (splitValue == inorder[splitPoint]) {
                break;
            }
            
        }
        
        vector<int> leftInOrder(inorder.begin(), inorder.begin()+splitPoint);
        vector<int> rightInOrder{inorder.begin()+splitPoint+1, inorder.end()};
        
        vector<int> leftPostOrder{postorder.begin(), postorder.begin()+leftInOrder.size()};
        vector<int> rightPostOrder{postorder.begin()+leftInOrder.size(),postorder.end()-1};
        
        node->left = tr(leftInOrder, leftPostOrder);
        node->right = tr(rightInOrder, rightPostOrder);
        
        return node;
        
        
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = tr(inorder, postorder);
        return root;
    }
};