class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, j, k;
        sort(nums.begin(), nums.end());
        
        for (int i=nums.size()-1; i>1; i--) {
            j = 0;
            k = i - 1;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    res += k - j;
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        return res;
    }
};