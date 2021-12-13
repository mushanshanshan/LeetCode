class Solution {
public:
    bool res = false;
    
    void backtracking(vector<vector<char>>& board, vector<vector<bool>>& used, string& word, int start, int i, int j) {
        if (i<0 || j<0 || i>=used.size() || j>=used[0].size() || used[i][j] || board[i][j] != word[start] || res) {
            return;
        }
        
        if (board[i][j] == word[start] && start == word.size()-1) res=true;
        
        used[i][j] = true;
        backtracking(board, used, word, start+1, i-1, j);
        backtracking(board, used, word, start+1, i+1, j);
        backtracking(board, used, word, start+1, i, j-1);
        backtracking(board, used, word, start+1, i, j+1);
        used[i][j] = false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    backtracking(board, used, word, 0, i, j);
                    if (res) return res;
                }
            }
        }
        return false;
    }
};