class Solution {
public:
    vector<vector<int>> result{};
    vector<int> path{};
    int sum=0;
    
    void backtrack(vector<int>& candidates, int target, int start) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }
        
        for (int i=start; i<candidates.size();i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
};