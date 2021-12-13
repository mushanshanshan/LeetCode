class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1 , vector<uint64_t>(t.size()+1, 0));
        for (int i=0; i<s.size(); i++) dp[i][0] = 1;
        
        
        for(int i=0; i<s.size(); i++) {
            for (int j=0; j<t.size(); j++) {
                if (s[i] == t[j]) {
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                    // bagg -bag => 
                } else {
                    // bass - bag =>
                    dp[i+1][j+1] = dp[i][j+1];
                }
                
            }
        }
        return dp[s.size()][t.size()];
    }
};