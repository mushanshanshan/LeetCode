class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ind = 0;
        int top = 0, down = m - 1, left = 0, right = n - 1;
        vector<int> res(m*n);
        char dir = 'r';
        
        while (left <= right && top <= down) {
            if (dir == 'r') {
                for (int i=left; i<=right; i++, ind++) res[ind] = matrix[top][i];
                dir = 'd';
                top++;
            } else if (dir == 'd') {
                for (int i=top; i<=down; i++, ind++) res[ind] = matrix[i][right];
                dir = 'l';
                right--;
            } else if (dir == 'l') {
                for (int i=right; i>=left; i--, ind++) res[ind] = matrix[down][i];
                dir = 'u';
                down--;
            } else {
                for (int i=down; i>=top; i--, ind++) res[ind] = matrix[i][left];
                dir = 'r';
                left++;
            }
        }
        return res;
        
    }
};