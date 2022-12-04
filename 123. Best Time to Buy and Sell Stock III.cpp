class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(5, vector<int>(prices.size(), 0));
        dp[1][0] -= prices[0];
        dp[3][0] -= prices[0];
        
        for (int i=1; i<prices.size(); i++) {
            for (int j=1; j<5; j++) {
                if (j%2==1) {
                    dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]-prices[i]);
                } else {
                    dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]+prices[i]);
                }
            }
        }
        
        return max(dp[4][prices.size()-1], dp[2][prices.size()-1]);
    }
};