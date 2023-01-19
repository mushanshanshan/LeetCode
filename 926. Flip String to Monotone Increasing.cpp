class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int right_zero = 0, right_one = 0, left_zero = 0, left_one = 0;
        

        for (auto c: s) {
            if (c == '0') right_zero++;
            else right_one++;
        }

        int res = left_one + right_zero;

        for (auto c: s) {
            if (c == '0') {
                right_zero--;
                left_zero++;
                res = min(res, left_one + right_zero);
            }
            else {
                right_one--;
                left_one++;
                res = min(res, left_one + right_zero);
            }
        }

        return res;

    }
};