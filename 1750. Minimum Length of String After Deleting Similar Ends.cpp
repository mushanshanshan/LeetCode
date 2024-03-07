class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;

        while (s[l] == s[r] && l < r) {
            char c = s[l];
            while (s[l] == c && l <= r) l++;
            while (s[r] == c && r >= l) r--;
        }

        return r < l? 0: r - l + 1;
    }
};