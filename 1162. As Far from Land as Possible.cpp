class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = 0, N = grid.size(), UPPER_BOUND = 1000;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j] != 1) {
                    grid[i][j] = min(UPPER_BOUND, min(i > 0 ? grid[i-1][j]+1 : UPPER_BOUND, j > 0 ? grid[i][j-1]+1 : UPPER_BOUND));
                }
            }
        }

        for (int i=N-1; i>=0; i--) {
            for (int j=N-1; j>=0; j--) {
                if (grid[i][j] != 1) {
                    grid[i][j] = min(grid[i][j], min(i != N-1 ? grid[i+1][j]+1 : UPPER_BOUND, j != N-1 ? grid[i][j+1]+1 : UPPER_BOUND));
                    res = max(res, grid[i][j]);
                }
            }
        }

        return res == UPPER_BOUND? -1 : res - 1;
    }
};