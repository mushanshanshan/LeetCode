class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int N = arr.size();
            int res = 0;
    
            vector<vector<int>> dp(N, vector<int>(N, 2));
            unordered_map<int, int> re_arr;
    
            for (int i=0; i<N; i++) re_arr[arr[i]] = i;
    
            for (int i=2; i<N; i++) {
                for (int j=i-1; j>=0; j--) {
                    if (arr[i] - arr[j] < arr[j] && re_arr.count(arr[i] - arr[j]) == 1) {
                        dp[j][i] = dp[re_arr[arr[i] - arr[j]]][j] + 1;
                        res = max(res, dp[j][i]);
                    }
                }
            }
    
            return res;
        }
    };