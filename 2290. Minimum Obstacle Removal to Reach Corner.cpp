class Solution {
private:
    vector<pair<int, int>> dirction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int step = 0;

        vector<vector<int>> visited(N, vector<int>(M, 0));
        deque<vector<int>> q;
        q.push_front({0, 0, 0});

        while (!q.empty()) {
            int qsize = q.size();
            step++;
            for (int i=0; i<qsize; i++) {
                auto cur = q.front();
                q.pop_front();

                for (auto& d: dirction) {
                    int cx = cur[0] + d.first;
                    int cy = cur[1] + d.second;
                    if (cx < 0 || cy < 0 || cx >= N || cy >= M || visited[cx][cy] == 1) continue;

                    if (cx == N-1 && cy == M-1) return cur[2];
                    visited[cx][cy] = 1;
                    if (grid[cx][cy] == 0) q.push_front({cx, cy, cur[2]});
                    else q.push_back({cx, cy, cur[2]+1});
                }
            }
        }

        return -1;
    }
};