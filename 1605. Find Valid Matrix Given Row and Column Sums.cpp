class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int N = rowSum.size(), M = colSum.size();
        vector<vector<int>> res(N, vector<int>(M, 0));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }

        return res;
    }
};