class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0;
        for (int i: nums) {s += i;}
        if (abs(target) > s) return 0;
        if ((s+target)%2 != 0) return 0;
        
        int t = (s+target) / 2;
        vector<int> dp(t+1, 0);
        dp[0] = 1;
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=t; j>=nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[t];
    }
};