class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int l = 0;

        for (char c: s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else res++;
            }
        }

        res += l;
        return res;
    }
};