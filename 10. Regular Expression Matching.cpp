class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        for (int i=0; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || dp[i][j];
                    if (i>0 && (p[j-2] == '.' || p[j-2] == s[i-1])) {
                        dp[i][j] = dp[i-1][j]  || dp[i][j];
                    }
                } else if (i>0 && p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1]  || dp[i][j];
                } else if (i>0 && p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1]  || dp[i][j];
                }

            }
        }
        
        return dp[m][n];
        
        
    }
};