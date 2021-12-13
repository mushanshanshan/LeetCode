class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i=s.size()-1; i>-1; i--) {
            for (int j=i; j<=s.size()-1; j++) {
                if (s[i] == s[j]) {
                    if (j-i < 2) {
                        dp[i][j] = true;
                        res++;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                        if (dp[i][j]) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};