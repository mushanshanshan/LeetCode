class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, count = 0;
        
        if (s[0] == 'L') count--;
        else count++;
        
        for (int i=1; i<s.size(); i++) {
            if (s[i] == 'L') count--;
            else count++;
            if (count == 0) {
                res++;
            }
        }
        return res;
    }
};