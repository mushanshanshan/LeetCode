class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, cur = 0;
        int count = 0;

        for (int i=0; i<nums.size(); i++) {
            if (cur > nums[i]) {
                count = i;
                res = cur + nums[i];
            }
            cur += nums[i];
        }

        return count > 1? res: -1;;
    }
};