class Solution {
public:
    string sortVowels(string s) {
        int N = s.size(), cur = 0;
        vector<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> counter;
        vector<int> replace_char;

        for (char c: vowels) {
            counter[c] = 0;
        }

        for (int i=0; i<N; i++) {
            if (counter.find(s[i]) != counter.end()) {
                counter[s[i]]++;
                replace_char.push_back(i);
            }
        }

        for (char c: vowels) {
            while (counter[c]-- > 0) {
                s[replace_char[cur++]] = c;
            }
        }

        return s;
    }
};