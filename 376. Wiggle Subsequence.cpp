class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int count=1, temp=nums[0], flag=0;
        
        for (int i=1; i<nums.size(); i++) {
            if (flag == 0 && nums[i]!=nums[i-1]) {
                count++;
                temp = nums[i];
                if (nums[i]>nums[i-1]) {
                    flag = 1;
                } else {
                    flag = -1;
                }
            } else if (flag == 1) {
                if (nums[i]>nums[i-1]) {
                    temp = nums[i];
                } else if (nums[i]<nums[i-1]) {
                    temp = nums[i];
                    count++;
                    flag = -1;
                }
            } else if (flag == -1) {
                if (nums[i]<nums[i-1]) {
                    temp = nums[i];
                } else if (nums[i]>nums[i-1]) {
                    temp = nums[i];
                    count++;
                    flag = 1;
                }
            }
        }
        
        
        return count;
    }
};