class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> farest(n+1, 0);
        int res = 0, N = ranges.size(), cur = 0, next = 0;
        for (int i=0; i<N; i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            farest[l] = max(farest[l], r-l);
        }



        for (int i=0; i<N-1; i++) {
            if (i > next) return -1;

            next = max(next, i+farest[i]);

            if (i == cur) {
                cur = next;
                res++;
            }
        }


        return next >= n? res: -1;
    }
};