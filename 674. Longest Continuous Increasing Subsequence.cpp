class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int temp=1, res=0;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                temp++;
            } else {
                res = max(res, temp);
                temp = 1;
            }
        }
        res = max(res, temp);
        return res;
    }
};