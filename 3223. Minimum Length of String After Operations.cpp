class Solution {
public:
    int minimumLength(string s) {
        vector<int> counter(26, 0);
        int res = 0, N = s.size();

        for (int i=0; i<N; i++) counter[s[i]-'a']++;
        for (auto i: counter) {
            if (i == 0) continue;
            if (i % 2 == 1) res += 1;
            else res += 2;
        }

        return res;
    }
};