class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0, N = s.size();

        for (int i=0; i<26; i++) {
            int l = 0, r = N - 1;
            while (l <= r && s[l] != ('a' + i)) l++;
            while (r >= l && s[r] != ('a' + i)) r--;

            if (l == r) continue;

            unordered_set<char> counter;
            for (int j=l+1; j<r; j++) {
                counter.insert(s[j]);
            }

            res += counter.size();
        }

        return res;
    }
};