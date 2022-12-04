class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        if (n==1) return 0;
        
        for (int i=1; i<n+1; i++) {
            dp[i] = i;
            for (int j=i-1; j>1; j--) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i/j);
                    break;
                }
            }
        }
        return dp[n];
    }
};