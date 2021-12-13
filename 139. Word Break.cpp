class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        string temp;
        
        for(int i=0; i<=s.size(); i++) {
            for (int j=0; j<i; j++) {
                temp = s.substr(j, i-j);
                if (dict.find(temp) != dict.end() && dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};