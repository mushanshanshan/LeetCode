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
    unordered_map<int, int> counter;
    int res = 0;

    void check_path() {
        bool odd = false;
        for (auto &a: counter) {
            if (a.second & 2 != 0) {
                if (odd) return;
                else odd = true;
            }
        }

        res++;
    }

    void backtrace(TreeNode* node) {
        if (!node) return;
        
        counter[node->val]++;
        if (node->left) backtrace(node->left);
        if (node->right) backtrace(node->right);
        else if (!node->left) check_path();

        counter[node->val]--;
    }


public:
    int pseudoPalindromicPaths (TreeNode* root) {
        backtrace(root);
        return res;
    }
};