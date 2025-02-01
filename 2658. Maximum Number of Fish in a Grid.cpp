class Solution {
private:
    int res = 0;
    int cur_res;
    int N, M;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, int x, int y) {
        cur_res += grid[x][y];
        grid[x][y] = 0;

        for (auto& d: dirs){
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] > 0) {
                dfs(grid, nx, ny);
            }
        }

        return;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] > 0) {
                    cur_res = 0;
                    dfs(grid, i, j);
                    res = max(res, cur_res);
                }
            }
        }

        return res;
    }
};