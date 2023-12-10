class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        
        res += 21 * (n / 7);
        if (n > 7) res += (1 + n / 7) * (n / 7) / 2 * 7;
        res += (1 + n % 7) * (n % 7) / 2 + (n % 7) * (n / 7);

        return res;
    }
};