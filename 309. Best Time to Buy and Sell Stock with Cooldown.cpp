class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(4, vector<int>(prices.size(), 0));
        // 0-no action; 1-buy; 2-sell; 3-cooldown;
        
        dp[1][0] -= prices[0];
        
        for (int i=1; i<prices.size(); i++) {
            dp[0][i] = max(dp[0][i-1], dp[3][i-1]);
            dp[1][i] = max(dp[1][i-1], max(dp[0][i-1] - prices[i], dp[3][i-1] - prices[i]));
            dp[2][i] = max(dp[2][i-1], dp[1][i-1] + prices[i]);
            dp[3][i] = dp[2][i-1];
        }
        
        int s = 0;
        for (int i=0; i<4; i++) {
            s = max(s, dp[i][prices.size()-1]);
        }
        
        return s;
    }
};