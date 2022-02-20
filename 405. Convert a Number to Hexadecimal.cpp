class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res = "";
        long cur;
        int temp;
        char ch;
        
        if (num < 0) {
            cur = pow(2, 32) + (long)num;
        } else {
            cur = num;
        }
        
        while (cur) {
            temp = cur % 16;
            cur /= 16;
            if (temp < 10) {
                ch = '0' + temp;
            } else {
                ch = 'a' + temp - 10;
            }
            res = ch + res;
        }
        
        return res;
    }
};