class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int N, M, K, H;

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        N = isWater.size();
        M = isWater[0].size();
        H = 0;
        queue<vector<int>> q;
    
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
                else isWater[i][j] = -1;
            }
        }

        while (!q.empty()) {
            int qs = q.size();
            H++;
            for (int k=0; k<qs; k++) {
                int x = q.front()[0];
                int y = q.front()[1];
                q.pop();
                for (auto& d: dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && isWater[nx][ny] == -1) {
                        isWater[nx][ny] = H;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return isWater;
    }
};