class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101,-1);
        vector<int> s(nums.begin(), nums.end());
        
        sort(s.begin(), s.end());
        for (int i=0; i<nums.size(); i++) {
            if (count[s[i]] == -1) count[s[i]] = i;
        }
        for (int i=0; i<nums.size(); i++) s[i] = count[nums[i]];
        
        return s;
        
    }
};