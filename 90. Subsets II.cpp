class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& nums, int start, vector<bool> used) {
        result.push_back(path);
        
        if (start == nums.size()) {return;}
        
        for (int i=start; i<nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]==0) {continue;}
            
            path.push_back(nums[i]);
            used[i] = 1;
            backtracking(nums, i+1, used);
            path.pop_back();
            used[i] = 0;
        }
        
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};