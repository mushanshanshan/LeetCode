class Solution {
public:
    void dfs(vector<vector<bool>>& map, vector<vector<int>>& heights, int l, int c) {
        map[l][c] = true;
        if (l != 0) {
            if (heights[l-1][c] >= heights[l][c] && !map[l-1][c]) {
                dfs(map, heights, l-1, c);
            }
        }
        
        if (c != 0) {
            if (heights[l][c-1] >= heights[l][c] && !map[l][c-1]) {
                dfs(map, heights, l, c-1);
            }
        }
        if (l != heights.size()-1) {
            if (heights[l+1][c] >= heights[l][c] && !map[l+1][c]) {
                dfs(map, heights, l+1, c);
            }
        }
        
        if (c != heights[0].size()-1) {
            if (heights[l][c+1] >= heights[l][c] && !map[l][c+1]) {
                dfs(map, heights, l, c+1);
            }
        }
        return;
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> p(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> a(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i=0; i<heights.size(); i++) {
            p[i][0] = true;
            a[i][heights[0].size()-1] = true;
        }
        
        for (int i=0; i<heights[0].size(); i++) {
            p[0][i] = true;
            a[heights.size()-1][i] = true;
        }
        
            
        for (int i=0; i<heights.size(); i++) {
            dfs(p, heights, i, 0);
            dfs(a, heights, i, heights[0].size()-1);
        }
        
        for (int i=0; i<heights[0].size(); i++) {
            dfs(p, heights, 0, i);
            dfs(a, heights, heights.size()-1, i);
        }
        
        vector<vector<int>> res;
        for (int i=0; i<heights.size(); i++) {
            for (int j=0; j<heights[0].size(); j++) {
                if (p[i][j] && a[i][j]) res.push_back(vector<int>{i, j});;
            }
        }
        
        return res;
        
    }
};