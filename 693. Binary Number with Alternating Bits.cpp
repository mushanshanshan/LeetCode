class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = (n & 1) ? 1 : 0 , cur;
        n >>= 1;
        while (n) {
            cur = (n & 1) ? 1 : 0 ;
            if (cur == pre) return false;
            n >>= 1;
            pre = cur;
        }
        return true;
    }
};