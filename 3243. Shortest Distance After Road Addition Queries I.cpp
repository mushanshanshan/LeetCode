class Solution {
private:
    int N;

    int bfs(vector<vector<int>>& graph) {
        vector<int> visited(N, 0);
        queue<int> q;
        int step = 0;
        q.push(0);

        while (!q.empty()) {
            step++;
            int q_size = q.size();
            for (int i=0; i<q_size; i++) {
                int cur = q.front();
                // printf("%d\n", cur);
                q.pop();

                for (int j=0; j<N; j++) {
                    if (j != cur && graph[cur][j] == 1 && visited[j] == 0) {
                        if (j == N-1) return step;
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }

        return -1;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<int> res;
        N = n;

        for (int i=0; i<N-1; i++) {
            graph[i][i+1] = 1;
        }

        for (auto& q: queries) {
            graph[q[0]][q[1]] = 1;
            res.push_back(bfs(graph));
        }

        return res;
    }
};