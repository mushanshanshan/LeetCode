class Solution {
public:
   
    
    int rob(vector<int>& nums) {
        
        if (nums.size()==1) return nums[0];
        if (nums.size()==0) return 0;
        
        vector<int> ldp(nums.size()+1, 0);
        for (int i=2; i<nums.size()+1; i++) {
            ldp[i] = max(ldp[i-1], ldp[i-2]+nums[i-2]);
        }
        int left = ldp[nums.size()];
        
        vector<int> rdp(nums.size()+1, 0);
        for (int i=2; i<nums.size()+1; i++) {
            rdp[i] = max(rdp[i-1], rdp[i-2]+nums[i-1]);
        }
        int right = rdp[nums.size()];
        
        return max(left, right);
    }
};