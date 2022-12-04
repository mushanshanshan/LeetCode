class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() < numRows) return s;
        
        string res = "";
        int cur;
        int n = s.size();
        
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<n; j+=(numRows-1)*2) {
                res += s[j];
                if (i!=0 && i!=numRows-1) {
                    int k = j + 2 * (numRows - i - 1);
                    if (k < n) res += s[k];
                }
            }
            
        }
        
        return res;
        
    }
};