class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int N = str1.size(), M = str2.size();

        for (int i=0, j=0; i<N; i++) {
            if (str2[j] - str1[i] == 0 || str2[j] - str1[i] == 1 || (str2[j] == 'a' && str1[i] == 'z')) {
                j++;
            }
            if (j == M) return true;
        }

        return false;
    }
};