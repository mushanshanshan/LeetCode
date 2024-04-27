class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }

        for (int r = 1; r < n; ++r) {
            int pr = (r - 1) % 2;
            int cr = r % 2;
            fill(dp[cr].begin(), dp[cr].end(), INT_MAX);
            
            for (int cc = 0; cc < n; ++cc) {
                for (int pc = 0; pc < n; ++pc) {
                    if (cc != pc) { 
                        dp[cr][cc] = min(dp[cr][cc], dp[pr][pc] + grid[r][cc]);
                    }
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[(n-1) % 2][i]);
        }

        return res;
    }
};
