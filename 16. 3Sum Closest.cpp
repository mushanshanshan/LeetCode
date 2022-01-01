class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), i=0, j, k;
        int res = nums[0]+nums[1]+nums[2], diff = abs(target - res);
        int temp, tempDiff;
        
        while (i < n-2) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                temp = nums[i]+nums[j]+nums[k];
                
                tempDiff = abs(target - temp);
                if (tempDiff == 0) return temp;
                if (tempDiff < diff) {
                    res = temp;
                    diff = tempDiff;
                }
                
                if (temp > target) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        return res;
    }
};