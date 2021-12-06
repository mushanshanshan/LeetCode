class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    
    bool checkCol(int row, int col, int n) {
        for (int i=0; i<row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        for (int r=row+1, c=col+1; r<n && c<n; r++, c++) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        for (int r=row-1, c=col-1; r>=0 && c>=0; r--, c--) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        for (int r=row-1, c=col+1; r>=0 && c<n; r--, c++) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        for (int r=row+1, c=col-1; r<n && c>=0; r++, c--) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        
        return true;
        
        
    }
    
    
    void backtracking(int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col=0; col<n; col++) {
            if (checkCol(row, col, n)) {
                board[row][col] = 'Q';
                backtracking(row+1, n);
                board[row][col] = '.';
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        for (int i=0; i<n; i++) {board.push_back(temp);}
        
        backtracking(0, n);
        return result;
        
    }
};