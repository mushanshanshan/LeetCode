class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int s0 = 10000, s1 = 10000, m0 = 0, m1 = 0;

        for (int i: nums) {
            if (i < s1) {
                if (i < s0) {s1 = s0; s0 = i;}
                else {s1 = i;}
            }
            if (i > m1) {
                if (i > m0) {m1 = m0; m0 = i;}
                else {m1 = i;}
            }
        }

        return m1 * m0 - s1 * s0;
    }
};