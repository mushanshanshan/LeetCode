class Solution {
public:
    int row, col;
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        
        if (dp[i][j]) return dp[i][j];
        
        int mx = 1;
        
        for (auto & a: dir) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || y < 0 || x >= row || y >= col || matrix[x][y] <= matrix[i][j]) continue;
            mx = max(mx, dfs(matrix, dp, x, y) + 1);
        }
        
        dp[i][j] = mx;
        return mx;
    }
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int res = 1;
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        
        return res;
        
    }
};