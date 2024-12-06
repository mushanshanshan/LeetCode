class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> counter;
        int res = 0;

        for (int i: banned) {
            if (i <= n) counter.insert(i);
        }

        for (int i=1; i<=n; i++) {
            if (!counter.contains(i) && maxSum >= i) {
                res++;
                maxSum -= i;
                // printf("%d-%d\n", i, maxSum);
            }
            if (maxSum <= i) break;
        }

        return res;
    }
};