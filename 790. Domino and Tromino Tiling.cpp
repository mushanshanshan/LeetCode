/*
 * @Date: 2022-12-24 15:58:21
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-24 15:58:34
 * @FilePath: /LeetCode/790. Domino and Tromino Tiling.cpp
 */
class Solution {
    int REM = 1e9+7;
public:
    int numTilings(int n) {
        vector<long long> dp(max(4,n+1), 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i=4; i<=n; i++) dp[i] = (2 * dp[i-1] + dp[i-3]) % REM;
        return dp[n];
    }
};