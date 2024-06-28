class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long res = 0;
        int N = h.size() - 1;
        sort(h.begin(), h.end());

        for (int i=0; i<k; i++) {
            res += max(0, h[N-i] - i);
        }

        return res;
    }
};