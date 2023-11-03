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
    int res = 0;

    pair<int, int> postorder(TreeNode* root) {
        if (!root) return {-1, -1};

        int cursum = root->val;
        int curcount = 1;

        auto s = postorder(root->left);
        if (s.second != -1) {
            cursum += s.first;
            curcount += s.second;
        }
        s = postorder(root->right);
        if (s.second != -1) {
            cursum += s.first;
            curcount += s.second;
        }

        if (cursum / curcount == root->val) res++;

        return {cursum, curcount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }
};