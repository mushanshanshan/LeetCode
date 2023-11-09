class Solution {
public:
    int countHomogenous(string s) {
        long res = 1, cur = 1;
        int N = s.size(), MOD = 1e9 + 7;

        for (int i=1; i<N; i++) {
            if (s[i] == s[i-1]) {
                res += (++cur);
            } else {
                cur = 1;
                res++;
            }
            res %= MOD;
        }

        return res %= MOD;
    }
};