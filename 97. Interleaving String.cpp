class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n+m != s3.size()) return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0] = true;
        
        for (int i=0; i<n; i++) {
            if (s1[i] == s3[i]) dp[i+1][0] = true;
            else break;
        }
        
        for (int i=0; i<m; i++) {
            if (s2[i] == s3[i]) dp[0][i+1] = true;
            else break;
        }
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (dp[i-1][j] && s3[i+j-1] == s1[i-1]) dp[i][j] = true;
                else if (dp[i][j-1] && s3[i+j-1] == s2[j-1]) dp[i][j] = true;
            }
        }
        
        return dp[n][m];
    }
};