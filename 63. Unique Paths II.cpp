class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        
        dp[0][0] = 1;
        
        for (int x=0; x<obstacleGrid[0].size(); x++) {
            for (int y=0; y<obstacleGrid.size(); y++) {
                if (obstacleGrid[y][x] == 1){
                    dp[y][x] = 0;
                } else if (x==0 && y!=0) {
                    dp[y][x] = dp[y-1][x];
                } else if (x!=0 && y==0) {
                    dp[y][x] = dp[y][x-1];
                } else if (x!=0 && y!=0) {
                    dp[y][x] = dp[y-1][x] + dp[y][x-1];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};