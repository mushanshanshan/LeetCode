class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k, N = nums.size(), m = nums[k], res = nums[k];

        while (l > 0 || r < N-1) {
            if (l == 0) {
                m = min(m, nums[++r]);
            } else if (r == N-1) {
                m = min(m, nums[--l]);
            } else {
                if (nums[l-1] < nums[r+1]) {
                    m = min(m, nums[++r]);
                } else {
                     m = min(m, nums[--l]);
                }
            }

            //printf("%d-%d-%d\n", l, r, m);
            res = max(res, m * (r - l + 1));
        }

        return res;
    }
};