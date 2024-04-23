class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int N = land.size(), M = land[0].size();

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (land[i][j] == 1) {
                    int rb = i, lb = j;
                    while (rb < N-1 && land[rb+1][j] == 1) rb++;
                    while (lb < M-1 && land[i][lb+1] == 1) lb++;

                    for (int k=i; k<=rb; k++) {
                        for (int l=j; l<=lb; l++) {
                            land[k][l] = 0;
                        }
                    }
                    res.push_back({i, j, rb, lb});
                }
            }
        }
        return res;
    }
};