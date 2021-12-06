class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, maxr = 0, pre_max = 0;
        
        for (int i=0; i<nums.size(); i++) {
            maxr = max(maxr, i+nums[i]);
            if (i == nums.size()-1){
                return step;
            }
            if (i == pre_max) {
                step++;
                pre_max = maxr;
            }
            
        }
        return 0;
    }
};