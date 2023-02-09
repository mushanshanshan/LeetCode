class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;

        for (int i=0; i<N; i++) {
            for (int j=1; j<=nums[i] && i+j<N; j++) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        
        return dp[N-1];
    }
};