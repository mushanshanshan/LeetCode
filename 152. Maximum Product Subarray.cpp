class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], n = nums.size(), l = 0, r = 0;
        for (int i=0; i<n; i++) {
            l = (l == 0? 1: l) * nums[i];
            r = (r == 0? 1: r) * nums[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};