class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;

        for (int p: piles) {
            r = max(r, p);
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            int cur_h = 0;
            //printf("%d-%d-%d:", l, m, r);
            for (int p: piles) {
                cur_h += (int) ceil((double)p / m);
                //printf("%d,", cur_h);
            }
            //printf("\n");
            if (cur_h > h) l = m + 1;
            else r = m;
        }

        return l;
    }
};