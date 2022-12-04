class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        
        vector<int> dp(s.size(), 0);
        int cur = s[1] - '0';
        int pre = s[0] - '0';
        int temp = pre*10+cur;
        if (cur == 0 && pre != 1 && pre != 2) return 0;
        if (temp > 26) {
            dp[0] = 1;
            dp[1] = 1;
        } else if (temp == 10 || temp == 20) {
            dp[0] = 1;
            dp[1] = 1;
        } else {
            dp[0] = 1;
            dp[1] = 2;
        }
        
        for (int i=2; i<s.size(); i++) {
            int cur = s[i] - '0';
            int pre = s[i-1] - '0';
            int temp = pre*10+cur;
            
            if (cur == 0) {
                if (pre != 1 && pre != 2) {
                    return 0;
                } else{
                    dp[i] = dp[i-2];
                }
            } else if (temp > 26) {
                dp[i] = dp[i-1];
            } else if (pre == 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        
        return dp[s.size()-1];
        
    }
};