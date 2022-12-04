class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        
        int temp = n%3;
        if (temp == 1) {
            return pow(3,n/3-1)*4;
        } else if (temp == 0) {
            return pow(3, n/3);
        } else {
            return pow(3,n/3)*2;
        }
    }
};