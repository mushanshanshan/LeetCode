class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp=0, res=INT_MIN;
        
        for (int i=0; i<nums.size(); i++) {
            temp += nums[i];
            res = max(temp, res);
            temp = max(0, temp);
        }
        
        return res;
    }
};