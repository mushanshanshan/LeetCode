class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int N = grid[0].size();
        long long cur_min = LLONG_MAX;
        vector<long long> r1(N, 0);
        vector<long long> r2(N, 0);

        for (int i=N-2; i>=0; i--) {
            r1[i] = r1[i+1] + grid[0][i+1];
        }

        for (int i=1; i<N; i++) {
            r2[i] = r2[i-1] + grid[1][i-1];
        }

        // for (auto i: r1) printf("%d-", i);
        // printf("\n");
        // for (auto i: r2) printf("%d-", i);

        for (int i=0; i<N; i++) {
            cur_min = min(cur_min, max(r1[i], r2[i]));
        }


        return cur_min;
    }
};