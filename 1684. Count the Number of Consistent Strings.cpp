class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> sc;
        int res = 0;

        for (char c: allowed) sc.insert(c);
        for (auto &w: words) {
            bool skip = false;
            for (char c: w) if (!sc.contains(c)) skip = true;
            if (skip) continue;
            res++;
        }

        return res;
    }
};