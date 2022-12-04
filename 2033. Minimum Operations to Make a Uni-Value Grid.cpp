class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v(m * n, 0);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                v[i*n+j] = grid[i][j];
            }
        }
        
        sort(v.begin(), v.end());
        int target = v[m*n/2], res = 0;
        
        for (int i=0; i<v.size(); i++) {
            if (abs(v[i] - target) % x) {
                return -1;
            } else {
                res += abs(v[i] - target) / x;
            }
        }
        return res;
    }
};