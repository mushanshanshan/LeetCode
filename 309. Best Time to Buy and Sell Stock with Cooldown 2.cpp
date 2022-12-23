class Solution {
    

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        vector<vector<int>> dp(4, vector<int>(n, 0));
        // 0-buy, 1-sell, 2-cooldown, 3-no action

        dp[0][0] = -prices[0];

        for (int i=1; i<n; i++) {
        
            dp[0][i] = max(dp[0][i-1], max(dp[3][i-1] - prices[i], dp[2][i-1] - prices[i]));
            dp[1][i] = dp[0][i-1] + prices[i];
            dp[2][i] = dp[1][i-1];
            dp[3][i] = max(dp[2][i-1], dp[3][i-1]);

        }

        for (int i: dp[1]){
            res = max(res, i);
        }

        return res;

    }
};