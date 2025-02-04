class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int cur = nums[0];
        int N = nums.size();

        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                cur += nums[i];
            } else {
                res = max(res, cur);
                cur = nums[i];
            }
        }

        return max(res, cur);
    }
};