class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        vector<int> count(26, 0);

        for (char c: s) count[c - 'a']++;
        for (char c: t) count[c - 'a']--;
        for (int i: count) res += abs(i);

        return res / 2;
    }
};