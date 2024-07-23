class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        vector<int> res;
        vector<int> row_min(N, 0);

        for (int i=0; i<N; i++) {
            int temp = matrix[i][0];
            for (int j=1; j<M; j++) {
                if (matrix[i][j] < temp) {
                    temp = matrix[i][j];
                    row_min[i] = j;
                }
            }
        }

        for (int j=0; j<M; j++) {
            int temp = matrix[0][j];
            int col_max = 0;
            for (int i=1; i<N; i++) {
                if (matrix[i][j] > temp) {
                    temp = matrix[i][j];
                    col_max = i;
                }
            }
            if (row_min[col_max] == j) res.push_back(matrix[col_max][j]);
        }

        return res;
    }
};