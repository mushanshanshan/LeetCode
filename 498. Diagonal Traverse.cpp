class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), i = 0 , j = 0;
        vector<int> res(n*m);
        bool up=true;
        
        for (int k=0; k<m * n; k++) {
            res[k] = mat[i][j];
            
            if (up) {
                i--;
                j++;
            } else {
                i++;
                j--;
            }
            
            if (j == m) {
                i += 2;
                j = m-1;
                up = !up;
            } else if (i == n){
                j += 2;
                i = n-1;
                up = !up;
            } else if (i<0) {
                i = 0;
                up = !up;
            } else if (j<0) {
                j = 0;
                up = !up;
            } 
        }
        
        return res;
    }
};