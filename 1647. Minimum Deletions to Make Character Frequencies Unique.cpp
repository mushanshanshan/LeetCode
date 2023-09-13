class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        int res = 0;
        unordered_set<int> freqs;

        for (auto a: s) {
            freq[a - 'a']++;
        }

        for (auto f: freq) {

            while (f != 0 && freqs.find(f) != freqs.end()) {
                res++;
                f--;
            }
            freqs.insert(f);
        }

        return res;

    }
};