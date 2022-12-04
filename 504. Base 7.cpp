class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = (num < 0);
        if (neg) num = -num;
        int base  = 1;
        string res;
        
        while (num != 0) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        

        if (neg) res = "-" + res;
        
        return res;
    }
};