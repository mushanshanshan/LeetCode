class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> char_count(26, 0);
        vector<int> res;
        int diff = p.size(), N = s.size(), M = diff;

        for (char c: p) char_count[c - 'a']++;

        for (int i=0; i<N; i++) {
            if (i >= M) diff += char_count[s[i-M] - 'a']++ < 0? -1: 1;
            diff += char_count[s[i] - 'a']-- > 0? -1: 1;
            if (diff == 0) res.push_back(i-M+1);
        }

        return res;
    }
};