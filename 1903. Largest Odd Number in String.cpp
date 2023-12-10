class Solution {
public:
    string largestOddNumber(string num) {
        int e = num.size() - 1;

        while (e >= 0 && (num[e] - '0') % 2 == 0) {
            e--;
        }

        return e == -1? "": num.substr(0, e+1);
    }
};