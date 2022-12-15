class Solution {
private:
    
    int _climbStairs(int n){
        vector<int> dp(max(n,2),0);

        dp[0] = 1;
        dp[1] = 2;

        for (int i=2; i<n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n-1];
    }


public:
    int climbStairs(int n) {
        return _climbStairs(n);
    }
};