class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        

        while (left < right) {
            while (nums[left] % 2 == 0 && left < right) left++;
            while (nums[right] % 2 != 0 && left < right) right--;
            if (left < right) swap(nums[left], nums[right]);
        }

        return nums;
    }
};