class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if( r * c != mat.size() * mat[0].size()) return mat;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        int i=0, j=0, k=0, l=0;
        
        while (i != mat.size() - 1 || j != mat[0].size()) {
            if (j == mat[0].size()) {
                i++;
                j=0;
            }
            if (l == c) {
                k++;
                l=0;
            }
            res[k][l] = mat[i][j];
            j++;
            l++;
        }
        
        return res;
    
    
    }
};