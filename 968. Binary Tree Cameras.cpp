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
    int result = 0;
    
    int traversal(TreeNode* node){
        if (node == NULL) return 2;
        
        int left = traversal(node->left);
        int right = traversal(node->right);
        
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        
        if (left == 2 && right == 2) {
            return 0;
        }

        return 2;

        
    }
    
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};