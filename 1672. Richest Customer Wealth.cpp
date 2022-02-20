class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int res = 0;
        
        for (int i=0; i<m; i++) {
            int temp = 0;
            for (int j=0; j<n; j++) {
                temp += accounts[i][j];
            }
            res = max(res, temp);
        }
        
        return res;
    }
};