class Solution {
public:
    int numSquares(int n) {
        vector<int> square{};
        
        int i = 1;
        while(true) {
            if (i*i > n) {break;}
            square.push_back(i*i);
            i++;
        }
        
        vector<int> dp(n+1, INT_MAX-10);
        dp[0] = 0;
        
        for (int i=0; i<square.size(); i++) {
            for (int j=square[i]; j<=n; j++) {
                dp[j] = min(dp[j], dp[j-square[i]]+1);
            }
        }
        
        return dp[n];
        
    }
};