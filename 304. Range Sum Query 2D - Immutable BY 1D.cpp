class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        for (int i=0; i<matrix.size(); i++) {
            int t = 0;
            s.push_back({0});
            for (int& j: matrix[i]) {
                t += j;
                s[i].push_back(t);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        for (int i=row1; i<=row2; i++) {
            res += s[i][col2+1] - s[i][col1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */