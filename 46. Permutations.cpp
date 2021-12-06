class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& nums, vector<bool> used){
        if (path.size() == nums.size()) {
            result.push_back(path);
        }
        
        for (int i=0; i<nums.size(); i++){
            if (used[i] == 1) {
                continue;
            }
            
            used[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = 0;
            path.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};