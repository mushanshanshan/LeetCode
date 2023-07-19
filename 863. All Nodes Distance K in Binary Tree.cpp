/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, vector<int>> g;
    int N = 0;

    void dfs(TreeNode* cur, int pre) {
        if (!cur) return;
        if (pre != -1) g[cur->val].push_back(pre);
        if (cur->left) g[cur->val].push_back(cur->left->val);
        if (cur->right) g[cur->val].push_back(cur->right->val);
        N = max(N, cur->val);
        dfs(cur->left, cur->val);
        dfs(cur->right, cur->val);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, -1);
        queue<int> q;
        vector<bool> visited(N, false);
        q.push(target->val);

        while (k > 0) {
            int s = q.size();
            for (int i=0; i<s; i++) {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                for (int n: g[cur]) {
                    if (!visited[n]) q.push(n);
                }
            }
            k--;
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;

    }
};