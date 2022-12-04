class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int res = 0, left = 0;
        
        for (int i=0; i<s.size(); i++) {
            left = max(left, dict[s[i]] + 1);
            res = max(res, i - left + 1);
            dict[s[i]] = i;
        }
        
        
        return res;
    }
};