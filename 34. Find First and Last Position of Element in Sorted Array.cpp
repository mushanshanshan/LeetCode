class Solution {
    int start(vector<int>& nums, int target) {
        int m, l = 0, r = nums.size()-1;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                r = m - 1;
            }
        }

        return (l >= nums.size() || nums[l] != target)? -1: l;
    }

    int end(vector<int>& nums, int target) {
        int m, l = 0, r = nums.size()-1;

        while (l <=r) {
            m = l + (r - l) / 2;

            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return (r < 0 || nums[r] != target)? -1: r;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {start(nums, target), end(nums, target)};
    }
};