class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int max_len = 0, start = 0;
        string res;
        for (int i=s.size()-1; i>=0; i--) {
            for (int j=i; j<s.size(); j++) {
                if (i==j) {
                    dp[i][j] = true;
                    if (max_len < 1) {
                        max_len = 1;
                        start = i;
                    }
                } else if (j-1==i && s[j]==s[i]) {
                    dp[i][j] = true;
                    if (max_len < 2) {
                        max_len = 2;
                        start = i;
                    }
                } else if (j > i+1 && s[j]==s[i]) {
                    dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j] && max_len < j - i + 1) {
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        
        return s.substr(start, max_len);
    }
};