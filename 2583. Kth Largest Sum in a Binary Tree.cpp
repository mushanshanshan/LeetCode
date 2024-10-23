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
    unordered_map<int, long long> level_sum;

    void recur(TreeNode* root, int cur) {
        if (!root) return;
        level_sum[cur] += root->val;
        recur(root->left, cur+1);
        recur(root->right, cur+1);
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        recur(root, 1);
        vector<long long> temp_vec;

        for (auto& a: level_sum) {
            temp_vec.push_back(a.second);
        }

        if (temp_vec.size() < k) return -1;

        sort(temp_vec.begin(), temp_vec.end());

        int target_size = temp_vec.size() - (--k);

        return temp_vec[target_size - 1];
    }
};