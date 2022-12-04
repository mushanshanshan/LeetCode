class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1, zero = 0;
        for (int i : nums) {
            if (i != 0) total *= i;
            else zero++;
        }
        
        vector<int> res(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero == 1) {
                    res[i] = total;
                } else {
                    res[i] = 0;
                }
            } else {
                if (zero > 0) {
                    res[i] = 0;
                } else {
                    res[i] = total / nums[i];
                }
            }
        }
        
        return res;
    }
};