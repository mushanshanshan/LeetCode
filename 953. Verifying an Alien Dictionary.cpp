class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char map[26];
        for (int i=0; i<26; i++) {
            map[order[i] - 'a'] = 'a' + i; 
        }

        for (auto &w: words) {
            for (auto & c:w) {
                c = map[c - 'a'];
            }
        }

        return is_sorted(words.begin(), words.end());
    }
};