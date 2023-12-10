class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        vector<vector<int>> res(M, vector<int>(N, 0));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};