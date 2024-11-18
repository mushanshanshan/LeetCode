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
    unordered_map<int, int> map;
    bool res = true;
    int counter = 0;

    void rec_left(TreeNode* cur) {
        if (!cur) return;
        int l = cur->left? cur->left->val: 100;
        int r = cur->right? cur->right->val: 100;
        map[cur->val] = l * r + l + r;
        counter++;
        rec_left(cur->left);
        rec_left(cur->right);
    }

    void rec_right(TreeNode* cur) {
        if (!cur || !res) return;
        int l = cur->left? cur->left->val: 100;
        int r = cur->right? cur->right->val: 100;
        int v = l * r + l + r;
        counter--;
        // printf("%d-%d-%d\n", cur->val, v, map[cur->val]);
        if (v != map[cur->val]) res = false;
        rec_right(cur->left);
        rec_right(cur->right);
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        rec_left(root1);
        rec_right(root2);
        return res && counter == 0;
    }
};