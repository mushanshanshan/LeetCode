class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> row_map, col_map;
        unordered_map<int, vector<int>> int_map;
        int N = mat.size(), M = mat[0].size(), K = arr.size();

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                int_map[mat[i][j]] = {i, j};
            }
        }

        for (int i=0; i<K; i++) {
            auto& idx = int_map[arr[i]];
            row_map[idx[0]]++;
            col_map[idx[1]]++;

            if (row_map[idx[0]] == M || col_map[idx[1]] == N) return i;
        }

        return -1;
    }
};