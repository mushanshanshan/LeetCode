class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r = nums.size()-1, m;
        
        while (l<r) {
            m = l + (r-l) / 2;
            if (m % 2 == 0) {
                if (nums[m+1] == nums[m]) {
                    l = m + 1;
                } else if (nums[m-1] == nums[m]) {
                    r = m - 2;
                } else {
                    return nums[m];
                }
                
            } else {
                if (nums[m+1] == nums[m]) {
                    r = m - 1;
                } else if (nums[m-1] == nums[m]) {
                    l = m +1;
                } else {
                    return nums[m];
                }
            }
        }
        return nums[r];
    }
};