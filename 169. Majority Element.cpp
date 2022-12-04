class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0, count = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (count == 0) {
                count++;
                cur = nums[i];
            } else if (nums[i] == cur) {
                count++;
            } else {
                count--;
            }
        }
        
        return cur;
    }
};