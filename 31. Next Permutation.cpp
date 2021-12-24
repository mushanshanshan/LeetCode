class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur = nums.size()-2, left, rihgt;
        
        while (cur>=0) {
            if (nums[cur] < nums[cur+1]) break;
            cur--;
        }
        
        if (cur == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        left = cur;
        cur = nums.size()-1;
        
        while (cur>=0) {
            if (nums[cur] > nums[left]) break;
            cur--;
        }
        
        swap(nums[cur], nums[left]);

        
        reverse(nums.begin()+left+1, nums.end());
        return;
    }
};