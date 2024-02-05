class Solution {
public:
    int firstUniqChar(string s) {
        int N = s.size();
        vector<int> counter(26, N);
        int res = N;

        for (int i=0; i<N; i++) {
            if (counter[s[i] - 'a'] == N) {
                counter[s[i] - 'a'] = i;
            } else if (counter[s[i] - 'a'] < N) {
                counter[s[i] - 'a'] = N+1;
            }
        }

        for (int i=0; i<26; i++) {
            res = min(counter[i], res);
        }

        return res >= N? -1: res;
    }
};