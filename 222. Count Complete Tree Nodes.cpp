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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftcnt = 0, rightcnt = 0;
        TreeNode* leftnode = root, * rightnode = root;
        
        while (leftnode) {
            leftnode = leftnode->left;
            leftcnt++;
        }
        
        while (rightnode) {
            rightnode = rightnode->right;
            rightcnt++;
        }
        
        if (leftcnt == rightcnt) return pow(2, leftcnt) - 1;
        else return 1 + countNodes(root->left) +countNodes(root->right);
    }
};