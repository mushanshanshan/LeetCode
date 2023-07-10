class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, res = INT_MAX, N = nums.size();

        for (int r=0; r<N; r++) {
            sum += nums[r];
            
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            if (sum >= target) res = min(res, r - l + 1);
        }

        return res == INT_MAX? 0: res;
    }
};