class Solution {
private:
    void dfs(int cur, int pre, vector<vector<int>> &dp, vector<vector<int>> &g, string &labels) {
        dp[cur][labels[cur] - 'a']++;
        for (int i: g[cur]) {
            if (i == pre) continue;
            dfs(i ,cur, dp, g, labels);
            for (int c=0; c<26; c++) dp[cur][c] += dp[i][c];
        }
    }  


public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<vector<int>>g(n);
        vector<int> res(n);

        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1, dp, g, labels);

        for (int i=0; i<n; i++) {
            res[i] = dp[i][labels[i] - 'a'];
        }

        return res;
    }
};