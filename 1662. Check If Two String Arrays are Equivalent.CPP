class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int s1 = 0, s2 = 0, c1 = 0, c2 = 0;

        while (s1 < word1.size() && s2 < word2.size()) {
            if (word1[s1][c1] != word2[s2][c2]) return false;

            if (c1 == word1[s1].size() - 1) {s1++; c1 = 0;}
            else c1++;

            if (c2 == word2[s2].size() - 1) {s2++; c2 = 0;}
            else c2++;
        }
        

        return s1 == word1.size() && s2 == word2.size();
    }
};