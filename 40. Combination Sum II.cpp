class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    int n;
    
    
    void backtracking(vector<int>& candidates, vector<bool>& used, int target, int start) {

        if (target == 0) {
            res.push_back(temp);
            return;
        }
        
        if (start == n) return;
        
        for (int i=start; i<n; i++) {
            if (candidates[i] > target) break;
            if (i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) continue;
            temp.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, used, target-candidates[i], i+1);
            used[i] = false;
            temp.pop_back();
        }
        
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        n = used.size();
        
        backtracking(candidates, used, target, 0);
        
        return res;
    }
};