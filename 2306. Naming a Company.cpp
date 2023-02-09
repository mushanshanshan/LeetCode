class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int counter[26][26] = {0};
        unordered_set<string> set;
        long long res = 0;

        for (string &s: ideas) set.insert(s);

        for (string s: ideas) {
            int pre = s[0] - 'a';
            for (int i=0; i<26; i++) {
                s[0] = 'a' + i;
                if (set.count(s) == 0) counter[pre][i]++;
            }
        }

        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                res += (long long) counter[i][j] * counter[j][i];
            }
        }

        return res;

    }
};