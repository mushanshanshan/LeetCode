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

short left = 0, right = 0;
vector<short> leaf{vector<short>(100, 0)};

void _tr(TreeNode* cur, bool flag) {
    if (!cur) return;

    if (!cur ->left && !cur->right) {
        if (flag) leaf[left++] += cur->val;
        else leaf[right++] -= cur->val;
    }

    _tr(cur ->left, flag);
    _tr(cur ->right, flag);
}


public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        _tr(root1, true);
        _tr(root2, false);

        for (auto s: leaf) {
            if (s != 0) return false;
        }

        return true;
    }
};