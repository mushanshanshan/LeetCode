class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        dp[0][0] = triangle[0][0];
        
        for (int i=1; i<n; i++) {
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            
            for (int j=1; j<i; j++) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }

            dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        }
        

        for (int& i: dp[n-1]){
            if (i < res) res = i;
        }
        
        return res;
    }
};