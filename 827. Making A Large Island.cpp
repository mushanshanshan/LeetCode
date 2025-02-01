class Solution {
private:
    unordered_map<int, vector<int>> connected_land_size;
    unordered_set<int> temp_connected;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int temp_size = 0;
    int N = 0;
    int M = 0;

    void dfs(vector<vector<int>>& grid, int x, int y) {
        temp_size++;
        grid[x][y] = -1;
        for (auto& d: dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (grid[nx][ny] == 0) temp_connected.insert(nx * 600 + ny);
                else if (grid[nx][ny] == 1) dfs(grid, nx, ny);
            } 
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int res = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 1) {
                    temp_size = 0;
                    temp_connected.clear();
                    dfs(grid, i, j);

                    for (auto& a: temp_connected) {
                        connected_land_size[a].push_back(temp_size);
                    }
                    res = max(temp_size, res);
                }
            }
        }

        for (auto& [key, value]: connected_land_size) {
            if (value.size() == 1) {
                res = max(res, value[0] + 1);
            } else if (value.size() > 1) {
                int sum = 1;
                for (int v: value) sum += v;
                res = max(res, sum);
            }
        }

        return max(res, 1);
    }
};