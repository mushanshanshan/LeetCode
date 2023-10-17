class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int N = cost.size();
        vector<int> dp(N+1, 1e9);
        dp[0] = 0;

        for (int i=0; i<N; i++) {
            for (int j=N; j>0; j--) {
                dp[j] = min(dp[j], cost[i] + dp[max(j - time[i] - 1, 0)]);
            }
        }

        return dp[N];
    }
};