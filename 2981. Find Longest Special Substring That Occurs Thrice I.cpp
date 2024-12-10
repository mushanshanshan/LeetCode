class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> counter(26, vector<int>(51, 0));
        int cur = 1, res = -1;
        int N = s.size();

        counter[s[0] - 'a'][1]++;

        for (int i=1; i<N; i++) {
            if (s[i] == s[i-1]) {
                cur++;
                for (int j=0; j<=cur; j++) {
                    counter[s[i] - 'a'][j]++;
                }
            } else {
                cur = 1;
                counter[s[i] - 'a'][1]++;
            }
        }

        for (int i=0; i<26; i++) {
            for (int j=49; j>=0; j--) {
                if (counter[i][j] >= 3) {
                    res = max(res, j);
                    break;
                }
            }
        }

        return res;
    }
};