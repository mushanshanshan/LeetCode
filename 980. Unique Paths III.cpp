/*
 * @Date: 2022-12-31 14:15:09
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-31 14:16:37
 * @FilePath: /LeetCode/980. Unique Paths III.cpp
 */
class Solution {
private:

    int needVisit = 1;
    int res = 0;
    int N, M;

    void backTrace(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x > N || y < 0 || y > M || grid[x][y] < 0) return;

        if (grid[x][y] == 2) {

            if (needVisit == 0) res++;
            return;
        }

        needVisit--;
        grid[x][y] = -2;
        backTrace(x-1, y, grid);
        backTrace(x+1, y, grid);
        backTrace(x, y-1, grid);
        backTrace(x, y+1, grid);
        needVisit++;
        grid[x][y] = 0;
        return;

    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        N = grid.size()-1;
        M = grid[0].size()-1;

        int _x, _y;

        for (int i=0; i<=N; i++) {
            for (int j=0; j<=M; j++) {
                if (grid[i][j] == 0) needVisit++;
                else if (grid[i][j] == 1) {_x = i; _y = j;}
            }
        }

        backTrace(_x, _y, grid);
        return res;
    }
}; -