class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][0] = nums[0];

        for (int i=1; i<N; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }

        return max(dp[N-1][0], dp[N-1][1]);
    }
};