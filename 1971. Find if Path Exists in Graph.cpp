class Solution {
private:
    bool res = false;
    int n, dest;
    unordered_map<int,vector<int>> graph; 
    vector<bool> visited;

    void dfs(int cur) {
        if (res || visited[cur]) return;
        if (cur == dest) {
            res = true;
            return;
        }

        visited[cur] = true;
        for (int i: graph[cur]) {
            dfs(i);
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (auto e: edges) {
            this->graph[e[0]].push_back(e[1]);
            this->graph[e[1]].push_back(e[0]);
        }
        this->visited = vector<bool>(n, false);
        this->n = n;
        this->dest = destination;

        dfs(source);

        return res;
    }
};