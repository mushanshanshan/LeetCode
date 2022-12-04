class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        
        int n = word1.size();
        vector<int> wc1(26,0);
        vector<int> wc2(26,0);
        vector<bool> we1(26,false);
        vector<bool> we2(26,false);
        
        for (int i=0; i<n; i++) {
            wc1[word1[i] - 'a']++;
            wc2[word2[i] - 'a']++;

            we1[word1[i] - 'a'] = true;
            we2[word2[i] - 'a'] = true;
        }

        sort(wc1.begin(), wc1.end());
        sort(wc2.begin(), wc2.end());

        if (we1 == we2 && wc1 == wc2) {
            return true;
        } else {
            return false;
        }
    }
};