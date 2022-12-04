class Solution {
public:
    vector<string> res;
    vector<char> temp;
    
    void backtracking(int left, int leftR, int n) {
        if (temp.size() == n) {
            string s;
            for (char& c: temp) {
                s += c;
            }
            res.push_back(s);
            return;
        }
        
        if (leftR) {
            temp.push_back('(');
            leftR--;
            left++;
            backtracking(left, leftR, n);
            leftR++;
            left--;
            temp.pop_back();
        }
        
        if (left) {
            temp.push_back(')');
            left--;
            backtracking(left, leftR, n);
            left++;
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        backtracking(0, n, 2*n);
        return res;
    }
};