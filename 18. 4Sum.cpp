class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        long temp, _temp;
        
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n-3; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            temp = (long)nums[i] + (long)nums[i+1] + (long)nums[i+2] + (long)nums[i+3];
            if (temp > target) break;
            temp = (long)nums[i] + (long)nums[n-1] + (long)nums[n-2] + (long)nums[n-3];
            if (temp < target) continue;
            
            for (int j=i+1; j<n-2; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                temp = (long)nums[i]+(long)nums[j]+(long)nums[j+1]+(long)nums[j+2];
                if(temp > target) break;
                temp = (long)nums[i]+(long)nums[j]+(long)nums[n-2]+(long)nums[n-1];
                if(temp < target) continue;
                int l = j+1, r = n-1, temp = target - nums[i] - nums[j];
                
                while (l < r) {
                    _temp = (long)nums[l] + (long)nums[r];
                    if (_temp > temp) r--;
                    else if (_temp < temp) l++;
                    else {
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while (l<r && nums[l-1] == nums[l]) l++;
                        while (l<r && nums[r+1] == nums[r]) r--;
                    }
                }
            }
        }
        
        return res;
    }
};