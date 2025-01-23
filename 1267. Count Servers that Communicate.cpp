class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_set<int> row, col;
        int res = 0, N = grid.size(), M = grid[0].size();
        int counter = 0;

        for (int i=0; i<N; i++) {
            counter = 0;
            for (int j=0; j<M; j++) {
                counter += grid[i][j];
            }
            if (counter == 1) row.insert(i);
        }

        for (int j=0; j<M; j++) {
            counter = 0;
            for (int i=0; i<N; i++) {
                counter += grid[i][j];
            }
            if (counter == 1) col.insert(j);
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 1 && !(row.contains(i) && col.contains(j))) res++;
            }
        }

        return res;
    }
};