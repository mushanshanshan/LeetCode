class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid[0].size();
        int M = grid.size();

        vector<int> pre(N, 0);
        vector<int> cur(N, 0);
        cur[0] = grid[0][0];

        for (int i = 1; i < N; i++) {
            cur[i] = grid[0][i] + cur[i-1];
        }

        for (int j = 1; j < M; j++) {
            swap(pre, cur);
            for (int i = 0; i < N; i++) {
                cur[i] = min(i > 0? cur[i-1]: INT_MAX, pre[i]) + grid[j][i];
            }
        }

        return cur[N-1];
    }
};