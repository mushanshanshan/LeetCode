class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> dict(59, 0);
        int res = 0;
        bool flag = true;
        
        for (char& c: s) {
            dict[c - 'A']++;
        }
        
        for (int& i: dict) {
            if (i>0) {
                if (i%2==0) {
                    res += i;
                } else {
                    res += i/2*2;
                    if (flag) {
                        res += 1;
                        flag = false;
                    }
                }
            }
        }
        
        return res;
        
    }
};