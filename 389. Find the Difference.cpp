class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        int N = s.size();
        count[t[N] - 'a']++;
        for (int i=0; i<N; i++) {
            count[t[i] - 'a']++;
            count[s[i] - 'a']--;
        }

        for (int i=0; i<26; i++) {
            if (count[i] != 0) return 'a' + i; 
        }

        return 'a';
    }
};