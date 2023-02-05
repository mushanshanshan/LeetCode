class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> data(numRows);
        string res;

        int row = 0, diff = 1;
        for (char c: s) {
            data[row] += c;
            if (row == 0) diff = 1;
            if (row == numRows-1) diff = -1;
            row += diff;
        }

        for (string s: data){
            res += s;
        }

        return res;
    }
};