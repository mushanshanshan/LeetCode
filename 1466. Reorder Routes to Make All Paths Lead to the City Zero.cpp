class Solution {
private:
    int res = 0;
    vector<bool> visited;
    void dfs(int cur, unordered_map<int, vector<int>> &g) {
        visited[cur] = true;
        for (auto i: g[cur]) {
            if (visited[abs(i)]) continue;
            if (i < 0) res++;
            dfs(abs(i), g);
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> g;
        visited.resize(n+1, false);

        for (auto v: connections) {
            g[v[0]+1].push_back(-(v[1]+1));
            g[v[1]+1].push_back(v[0]+1);
        }

        dfs(1, g);

        return res;
    }
};