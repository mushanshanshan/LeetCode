class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size(),temp = 0, res = 0;
        vector<int> count(C, 0);

        for (int r=0; r<R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == 1) count[c]++;
                else count[c] = 0;
            }

            vector<int> tv(count);
            sort(tv.begin(), tv.end());

            for (int c = C-1; c>=0; c--) {
                if (tv[c] == 0) break;
                res = max(res, tv[c] * (C-c));
            }
        }

        return res;
    }
};