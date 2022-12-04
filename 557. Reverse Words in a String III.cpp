class Solution {
public:
    string reverseWords(string s) {
        int cur = 0, pre = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + pre, s.begin() + i);
                pre = i+1;
            }
        }
        
        reverse(s.begin() + pre, s.end());
        return s;
    }
};