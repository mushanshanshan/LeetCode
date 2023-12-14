class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> onesRow(N, 0);
        vector<int> onesCol(M, 0);

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                grid[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - N - M;
            }
        }


        return grid;
    }
};