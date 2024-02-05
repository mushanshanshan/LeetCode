class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> dp(N+1, 0);

        for (int i=1; i<=N; i++) {
            int cm = 0;
            for (int j=1; j<=k && j<=i; j++) {
                cm = max(cm, arr[i-j]);
                dp[i] = max(dp[i], dp[i-j] + cm * j);
            }
        }

        return dp[N];
    }
};