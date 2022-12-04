class Solution {
public:
    
    bool checkBoard(vector<vector<char>>& board, int row, int col, char s) {
        for (int r=0; r<9; r++) {
            if (board[r][col] == s) return false;
        }
        
        for (int c=0; c<9; c++) {
            if (board[row][c] == s) return false;
        }
        
        int lu_row = (row/3)*3, lu_col = (col/3)*3;
        
        for (int r=lu_row; r<lu_row+3; r++) {
            for (int c = lu_col; c<lu_col+3; c++) {
                if (board[r][c] == s) return false;
            }
        }
        return true;
        
    }
    
    bool backtracking(vector<vector<char>>& board) {
        
        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                if (board[r][c] != '.') {continue;}
                
                for (char s='1'; s<='9'; s++) {
 
                    if (checkBoard(board, r, c, s)) {
                        board[r][c] = s;
                        if (backtracking(board)) {return true;}
                        board[r][c] = '.';
                    }
                }
                return false;
            } 
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};