class Solution {
public:
    int numberOfWays(string corridor) {
        long res = 1, pcount = 0, pend = -1, N = corridor.size(), MOD = 1e9 + 7;

        for (int i=0; i<N; i++) {
            if (corridor[i] == 'S') {
                pcount++;
                if (pcount % 2 == 0) {
                    pend = i;
                } else {
                    if (pend != -1) {
                        res *= (i - pend);
                        res %= MOD;
                    }
                }
            }

        }

        return pcount % 2 == 0 && pcount > 0 ? res: 0;

    }
};