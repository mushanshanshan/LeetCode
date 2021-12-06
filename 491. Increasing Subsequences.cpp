class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& nums, int sIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        
        vector<bool> used(201, false);
        
        for (int i=sIndex; i<nums.size(); i++) {
            if ((path.size()>0 && path.back()>nums[i]) || used[nums[i]+100] == true) {
                continue;
            }
            
            used[nums[i] + 100] = true;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
            
        }
        
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};