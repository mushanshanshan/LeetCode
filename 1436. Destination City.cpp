class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> out;

        for (auto &p: paths) {
            out.insert(p[0]);
        }

        for (auto &p: paths) {
            if (!out.contains(p[1])) return p[1];
        }

        return "";
    }
};