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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        bool flag = true;
        int dqsize;
        TreeNode* cur;
        vector<int> temp;
        
        dq.push_back(root);
        
        while (!dq.empty()) {
            dqsize = dq.size();
            temp.clear();
            for (int i=0; i<dqsize; i++) {
                if (flag) {
                    cur = dq.front();
                    dq.pop_front();
                    temp.push_back(cur->val);
                    if (cur->left) dq.push_back(cur->left);
                    if (cur->right) dq.push_back(cur->right);
                } else {
                    cur = dq.back();
                    dq.pop_back();
                    temp.push_back(cur->val);
                    if (cur->right) dq.push_front(cur->right);
                    if (cur->left) dq.push_front(cur->left);
                }
            }
            flag = !flag;
            res.push_back(temp);
        }
        
        return res;
        
    }
};