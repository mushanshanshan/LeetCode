class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0, cur;
        
        for (int i=1; i<n; i++) {
            cur = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (cur == dp[p2] * 2) p2++;
            if (cur == dp[p3] * 3) p3++;
            if (cur == dp[p5] * 5) p5++;
            dp[i] = cur;
        }
        
        return dp[n-1];
    }
};