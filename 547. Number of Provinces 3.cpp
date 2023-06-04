class Solution {
private:
    int N;
    int prov = 0;

    void bfs(int cur, vector<vector<int>>& isConnected, vector<bool>& visited) {
        if (visited[cur]) return;
        visited[cur] = true;

        for (int i=0; i<N; i++) {
            if (isConnected[cur][i]) bfs(i, isConnected, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        vector<bool> visited(N, false);

        for (int i=0; i<N; i++) {
            if (!visited[i]) {
                prov++;
                bfs(i, isConnected, visited);
            }
        }

        return prov;
    }
};