class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> counter(100001, 0);
        int nmin = 100000, nmax = 0;
        int res = 0, cur = 0;

        for (int n: nums) {
            counter[n]++;
            nmin = min(n, nmin);
            nmax = max(n, nmax);
        }

        int l = nmin, r = nmin;
        while (r <= nmax) {
            if (r-l <= 2 * k) {
                cur += counter[r++];
            } else {
                cur -= counter[l++];
                cur += counter[r++];
            }
            res = max(res, cur);
        }

        return res;
    }
};