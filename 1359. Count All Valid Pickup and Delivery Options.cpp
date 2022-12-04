class Solution {
public:
    int countOrders(int n) {
        long mod = 1e9 + 7;
        long res = 1;
        int temp = 1, j=1;
        for (int i=2; i<=n; i++) {
            temp += ++j;
            temp += ++j;
            res = res * temp % mod;
        }
        return (int)res;
    }
};