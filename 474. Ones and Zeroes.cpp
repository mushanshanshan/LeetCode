class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> counter(strs.size(), vector<int>(2, 0));
        for (int i=0; i<strs.size(); i++) {
            for (char c: strs[i]) {
                if (c=='0') {
                    counter[i][0]++;
                } else {
                    counter[i][1]++;
                }
            }
        }
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (vector<int> v: counter) {
            for (int i=m; i>=v[0]; i--) {
                for (int j=n; j>=v[1]; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-v[0]][j-v[1]]+1);
                }
            }
        }
        
        return dp[m][n];
        
    }
};