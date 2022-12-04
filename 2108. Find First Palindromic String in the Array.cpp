class Solution {
public:
    bool pa(string s) {
        int l = 0, r = s.size()-1;
        while (l<r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (string & s: words) if (pa(s)) return s;
        return "";
    }
};