class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size(), res = 0;
        vector<int> nc(N, 0);
        nc[0] = 1;

        for (int i=1; i<N; i++) {
            nc[i] = ratings[i] > ratings[i-1]? nc[i-1] + 1 : 1;
        }

        res = nc[N-1];
        for (int i=N-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) nc[i] = max(nc[i+1] + 1, nc[i]);
            res += nc[i];
        }

        return res;
    }
};