class Solution {
public:
    int partitionString(string s) {
        vector<bool> count(26, false);
        int res = 0;

        for (auto c: s) {
            if (!count[c - 'a']) count[c - 'a'] = true;
            else {
                res++;
                fill(count.begin(), count.end(), false);
                count[c - 'a'] = true;
            }
        }

        return res + 1;
    }
};