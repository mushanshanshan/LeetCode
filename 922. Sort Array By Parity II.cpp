class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1, even = 0;
        
        while (odd < nums.size() && even < nums.size()) {
            if (nums[odd] % 2) {
                odd += 2;
                continue;
            }
            if (nums[even] % 2 == 0) {
                even +=2;
                continue;
            }
            swap(nums[odd], nums[even]);
        }
        
        return nums;
    }
};