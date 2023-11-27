class Solution {
public:
    int knightDialer(int n) {
        vector<vector<long>> counter(2, vector<long>(10, 1));
        const int MOD = 1e9 + 7;
        long res = 0;

        vector<vector<int>> moves = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0},
            {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
        };

        for (int i = 1; i < n; i++) {
            int curr = i % 2;
            int prev = (i - 1) % 2;
            
            for (int j = 0; j < 10; j++) {
                counter[curr][j] = 0;
                for (int m : moves[j]) {
                    counter[curr][j] = (counter[curr][j] + counter[prev][m]) % MOD;
                }
            }
        }

        for (long count : counter[(n - 1) % 2]) {
            res = (res + count) % MOD;
        }

        return res;
    }
};
