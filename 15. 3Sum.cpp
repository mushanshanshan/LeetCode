class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), target;
        
        for(int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            target = 0 - nums[i];
            int left = i+1, right = n-1;
            
            while (left < right) {
                
                int s = nums[left] + nums[right];
                if (s == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    int ans_left = nums[left], ans_right = nums[right];
                    while (left < right && nums[left] == ans_left) left++;
                    while (left < right && nums[right] == ans_right) right--;
                } else if (s < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};