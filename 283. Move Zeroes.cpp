class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0, n = nums.size()-1;
        
        while (fast < n) {
            while (slow < n && nums[slow] != 0) slow++;
            fast = slow;
            while (fast < n && nums[fast] == 0) fast++;
            swap(nums[fast], nums[slow]);
        }
    }
};