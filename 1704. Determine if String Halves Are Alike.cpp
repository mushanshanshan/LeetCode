class Solution {
private:
    bool vowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.size(), res = 0;
        for (int i=0; i<n; i++) {
            if (vowel(s[i])) {
                if (i < n/2) res++;
                else res--;
            }
        }

        return res == 0;
    }
};