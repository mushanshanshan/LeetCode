class Solution {
private:
    vector<int> visited;
    int res = -1;
    int N = 0;

    void dfs(int cur, int depth, vector<int>& edges) {
        if (cur == -1 || visited[cur] == -1) {
            return;
        }

        if (visited[cur] >= 0) {
            res = max(res, depth - visited[cur]);
        } else {
            visited[cur] = depth;
            dfs(edges[cur], depth+1, edges);
            visited[cur] = -1;
        }
    }

public:
    int longestCycle(vector<int>& edges) {
        N = edges.size();
        visited.resize(N, -2);

        for (int i=0; i<N; i++) {
            if (visited[i] == -2) {
                dfs(i, 0, edges);
            }
        }

        return res;
    }
};