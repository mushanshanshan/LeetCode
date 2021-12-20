class Solution {
public:
    int res = 0;
    
    bool isValid(vector<vector<bool>>& board, int row, int col, int n) {
        for (int i=0; i<row; i++) {
            if (board[i][col]) return false;
        }
        
        for (int i=row-1, j=col-1; i>-1 && j>-1; i--, j--) {
            if (board[i][j]) return false;
        }
        
        for (int i=row-1, j=col+1; i>-1 && j<n; i--, j++) {
            if (board[i][j]) return false;
        }
        
        for (int i=row+1, j=col-1; i<n && j>-1; i++, j--) {
            if (board[i][j]) return false;
        }
        
        for (int i=row+1, j=col+1; i<n && j<n; i++, j++) {
            if (board[i][j]) return false;
        }
        
        return true;
        
    }
    
    void backtracking(vector<vector<bool>>& board, int row, int n) {
        if (row == n) {
            res++;
            return;
        }
        
        for (int i=0; i<n; i++) {
            if (isValid(board, row, i, n)) {
                board[row][i] = true;
                backtracking(board, row+1, n);
                board[row][i] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        backtracking(board, 0, n);
        return res;
    }
};