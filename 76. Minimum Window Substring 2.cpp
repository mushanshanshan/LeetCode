class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> counter;
        int N = s.size(), l = 0, min_left = -1, min_len = N, diff = 0;

        for (char c: t) {
            counter[c]++;
            if (counter[c] == 1) diff++;
        }

        for (int i=0; i<N; i++) {
            if (counter.find(s[i]) != counter.end()) {
                counter[s[i]]--;
                if (counter[s[i]] == 0) diff--;
            }
            while (diff==0) {
                if (i - l < min_len){
                    min_left = l;
                    min_len = i - l + 1;
                }
                if (counter.find(s[l]) != counter.end()) {
                    counter[s[l]]++;
                    if (counter[s[l]] == 1) diff++;
                }
                l++;
            }
        }

        return min_left == -1? "": s.substr(min_left, min_len);
    }
};