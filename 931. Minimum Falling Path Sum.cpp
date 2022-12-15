class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cur = 0, pre = 1;
        vector<vector<int>> dp(2, vector<int>(matrix.size(), 0));
        
        for (int i=0; i<n; i++) {
            dp[pre][i] = matrix[n-1][i];
        }

        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<n; j++) {
                dp[cur][j] = matrix[i][j] + min(dp[pre][j], min(j==0?INT_MAX:dp[pre][j-1], j==n-1?INT_MAX:dp[pre][j+1]));
            }
            swap(cur, pre);
        }

        int res = INT_MAX;
        for (int i: dp[pre]) {
            res = min(i, res);
        }

        return res;

    }
};