class Solution {
private:
    int res = 0;

    int dfs(int cur, vector<vector<int>> &g, string &s) {
        if (g[cur].size() == 0) return 1;

        vector<int> all_child;
        for (int i: g[cur]) {
            int c = dfs(i, g, s);
            if (s[i] == s[cur]) c = 0;
            all_child.push_back(c);
        }

        if (all_child.size() == 1) {
            res = max(res, all_child[0]+1);
        } else {
            sort(all_child.begin(), all_child.end(), std::greater<int>());
            res = max(res, all_child[0]+all_child[1]+1);
        }

        return all_child[0]+1;
    }
    

public:
    int longestPath(vector<int>& parent, string s) {
        int N = s.size();

        if (N == 1) return 1;

        vector<vector<int>> g(N);

        for (int i=1; i<N; i++) {
            g[parent[i]].push_back(i);
        }

        dfs(0, g, s);

        return res;
    }
};