class Solution {
private:
    int simple(int i) {
        if (i == 0) return 0;
        return i > 0? 1: -1;
    }


public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) return true;

        int diff = 0;
        for (int i=1; i<nums.size(); i++) {
            if (diff == 0) diff = simple(nums[i] - nums[i-1]);
            else if (simple(nums[i] - nums[i-1]) * diff < 0) return false;
        }

        return true;
    }
};