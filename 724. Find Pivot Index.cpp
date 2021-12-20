class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0, right;
        
        for (int& i:nums) sum += i;
        
        for (int i=0; i<nums.size(); i++) {
            left+=nums[i];
            right = sum - left + nums[i];
            if (left == right) return i;
        }
        return -1;
    }
};