class Solution {
public:
    vector<vector<int>> result{};
    vector<int> temp{};
    
    void backtrack(int n, int k, int start) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        
        for (int i=start; i<=n; i++){
            temp.push_back(i);
            backtrack(n, k, i+1);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
};