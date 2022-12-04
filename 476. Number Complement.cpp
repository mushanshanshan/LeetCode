class Solution {
public:
    int findComplement(int num) {
        int temp = num, count = 0;
        while (temp) {
            count++;
            temp >>= 1;
        }

        for (int i=0; i<count-1; i++) {
            temp += 1;
            temp <<= 1;
        }
        temp += 1;

        return num ^ temp;
    }
};