class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        
        dp[0][0][col-1] = grid[0][0] + grid[0][col-1];
        
        for (int i=1; i<row; i++) {
            for (int j=0; j<col-1; j++) {
                for (int k = j+1; k<col;k++) {
                    int temp = grid[i][j] + grid[i][k];
                    for (int n = j-1; n<=j+1; n++) {
                        for (int m = k-1; m<=k+1; m++) {
                            if (n>=0 && m<col && dp[i-1][n][m]>=0) {
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][n][m] + temp);
                            }
                        }
                    }
                    if (i == row - 1) res = max(res, dp[i][j][k]);
                }
            }
        }

        
        return res;
    }
};