class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15000, 0);
        
        int sum = 0;
        for (int i: stones) {
            sum += i;
        }
        int target = sum / 2;
        
        for (int i=0; i<stones.size(); i++) {
            for (int j=sum; j>=stones[i]; j--) {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        
        return sum - dp[target] - dp[target];
    }
};