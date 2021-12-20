class Solution {
public:
    bool checkValidString(string s) {
        int pmax = 0, pmin = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                pmax++;
                pmin++;
            } else if (s[i] == ')') {
                pmax--;
                pmin = max(0, pmin-1);
            } else {
                pmax++;
                pmin = max(0, pmin-1);
            }
            if (pmax < 0) return false;
        }
        
        return pmin==0;
    }
};