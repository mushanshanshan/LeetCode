class Solution {
public:
    void partition(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        
        int pivot = nums[left], l = left, r = right;
        
        while (l < r) {
            while (l < r && nums[r] >= pivot) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        
        partition(nums, left, l-1);
        partition(nums, l+1, right);
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        partition(nums, 0, nums.size()-1);
        return nums;
    }
};