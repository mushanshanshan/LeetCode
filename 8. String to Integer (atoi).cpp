class Solution {
public:
    int myAtoi(string s) {
        int cur = 0, flag = 1;
        long res = 0;
        while (s[cur] == ' ' && cur < s.size()) {
            cur++;
        }
        
        if (s[cur] == '-'){
            flag = -1;
            cur++;
        } else if (s[cur] == '+') {
            cur++;
        }
        
        while (s[cur]>='0' && s[cur]<='9') {
            res = res * 10 + (s[cur] - '0');
            if (res > INT_MAX) return flag == 1? INT_MAX: INT_MIN;
            cur++;
        }
        
        return res*flag;
    }
};