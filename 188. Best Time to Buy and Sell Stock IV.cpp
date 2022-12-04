class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()<2) return 0;
        
        vector<vector<int>> dp(2*k+1, vector<int>(prices.size(), 0));
        for (int i=1; i<2*k+1; i +=2) {
            dp[i][0] -= prices[0];
        }
        
        
        for (int i=1; i<prices.size(); i++) {
            for (int j=0; j<=2*k; j++) {
                if (j % 2 == 1) {
                    dp[j][i] = max(dp[j][i-1], dp[j-1][i-1] - prices[i]);
                } else if (j > 0) {
                    dp[j][i] = max(dp[j][i-1], dp[j-1][i-1] + prices[i]);
                }
            }
        }
        
        return dp[2*k][prices.size()-1];
    }
};