class Solution {
private:
    int N;
    int prov = 0;

    void bfs(int cur, vector<vector<int>>& isConnected, vector<int>& visited) {
        if (visited[cur] != 0) return;
        visited[cur] = prov;

        for (int i=0; i<N; i++) {
            if (isConnected[cur][i]) bfs(i, isConnected, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        vector<int> visited(N, 0);

        for (int i=0; i<N; i++) {
            if (visited[i] == 0) {
                prov++;
                bfs(i, isConnected, visited);
            }
        }

        return prov;
    }
};