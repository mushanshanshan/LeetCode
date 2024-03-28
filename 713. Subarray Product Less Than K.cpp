class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int cur_mul = 1, res = 0, N = nums.size(), start = 0;

        for (int end = 0; end < N; end++) {
            cur_mul *= nums[end];

            while (cur_mul >= k) {
                cur_mul /= nums[start++];
            }

            res += end - start + 1;
        }

        return res;
    }
};
