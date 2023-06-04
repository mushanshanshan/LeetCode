class Solution {
private:
    void process(queue<pair<int, int>>& q, vector<vector<int>>& grid, int x, int y, int n) {
        if (x < 0 || y < 0 || x == n || y == n) return;
        if (grid[x][y] == 1) return;
        q.push({x, y});
        grid[x][y] = 1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        if (grid[0][0] == 0) q.push({0,0});
        int dis = 0, n = grid.size();

        while (!q.empty()) {
            int l = q.size();
            dis++;
            for (int i=0; i<l; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n-1 && y == n-1) return dis;

                process(q, grid, x-1, y, n);
                process(q, grid, x, y-1, n);
                process(q, grid, x-1, y-1, n);
                process(q, grid, x+1, y, n);
                process(q, grid, x, y+1, n);
                process(q, grid, x+1, y+1, n);
                process(q, grid, x+1, y-1, n);
                process(q, grid, x-1, y+1, n);
                
            }
        }

        return -1;
    }
};