class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int r=0; r<m; r++) {
            for (int c=1; c<n; c++) {
                dp[c] += dp[c-1];
            }
        }

        return dp[n-1];
    }
};