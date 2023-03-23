class Solution {
private:
    long long _count(long c) {
        return (1 + c) * c / 2;
    }

public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        long long res = 0;

        for (int i: nums) {
            if (i == 0) c++;
            else {
                if (c > 0) res += _count(c);
                c = 0;
            }
        }
        if (c > 0) res += _count(c);

        return res;
    }
};