class Solution {
public:
    vector<vector<int>> result{};
    vector<int> path{};
    int sum=0;
    
    void backtrack(int k, int n, int s) {
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i=s; i<=9; i++) {
            path.push_back(i);
            sum += i;
            backtrack(k, n, i+1);
            path.pop_back();
            sum -=i;
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return result;
    }
};