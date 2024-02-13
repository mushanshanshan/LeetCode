class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size(), res = 0;
        vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(C, -1)));

        dp[0][0][C-1] = grid[0][0] + grid[0][C-1];

        for (int i=1; i<R; i++) {
            for (int l=0; l<C-1; l++) {
                for (int r=l+1; r<C; r++) {
                    int cherry_cur = grid[i][l] + grid[i][r];
                    for (int l_delta: {-1, 0, 1}){
                        for (int r_delta: {-1, 0, 1}) {
                            int l_pre = l + l_delta;
                            int r_pre = r + r_delta;
                            if (l_pre >= 0 && r_pre < C && dp[i-1][l_pre][r_pre] >= 0){
                                dp[i][l][r] = max(cherry_cur + dp[i-1][l_pre][r_pre], dp[i][l][r]);
                            } 

                            if (i == R-1) res = max(res, dp[i][l][r]);
                        }
                    }

                    
                }
            }
        }

        return res;

    }
};