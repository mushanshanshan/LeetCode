class Solution {
public:
    
    
    int corr(vector<vector<int>>& grid, int target) {
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == target) {
                    if (i>0) {
                        if (grid[i-1][j] == 1) return target;
                        else if (grid[i-1][j] == 0) grid[i-1][j] = target+1;
                    }
                    if (j>0) {
                        if (grid[i][j-1] == 1) return target;
                        else if (grid[i][j-1] == 0) grid[i][j-1] = target+1;
                    }
                    if (i<grid.size()-1) {
                        if (grid[i+1][j] == 1) return target;
                        else if (grid[i+1][j] == 0) grid[i+1][j] = target+1;
                    }
                    if (j<grid[0].size()-1) {
                        if (grid[i][j+1] == 1) return target;
                        else if (grid[i][j+1] == 0) grid[i][j+1] = target+1;
                    }
                    
                }
            }
        }
        return -1;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) {
            return;
        }
        
        grid[i][j] = 2;
        
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
    }
    
    void searchLand(vector<vector<int>>& grid) {
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i ,j);
                    return;
                }
            }
        }
    }
    
    void print(vector<vector<int>>& grid) {
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                cout<<grid[i][j]<<',';
            }
            cout<<endl;
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        searchLand(grid);
        int res=-1;
        for (int i=2;;i++) {
            res = corr(grid, i);
            if (res > 0) return res-2;
        }
        return 0;
    }
};