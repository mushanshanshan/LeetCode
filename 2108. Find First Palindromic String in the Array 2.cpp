class Solution {
private:
    bool isPalindrome(string &s) {
        int N = s.size();
        for (int i=0; i<N/2; i++) {
            if (s[i] != s[N-1-i]) return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for (int i=0; i<words.size(); i++) {
            if (isPalindrome(words[i])) return words[i];
        }
        return "";
    }
};