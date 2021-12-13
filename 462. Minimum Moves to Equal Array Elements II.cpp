class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        
        int s = nums[nums.size() / 2];
        
        for (int i:nums) {
            res += abs(i - s);
        }
        
        return res;
    }
};