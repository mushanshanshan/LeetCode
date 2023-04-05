class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long psum = 0.0;
        long res = 0;
        int N = nums.size();
        for (int i=0; i<N; ++i) {
            psum += nums[i];
            res = max(res, (psum + i) / (i + 1));
        }

        return res;
    }
};