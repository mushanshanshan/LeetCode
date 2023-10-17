class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(3, 0);
        int N = cost.size();
 

        for (int i=2; i<N; i++) {
            dp[i%3] = min(dp[(i-2)%3] + cost[i-2], dp[(i-1)%3] + cost[i-1]);
        }

        return dp[(N-1)%3];
    }
};