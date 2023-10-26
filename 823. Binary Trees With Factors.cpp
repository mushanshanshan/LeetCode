class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long> dp;
        int N = arr.size();
        long res = 0;

        sort(arr.begin(), arr.end());
        for (int a: arr) dp[a] = 1;

        for (int i=0; i<N; i++) {
            int limit = sqrt(arr[i]);
            for (int j=0; j<i; j++) {
                if (arr[j] > limit) break;
                if (arr[i] % arr[j] == 0) {
                    int div = arr[i] / arr[j];
                    if (dp.find(div) != dp.end()) {
                        long long count = (dp[arr[j]] * dp[div]) % MOD;
                        if (div == arr[j]) {
                            dp[arr[i]] = (dp[arr[i]] + count) % MOD;
                        } else {
                            dp[arr[i]] = (dp[arr[i]] + count * 2) % MOD;
                        }
                    }
                }
            }
            res = (res + dp[arr[i]]) % MOD;
        }

        return (int)res;
    }
};
