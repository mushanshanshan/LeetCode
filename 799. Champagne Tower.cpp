class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(2, vector<double>(101, 0));
        dp[0][0] = poured;
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                dp[(r+1)%2][c] = 0;
            }
            for (int c = 0; c <= r; c++) {
                if (dp[r%2][c] > 1) {
                    dp[(r+1)%2][c] += (dp[r%2][c] - 1) / 2.0;
                    dp[(r+1)%2][c+1] += (dp[r%2][c] - 1) / 2.0;
                }
            }
        }

        return min(1.0, dp[query_row%2][query_glass]);
    }
};