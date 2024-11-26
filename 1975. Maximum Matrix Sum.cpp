class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg_count = 0, min_value = INT_MAX;
        int N = matrix.size();

        long long sum_value = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (matrix[i][j] < 0) {
                    matrix[i][j] = -matrix[i][j];
                    neg_count++;
                }
                sum_value += matrix[i][j];
                min_value = min(min_value, matrix[i][j]);
            }
        }

        if (neg_count % 2 == 0) return sum_value;
        else return sum_value - 2 * min_value;
    }
};