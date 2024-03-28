class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, N = nums.size(), res = 0;
        int exceed = 0;
        unordered_map<int, int> counter;

        while (l <= r && r < N) {
            // printf("%d-%d-%d\n", l, r, exceed);
            if (exceed == 0) {
                counter[nums[r]]++;
                if (counter[nums[r]] > k) {
                    exceed = nums[r];
                    r++;
                    continue;
                } else {
                    res = max(res, r - l + 1);
                    r++;
                }
            } else {
                counter[nums[l]]--;
                if (nums[l] == exceed) {
                    exceed = 0;
                }
                l++;
            }
        }

        return res;

    }
};