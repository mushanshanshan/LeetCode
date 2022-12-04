class Solution {
public:
    string reverseWords(string s) {
        string res;
        int cur = 0, n = s.size(), start, len;
        
        while (cur < n) {
            if (s[cur] != ' '){
                start = cur;
                while (cur < n && s[cur] != ' ') {
                    cur++;
                }

                res = s.substr(start, cur - start) + res;
                res = ' ' + res;

                
            }
            
            cur++;
        }
        
        return res.substr(1);
    }
};