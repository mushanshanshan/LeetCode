class Solution {
private:
    int N, M;
    void bfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= M) return;
        if (grid[x][y] == 1) return;
        grid[x][y] = 1;
        bfs(grid, x-1, y);
        bfs(grid, x, y-1);
        bfs(grid, x+1, y);
        bfs(grid, x, y+1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int res = 0;

        for (int i=0; i<N; i++) {
            bfs(grid, i, 0);
            bfs(grid, i, M-1);
        }

        for (int j=0; j<M; j++) {
            bfs(grid, 0, j);
            bfs(grid, N-1, j);
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }

        return res;
    }
};