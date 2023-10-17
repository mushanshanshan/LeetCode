class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(2, vector<int>(rowIndex+1, 0));
        dp[0][0] = 1;

        for (int r=1; r<=rowIndex; r++) {
            for (int c=0; c<=r; c++) {
                int cur = r % 2;
                if (c == 0) dp[cur][c] = 1;
                else if (c == r) dp[cur][c] = 1;
                else {
                    int pre = (r-1) % 2;
                    dp[cur][c] = dp[pre][c] + dp[pre][c-1];
                }  
            }
        }

        return dp[rowIndex%2];
    }
};