class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    int s_length;
    
public:
    bool isPalindrome(string& s, int l, int r){
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    void backtracking(string& s, int start) {
        if (start == s_length) {
            res.push_back(temp);
            return;
        }
        
        for (int i=start; i<s_length; i++) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                backtracking(s, i + 1);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        s_length = s.size();
        backtracking(s, 0);
        return res;
    }
};