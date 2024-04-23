class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, N = grid.size(), M = grid[0].size();

        for (int i=0; i<N; i++){
            int pre = 0;
            for (int j=0; j<M; j++) {
                if (pre != grid[i][j]) {
                    res++;
                } 
                pre = grid[i][j];
            }
            res += grid[i][M-1];
        }

        for (int j=0; j<M; j++){
            int pre = 0;
            for (int i=0; i<N; i++) {
                if (pre != grid[i][j]) {
                    res++;
                } 
                pre = grid[i][j];
            }
            res += grid[N-1][j];
        }


        return res;
    }
};