class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, suml = 0, sumr = 0;

        while (l <= r) {
            if (suml < sumr) suml += l++;
            else if (suml > sumr) sumr += r--;
            else if (l == r) return l;
            else suml += l++;

        }

        return -1;
    }
};