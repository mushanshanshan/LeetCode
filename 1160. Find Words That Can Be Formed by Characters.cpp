class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_count(26, 0);
        vector<int> word_count(26, 0);
        int res = 0;

        for (auto c: chars) char_count[c - 'a']++;

        for (auto word: words) {
            fill(word_count.begin(), word_count.end(), 0);
            for (auto c: word) {
                word_count[c - 'a']++;
            }
            int i = 0;
            for (; i<26; i++) {
                if (word_count[i] > char_count[i]) break;
            }
            if (i == 26) res += word.size();
        }

        return res;
        
    }
};