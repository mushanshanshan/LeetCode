class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, unordered_map<int ,int>> g;
    int res = INT_MAX;

    void dfs(int cur) {
        visited.insert(cur);
        for (auto a: g[cur]) {
            if (!visited.count(a.first)) {
                dfs(a.first);
            }
            res = min(res, a.second);
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        for (auto a: roads) {
            g[a[0]][a[1]] = a[2];
            g[a[1]][a[0]] = a[2];
        }

        dfs(1);
        return res;
    }
};