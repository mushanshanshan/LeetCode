class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size(), max_l = 0;
        vector<vector<int>> col_counter(N, vector<int>(M, 0));
        vector<vector<int>> row_counter(N, vector<int>(M, 0));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 1) {
                    col_counter[i][j] = i > 0? col_counter[i-1][j] + 1: 1;
                    row_counter[i][j] = j > 0? row_counter[i][j-1] + 1: 1;
                }
            }
        }


        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (col_counter[i][j] > max_l) {
                    int cur = min(col_counter[i][j], row_counter[i][j]);
                    while (cur > max_l) {
                        if (cur <= col_counter[i][j+1-cur] && cur <= row_counter[i+1-cur][j]) max_l = cur;
                        cur--;
                    }
                }
            }
        }

        // for (int i=0; i<N; i++) {
        //     for (int j=0; j<M; j++) {
        //         printf("%d ", col_counter[i][j]);
        //     }
        //     printf("\n");
        // }

        // printf("\n");

        // for (int i=0; i<N; i++) {
        //     for (int j=0; j<M; j++) {
        //         printf("%d ", row_counter[i][j]);
        //     }
        //     printf("\n");
        // }

        return max_l * max_l;

    }
};