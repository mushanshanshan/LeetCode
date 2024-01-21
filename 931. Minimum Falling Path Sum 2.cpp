class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size(), res = INT_MAX;
        vector<vector<int>> dp(2, vector<int>(N, 0));

        for (int j=0; j<N; j++) dp[0][j] = matrix[0][j];

        for (int i=1; i<N; i++) {
            for (int j=0; j<N; j++) {
                int temp = dp[(i-1)%2][j];
                if (j > 0) temp = min(temp, dp[(i-1)%2][j-1]);
                if (j < N-1) temp = min(temp, dp[(i-1)%2][j+1]);
                dp[i%2][j] = matrix[i][j] + temp;

            }

        }

        for (int i: dp[(N-1)%2]) res = min(i, res);

        return res;
    }
};