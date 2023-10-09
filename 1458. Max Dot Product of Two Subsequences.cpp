class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector(nums2.size(), 0));

        for (int r=0; r<nums1.size(); r++) {
            for (int c=0; c<nums2.size(); c++) {
                dp[r][c] = nums1[r] * nums2[c];
                if (r > 0 && c > 0) dp[r][c] += max(0, dp[r-1][c-1]);
                if (r > 0) dp[r][c] = max(dp[r][c], dp[r-1][c]);
                if (c > 0) dp[r][c] = max(dp[r][c], dp[r][c-1]);
            }
        }

        return dp[nums1.size()-1][nums2.size()-1];
    }
};