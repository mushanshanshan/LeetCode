class Solution {
private:
    bool res = false;
    void dfs(int n, vector<vector<int>>& adj, vector<int>& checked, int cur, int destination) {
        if (checked[cur] == 1) return;
        if (cur == destination) {
            res = true;
            return;
        }

        checked[cur] = 1;

        for (int i: adj[cur]) {
            dfs(n, adj, checked, i, destination);
        }

        return;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> checked(n, 0);

        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(n, adj, checked, source, destination);

        return res;
    }
};