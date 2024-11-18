class Solution {
public:
    string makeFancyString(string s) {
        string res;
        res += s[0];

        int count = 1, N = s.size();
        for (int i=1; i<N; i++) {
            if (s[i] == s[i-1]) {
                if (++count <= 2) res += s[i];
            } else {
                res += s[i];
                count = 1;
            }
        }

        return res;
    }
};