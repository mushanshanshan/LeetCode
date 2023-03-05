class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int out_idx = -1, min_idx = -1, max_idx = -1;
        long long res = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == minK) min_idx = i;
            if (nums[i] == maxK) max_idx = i;
            if (nums[i] > maxK || nums[i] < minK) out_idx = i;
            res += max(0, min(min_idx, max_idx) - out_idx);
        }

        return res;
    }
};