class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& checked) {
        //f 1-up,2-down,3-left,4-right
        
        
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if (checked[i][j] || board[i][j] == 'X') return;
        
        checked[i][j] = true;
        
        if (board[i][j] == 'O') board[i][j] = 'T';
        
        dfs(board, i-1, j, checked);
        dfs(board, i+1, j, checked);
        dfs(board, i, j-1, checked);
        dfs(board, i, j+1, checked);
        
        return;
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> checked(board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i<board.size(); i++) {
            dfs(board, i, 0, checked);
            dfs(board, i, board[0].size()-1, checked);
        }
        
        for (int i=0; i<board[0].size(); i++) {
            dfs(board, 0, i, checked);
            dfs(board, board.size()-1, i, checked);
        }
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};