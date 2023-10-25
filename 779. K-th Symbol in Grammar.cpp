class Solution {
public:
    int kthGrammar(int n, int k) {
        n--;
        k--;

        int reverse = 0;
        int res = 0;

        if (n == 0) return 0;
        while (n > 1) {
            if (k >= pow(2, n-1)) {
                reverse++;
                k -= pow(2, n-1);
            }
            n--;


        }

        if (k == 1) res = 1;
        if (reverse % 2 != 0) res = (res + 1) % 2;

        return res;
    }
};