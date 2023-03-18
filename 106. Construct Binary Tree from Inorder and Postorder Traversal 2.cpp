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
private:
    TreeNode* helper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if (is > ie || ps > pe) return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);

        int im = is;
        while (root->val != inorder[im]) im++;
        int pm = ps + im - is;

        root->left = helper(inorder, is, im-1, postorder, ps, pm-1);
        root->right = helper(inorder, im+1, ie, postorder, pm, pe-1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, inorder.size()-1);
    }
};