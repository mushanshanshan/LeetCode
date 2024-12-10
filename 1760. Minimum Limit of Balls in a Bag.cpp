class Solution {
private:
    bool search(vector<int>& nums, int maxOperations, int target) {
        for (int n : nums) {
            maxOperations -= (n - 1) / target;
            if (maxOperations < 0) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (search(nums, maxOperations, mid)) {
                right = mid;  // Try a smaller penalty
            } else {
                left = mid + 1;  // Increase penalty
            }
        }
        return left;
    }
};
