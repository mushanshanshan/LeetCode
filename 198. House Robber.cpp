class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);
        
        for(int i=2; i<nums.size()+2; i++) {
            dp[i] = max(dp[i-2] + nums[i-2],dp[i-1]);
        }
        
        return dp[nums.size()+1];
    }
};