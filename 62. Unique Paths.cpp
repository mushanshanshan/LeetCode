class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int x=0; x<n; x++) {
            for (int y=0; y<m; y++) {
                if (x==0 && y!=0) {
                    dp[y][x] = dp[y-1][x];
                } else if (x!=0 && y==0) {
                    dp[y][x] = dp[y][x-1];
                } else if (x!=0 && y!=0) {
                    dp[y][x] = dp[y][x-1] + dp[y-1][x];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};