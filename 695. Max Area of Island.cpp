class Solution {
public:
    int dfs(vector<vector<int>>& grid, int l, int c) {
        if (grid[l][c] == 0) {
            return 0;
        } else {
            grid[l][c] = 0;
            int s = 1;
            if (l != 0) s += dfs(grid, l-1, c);
            if (c != 0) s += dfs(grid, l, c-1);
            if (l != grid.size()-1) s += dfs(grid, l+1, c);
            if (c != grid[0].size()-1) s += dfs(grid, l, c+1);
            return s;
        }
        return 0;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i ,j));
                }
            }
        }
        return area;
    }
};