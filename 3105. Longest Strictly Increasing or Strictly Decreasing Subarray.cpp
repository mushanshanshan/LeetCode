class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) {
        int ans = 1;
        for (int inc = 1, dec = 1, i = 1; i < ssize(nums); ++i) {
            inc = nums[i - 1] < nums[i] ? inc + 1 : 1;
            dec = nums[i - 1] > nums[i] ? dec + 1 : 1;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};