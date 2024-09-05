class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        vector<int> counter(26, 0);

        for (char c: word) counter[c - 'a']++;
        sort(counter.rbegin(), counter.rend());

        for (int i=0; i<26; i++) {
            // printf("%d*%d-", counter[i], int(i / 8 + 1));
            res += counter[i] * int(i / 8 + 1);
        }

        // for (int i:counter) printf("%d-", i);

        return res;
    }
};