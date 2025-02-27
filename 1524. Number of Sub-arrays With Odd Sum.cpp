class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD = 1e9 + 7;
            int N = arr.size();
            int res = 0;
            vector<vector<int>> dp(2, vector<int>(N+1, 0));
    
            for (int i=N-1; i>=0; i--) {
                if (arr[i] % 2 == 0) {
                    dp[0][i] = (dp[0][i+1] + 1) % MOD;
                    dp[1][i] = (dp[1][i+1]) % MOD;
                } else {
                    dp[0][i] = (dp[1][i+1]) % MOD;
                    dp[1][i] = (dp[0][i+1] + 1) % MOD;
                }
            }
    
            for (int i: dp[1]) {
                res = (res + i) % MOD;
            }
                
            return res;
        }
    };