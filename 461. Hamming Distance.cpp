class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y, count = 0;
        
        while (diff) {
            if (diff & 1) count++;
            diff >>= 1;
        }
        return count;
    }
};