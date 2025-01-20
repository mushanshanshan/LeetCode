class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int res = 0, b1 = 0;

        while (num2 > 0) {
            num2 &= (num2 - 1);
            b1++;
        }

        for (int i=31; i>=0; i--) {
            if (num1 & (1 << i)) {
                res |= (1 << i);
                b1--;
            }
            if (!b1) break;
        }

        for (int i=0; i<32; i++) {
            if (!b1) break;
            if (!(num1 & (1 << i))) {
                res |= (1 << i);
                b1--;
            }
        }

        return res;
    }
};