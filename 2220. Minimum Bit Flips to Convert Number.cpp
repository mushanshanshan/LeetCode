class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0; 
        int xorres = start ^ goal;

        while (xorres) {
            res += xorres & 1;
            xorres >>= 1;
        }

        return res;
    }
};