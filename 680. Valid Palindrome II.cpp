class Solution {
public:
    
    bool check(string& s, int l, int r, int c){
        if (c>1) return false;
        if (l >= r) return true;
        
        if (s[l] == s[r]) {
            
            return check(s, l+1, r-1, c);
        } else {
            if (s[l+1] == s[r] && s[l] == s[r-1]) {
                c++;
                return check(s, l+1, r, c) || check(s, l, r-1, c);
            } else if (s[l+1] == s[r]) {
                c++;
                return check(s, l+1, r, c);
            } else if (s[l] == s[r-1]) {
                c++;
                return check(s, l, r-1, c);
            } else {
                return false;
            }
        }
    }
    
    
    bool validPalindrome(string s) {
        return check(s, 0, s.size()-1, 0);
    }
};