class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp = {0, 1, 1};

        while (dp.size() <= n) {
            dp.push_back(dp[dp.size()-1] + dp[dp.size()-2] + dp[dp.size()-3]);
        }

        return dp[n];
    }
};
